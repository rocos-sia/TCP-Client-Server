#include <atomic>   // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <iostream> // std::cout
#include <thread>   // std::thread, std::this_thread::yield
#include <vector>   // std::vector
/**
 * @brief 结论 atomic 只保证操作原子性，不保证顺序
 * 
 * 
 */

std::atomic<bool> ready(false);             // 由 false 初始化一个 std::atomic<bool> 类型的原子变量
std::atomic_flag winner = ATOMIC_FLAG_INIT; //atomic 自带的bool类型，特点未设置返回false并且设置、设置过返回true

void do_count1m(int id)
{
    while (!ready)
    {
        // std::this_thread::yield();
    } // 等待 ready 变为 true.

    // for (volatile int i = 0; i < 1000000; ++i)
    // {
    // } // 计数

    if (!winner.test_and_set())
    {
        std::cout << "thread #" << id << " won!\n";
    }
}

int main()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i = 1; i <= 8; ++i)
        threads.push_back(std::thread(do_count1m, i));
    ready = true;

    for (auto &th : threads)
        th.join();
    return 0;
}