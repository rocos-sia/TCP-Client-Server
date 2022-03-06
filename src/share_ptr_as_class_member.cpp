#include <iostream>
#include <memory>  // for std::shared_ptr
#include <unistd.h>

/**
 * @brief 总结   多个std::shared_ptr可以管理同一个资源，当最后一个std::shared_ptr解除，资源释放。优点：提供一个独立的master来管理唯一资源，但可以同时有多个访问接口
        //总结  std::make_shared可以创建一个内存，并返回  std::shared_ptr，优点：避免了两个独立的share_ptr（两个maser）指向同一个资源
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
    father( const std::shared_ptr< Resource > & ptr):ptr1(ptr) { std::cout << "father construct:" << std::endl; };
    ~father( ) { std::cout << "father destruct:" << std::endl; }
    std::shared_ptr< Resource > ptr1;

};

int main( )
{
    father xx(std::make_shared<Resource>());
    sleep( 2 );
    return 0;
}