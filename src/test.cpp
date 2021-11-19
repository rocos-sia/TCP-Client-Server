#include <cassert>  // for assert()
#include <cmath>    // for std::sqrt
#include <iostream>
#include <vector>

#include <fstream>
/**
 * @brief 仅用于测试
 * 
 */
int main( int argc, char const* argv[] )
{
    try
    {
        //** 打开文件 **//
        std::ofstream of( "../link_waypoints.POINT", std::ios::out | std::ios::trunc );
        int           count = 0;

        //**  计算路点 **//

        of << "\n"
           << "P[" + std::to_string( count++ ) + "]\n"
           << "x                              = " + std::to_string( 1 ) + "\n"
           << "y                              = " + std::to_string( 2 ) + "\n"
           << "z                              = " + std::to_string( 3 ) + "\n"
           << "k                              = " + std::to_string( 4 ) + "\n"
           << "p                              = " + std::to_string( 5 ) + "\n"
           << "s                              = " + std::to_string( 6 ) + "\n";

        of << "\n"
           << "P[" + std::to_string( count++ ) + "]\n"
           << "x                              = " + std::to_string( 1 ) + "\n"
           << "y                              = " + std::to_string( 2 ) + "\n"
           << "z                              = " + std::to_string( 3 ) + "\n"
           << "k                              = " + std::to_string( 4 ) + "\n"
           << "p                              = " + std::to_string( 5 ) + "\n"
           << "s                              = " + std::to_string( 6 ) + "\n";

        of << "\n"
           << "P[" + std::to_string( count++ ) + "]\n"
           << "x                              = " + std::to_string( 1 ) + "\n"
           << "y                              = " + std::to_string( 2 ) + "\n"
           << "z                              = " + std::to_string( 3 ) + "\n"
           << "k                              = " + std::to_string( 4 ) + "\n"
           << "p                              = " + std::to_string( 5 ) + "\n"
           << "s                              = " + std::to_string( 6 ) + "\n";

        of << "\n";
        of << "\n";
        of.close( );
    }
    catch ( std::exception& e )
    {
        std::cout << "error happened:" << e.what( ) << std::endl;
    }

    return 0;
}
