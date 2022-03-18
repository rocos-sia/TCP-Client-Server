/**
 * @file test.cpp
 * @author your name (you@domain.com)
 * @brief 结论：调用reset()会使引用计数减1；调用reset（new xxx())重新赋值时，智能指针首先是生成新对象，
 * 然后将就对象的引用计数减1（当然，如果发现引用计数为0时，则析构旧对象），然后将新对象的指针交给智能指针保管,新对象引用+1。
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <errno.h>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <boost/thread.hpp>

#define RED "\033[31m" /* Red */

#define GREEN "\033[32m" /* Green */

#define YELLOW "\033[33m" /* Yellow */


class base
{
    public:
    base( std::string s) : str(s){ std::cout << "base construct" << std::endl; }
    base (const base & copy){ str = copy.str;    std::cout << "base copy construct" << std::endl;  }
    ~base( ) { std::cout << "base destruct" << std::endl; }
    std::string str;
};



#define WHITE "\033[37m" /* White */


int main( int argc, char** argv )
{
using namespace boost;
//** 实验1 **//
std::cout<< RED;
shared_ptr < base> p1 =nullptr;//先创建一个对象，然后shared_ptr 指向它
p1.reset( new base{"1234"});
std::cout<<"P1 = "<<p1 <<std::endl;//因为指向对象已经销毁，所以P1的值为0
std::cout<<"P1.str= "<<p1->str <<std::endl;//因为指向对象已经销毁，所以P1的值为0
std::cout<<"----------------------- " <<std::endl;

//两次析构
return 0;
}
