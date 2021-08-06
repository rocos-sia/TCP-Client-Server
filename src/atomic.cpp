#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <sys/syscall.h>
#include <string.h>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

std::atomic<bool> readyFlag(false);
char *data;

void write_thread(const int &count)
{
    for (int i = 0; i < count; i++)
    {
        while (readyFlag.load())
            std::this_thread::yield();
        sprintf(data, "my share memary data is %d", i);
        readyFlag.store(true);
    }
}

void read_thread(const int &count)
{
    for (int i = 0; i < count; i++)
    {
        while (!readyFlag.load())
            std::this_thread::yield();
        puts(data);
        readyFlag.store(false);
    }
}

int main(int argc, char const *argv[])
{
    pid_t pid = syscall(SYS_gettid);

    char *buff = new char[100];
    memset(buff, 0, 100);
    sprintf(buff, "chrt  -a   -r   --pid  %d   %d", 99, pid);
    int var = system(buff);
    if (var == -1 || var == 127)
    {
        std::cerr << "system call failed";
        return -1;
    };
    delete[] buff;

    high_resolution_clock::time_point beginTime = high_resolution_clock::now();

    data = (char *)mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!data)
    {
        printf("mmap failed\n");
        munmap(data, 1024);
    }

    std::thread th_write(write_thread, 20);
    std::thread th_read(read_thread, 20);

    th_write.join();
    th_read.join();

    high_resolution_clock::time_point endTime = high_resolution_clock::now();
    auto timeInterval = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime);
    cout << "Running Time：" << (double)timeInterval.count() / 1000.0 << "us" << endl;

    return 0;
}