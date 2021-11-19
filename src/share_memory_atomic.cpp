
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
/**
 * @brief 总结 使用atomic变量实现共享内存的互斥读写
 * 
 */
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
std::atomic< bool > readyFlag( false );
char*               data_ptr;
void                write_thread( const int& count )
{
    for ( int i = 0; i < count; i++ )
    {
        while ( readyFlag.load( ) )
            std::this_thread::yield( );
        sprintf( data_ptr, "my share memary data_ptr is %d", i );
        readyFlag.store( true );
    }
}
void read_thread( const int& count )
{
    for ( int i = 0; i < count; i++ )
    {
        while ( !readyFlag.load( ) )
            std::this_thread::yield( );
        puts( data_ptr );
        readyFlag.store( false );
    }
}
int main( int argc, char const* argv[] )
{
    pid_t pid  = syscall( SYS_gettid );
    char* buff = new char[ 100 ];
    memset( buff, 0, 100 );
    sprintf( buff, "chrt  -a   -r   --pid  %d   %d", 99, pid );
    int var = system( buff );
    if ( var == -1 || var == 127 )
    {
        std::cerr << "system call failed";
        return -1;
    };

    delete[] buff;
    high_resolution_clock::time_point beginTime = high_resolution_clock::now( );
    data_ptr                                    = ( char* )mmap( NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0 );
    if ( !data_ptr )
    {
        printf( "mmap failed\n" );
        munmap( data_ptr, 1024 );
    }
    std::thread th_write( write_thread, 20 );
    std::thread th_read( read_thread, 20 );
    th_write.join( );
    th_read.join( );
    high_resolution_clock::time_point endTime      = high_resolution_clock::now( );
    auto                              timeInterval = std::chrono::duration_cast< std::chrono::nanoseconds >( endTime - beginTime );
    cout << "Running Time：" << ( double )timeInterval.count( ) / 1000.0 << "us" << endl;
    return 0;
}