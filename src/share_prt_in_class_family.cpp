/**
 * @file share_prt_in_class_family.cpp
 * @author your name (you@domain.com)
 * @brief  
 * 结论：如假设B、C类继承A，share_Prt<A> 先等于 share_Prt<B> ，在等于share_Prt<C>,
 * 此时在切换时，可以验证发现 B的智能指针拥有者由2变为1，C的智能指针由1变为2
 * 以及重要一点：父类的智能指针可以等于其子类的智能指针
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <memory>

class base
{
    public:
    base( ) { std::cout << "base construct" << std::endl; }
    ~base( ) { std::cout << "base destruct" << std::endl; }
};

class inherit_1:public base
{
    public:
    inherit_1( ) { std::cout << "inherit_1 construct" << std::endl; }
    ~inherit_1( ) { std::cout << "inherit_1 destruct" << std::endl; }
};

class inherit_2:public base
{
    public:
    inherit_2( ) { std::cout << "inherit_2 construct" << std::endl; }
    ~inherit_2( ) { std::cout << "inherit_2 destruct" << std::endl; }
};


int main( int argc, char** argv )
{
    using namespace std;
    std::shared_ptr< base > p_base;
    std::shared_ptr< inherit_1 > p_inherit_1 = std::make_shared< inherit_1 >( );
    std::shared_ptr< inherit_2 > p_inherit_2 = std::make_shared< inherit_2 >( );

    cout << "-----------------------------------------------" << endl;
    cout << "the count pointting to inherit_1  = " << p_inherit_1.use_count( ) << endl;
    cout << "the count pointting to inherit_2  = " << p_inherit_2.use_count( ) << endl;
    cout << "-----------------------------------------------" << endl;
    p_base = p_inherit_1;
    cout << "the count pointting to inherit_1  = " << p_inherit_1.use_count( ) << endl;
    cout << "the count pointting to inherit_2  = " << p_inherit_2.use_count( ) << endl;
    cout << "-----------------------------------------------" << endl;
    p_base = p_inherit_2;
    cout << "the count pointting to inherit_1  = " << p_inherit_1.use_count( ) << endl;
    cout << "the count pointting to inherit_2  = " << p_inherit_2.use_count( ) << endl;
    cout << "-----------------------------------------------" << endl;

    return 0;
}
