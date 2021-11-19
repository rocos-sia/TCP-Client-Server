#include <iostream>
#include <memory>  // for std::shared_ptr

/**
 * @brief 总结   多个std::shared_ptr可以管理同一个资源，当最后一个std::shared_ptr解除，资源释放。优点：提供一个独立的master来管理唯一资源，但可以同时有多个访问接口
        //总结  std::make_shared可以创建一个内存，并返回  std::shared_ptr，优点：避免了两个独立的share_ptr（两个maser）指向同一个资源
 * 
 */

class Resource
{
public:
    Resource(std::string str_in) : str(str_in) { std::cout << "Resource acquired ,received:" << str << "\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    std::string str;
};

int main()
{
    //** std::make_share 构造函数等效传递 **//
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("123");
    std::cout << "ptr1 . use_count" << ptr1.use_count() << std::endl;
    std::shared_ptr<Resource> ptr2(ptr1);
    std::cout << "ptr1 . use_count" << ptr1.use_count() << std::endl;
    std::shared_ptr<Resource> ptr3(ptr2);
    std::cout << "ptr1 . use_count" << ptr1.use_count() << std::endl;
    std::shared_ptr<Resource> ptr4(ptr1);
    std::cout << "ptr4 . use_count" << ptr4.use_count() << std::endl;
    std::cout << ptr1->str << std::endl;
    //总结 std::shared_ptr内部有一个共享控制块，所以 ptr4(ptr1) 或者ptr4(ptr2)都可以
    return 0;
}