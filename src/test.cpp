#include <arpa/inet.h>
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

class base
{
    public:
    base( std::string s) : str(s){ std::cout << "base construct" << std::endl; }
    base (const base & copy){ str = copy.str;    std::cout << "base copy construct" << std::endl;  }
    ~base( ) { std::cout << "base destruct" << std::endl; }
    std::string str;
};

class inherit_1 
{
    public:
    inherit_1(   base  res ) { std::cout << "inherit_1 construct---" << res.str <<std::endl;   ;sleep(5);  }
    ~inherit_1( ) { std::cout << "inherit_1 destruct" << std::endl; }
};




int main( int argc, char** argv )
{
using namespace std;

inherit_1 res {base{"123"}};


return 0;
}
