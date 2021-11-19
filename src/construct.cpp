#include <algorithm>
#include <iostream>
#include <vector>
/**
 * @brief 类的几种构造函数的区分
 * 
 */

using namespace std;

class test
{
private:
    int var;

public:
    test() { cout << "call test()" << endl; }
    test(const test& var) { cout << "call test(const test &)" << endl; }
    test(const int i) : var(i) { cout << "call test(cosnt int )" << endl; }
};

int main()
{
    cout << "test demo start1---" << endl;
    cout << 1 << endl;
    test var1;
    cout << 2 << endl;
    test var2(var1);
    cout << 3 << endl;
    test var3 = var2;
    cout << 4 << endl;
    test var4(2);
    cout << 5 << endl;
    test var5 = 4;
    cout << "end" << endl;
    /* 得出结论：在对象初始化时，（）的作用等于 = */

    cout << "test demo start--2" << endl;
    cout << 6 << endl;
    test var6{};
    cout << 7 << endl;
    test var7{var6};
    cout << 8 << endl;
    test var8 = var7;
    cout << 9 << endl;
    test var9{2};
    cout << 10 << endl;
    test var10 = 4;
    cout << "end" << endl;
    /* 得出结论：在对象初始化时，{} 是统一的初始化方法}*/
}
