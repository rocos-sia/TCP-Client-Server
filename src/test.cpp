#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096

int main( int argc, char** argv )
{
    int sockfd, n;
    char buff_res[ 4096 ], sendline[ 4096 ];
    struct sockaddr_in servaddr;

    if ( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 )
    {
        printf( "create socket error: %s(errno: %d)\n", strerror( errno ), errno );
        return 0;
    }

    memset( &servaddr, 0, sizeof( servaddr ) );  //清空
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons( 5000 );
    if ( inet_pton( AF_INET, "127.0.0.1", &servaddr.sin_addr ) <= 0 )
    {
        printf( "inet_pton error for %s\n", argv[ 1 ] );
        return 0;
    }

    if ( connect( sockfd, ( struct sockaddr* )&servaddr, sizeof( servaddr ) ) < 0 )
    {
        printf( "connect error: %s(errno: %d)\n", strerror( errno ), errno );
        return 0;
    }

    printf( "send msg to server: \n" );
    while ( 1 )
    {
        // 这里改成咱们的code给sendline
        fgets( sendline, 4096, stdin );
        if ( send( sockfd, sendline, strlen( sendline ), 0 ) < 0 )
        {
            printf( "send msg error: %s(errno: %d)\n", strerror( errno ), errno );
            return 0;
        }  // 发送信息

        n             = recv( sockfd, buff_res, MAXLINE, 0 );  //接收信息
        buff_res[ n ] = '\0';
        printf( "recv msg from client: %s\n", buff_res );
    }
    close( sockfd );
    return 0;
}
