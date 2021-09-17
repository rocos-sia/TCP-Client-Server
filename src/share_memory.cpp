#include <condition_variable>
#include <fcntl.h>
#include <iostream>
#include <mutex>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

/**
 * @brief 总结 实现线程之间的共享内存读写
 * 
 */

std::mutex mut;
bool ready = false;
std::condition_variable cond;
char *data;

void write_thread(const int &count)
{
    for (int i = 0; i < count; i++)
    {
        std::unique_lock<std::mutex> mtx_lcok_write(mut);
        sprintf(data, "my share memary data is %d", i);
        mtx_lcok_write.unlock();
        ready = true;
        cond.notify_all();
        std::this_thread::sleep_for(std::chrono::microseconds(2000));
    }
    ready = false;
    cond.notify_all();
}

void read_thread(const int &count)
{
    for (int i = 0; i < count; i++)
    {
        std::unique_lock<std::mutex> mtx_lock_read(mut);
        while (!ready)
            cond.wait(mtx_lock_read);
        puts(data);
        ready = false;
    }
}

int main(int argc, char const *argv[])
{
    clock_t startTime = clock();
    data = (char *)mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!data)
    {
        printf("mmap failed\n");
        munmap(data, 1024);
    }
    std::cout << "this thread id is " << getpid() << std::endl;
    std::thread th_read(read_thread, 10);
    std::thread th_write(write_thread, 10);

    th_write.join();
    th_read.join();
    clock_t endTime = clock();
    std::cout << "整个程序用时：" << 1000 * double(endTime - startTime) / CLOCKS_PER_SEC << "ms" << std::endl;
    return 0;
}