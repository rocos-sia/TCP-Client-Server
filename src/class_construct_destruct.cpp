/**
 * @file class_construct_destruct.cpp
 * @author your name (you@domain.com)
 * @brief 结论： 类在析构时，会自动调用成员变量的析构
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <memory>  // for std::shared_ptr
#include <unistd.h>

class Resource
{
public:
    Resource( ) { std::cout << "Resource construct:" << std::endl; }
    ~Resource( ) { std::cout << "Resource destroyed\n"; }
    std::string str;
};

class father
{
public:
    father( ) { std::cout << "father construct:" << std::endl; };
    ~father( ) { std::cout << "father destruct:" << std::endl; }
    Resource res;
};

int main( )
{
    father xxx;
    sleep( 2 );
    return 0;
}