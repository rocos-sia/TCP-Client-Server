/**
 * @file boost_thread_interrupt.cpp
 * @author your name (you@domain.com)
 * @brief 线程安全退出的方法：用interp()抛出异常，然后joint等待线程回收
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void thread_func(int a)
{
    //发起线程中断时，会抛出异常
    try {
        while (1) {
            std::cout << a << std::endl;
            boost::this_thread::sleep_for(boost::chrono::seconds(1));
        }
    }
    catch(boost::thread_interrupted const&)
    {
        std::cout << "thread " << a;
    }
}

int main()
{
    std::vector<std::shared_ptr<boost::thread>> threads;

    std::cout << "main starts" << std::endl;

    for (int i = 0; i < 3; i++) {
        threads.push_back(std::make_shared<boost::thread>(thread_func, i));
        boost::this_thread::sleep_for(boost::chrono::microseconds(500));
    }

    boost::this_thread::sleep_for(boost::chrono::seconds(3));
    boost::posix_time::time_duration timeout = boost::posix_time::seconds(3);

    for (auto t : threads) {
        t->interrupt();//发起线程中断
        if (t->timed_join(timeout))//等待3秒回收线程
        {
            std::cout << " finish correctly" << std::endl;
        }
        else
        {
            std::cout << "thread not finished" << std::endl;
        }
    }

    std::cout << "main ends" << std::endl;
    return 0;
}