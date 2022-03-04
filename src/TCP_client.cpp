/**
 * @file TCP_client.cpp
 * @author JC (you@domain.com)
 * @brief 这是个TCP客户端，效果是不断向服务器发送count值
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <iostream>

#define MAXLINE 4096

int main( int argc, char** argv )
{
    int sockfd, n;
    char buff_res[ 4096 ];
    std::string sendline;
    struct sockaddr_in servaddr;
    int count = 0;

    memset( &servaddr, 0, sizeof( servaddr ) );  //清空
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons( 6000 );

    if ( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 )
    {
        printf( "create socket error: %s(errno: %d)\n", strerror( errno ), errno );
        return 0;
    }

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

    while ( 1 )
    {
        sendline = std::to_string( count++ ) + std::string( "\n" );
        if ( send( sockfd, sendline.c_str( ), sendline.length( ), 0 ) < 0 )
        {
            printf( "send msg error: %s(errno: %d)\n", strerror( errno ), errno );
            return 0;
        }  // 发送信息
        std::cout << sendline << std::endl;
        sleep( 1 );
    }
    close( sockfd );
    return 0;
}
