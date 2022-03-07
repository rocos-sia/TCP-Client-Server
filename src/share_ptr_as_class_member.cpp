#include <iostream>
#include <memory>  
#include <unistd.h>

/**
 * @brief 总结  可以放心得在类里使用share_ptr；在类析构时会同时调用类成员的析构；
 * 
 */

class Resource
{
public:
    Resource( ) { std::cout << "Resource construct:" << std::endl; }
    ~Resource( ) { std::cout << "Resource destroyed\n"; }
  
};

class father
{
public:
    father( const std::shared_ptr< Resource > & p) : ptr(p) {  std::cout << "father construct:" <<std::endl; };
    ~father( ) { std::cout << "father destruct:" << std::endl; }
    std::shared_ptr< Resource > ptr;

};



int main( )
{

    father var( std::make_shared<Resource>());//通过这行，我发现编译器会自动把值传递优化成引用，不信可以father的构造函数改成值传递，然后
    //打印shared_ptr的user_count,可以发现一直为1
    return 0;
}