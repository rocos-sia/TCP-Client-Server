/**
 * @file TCP_client.cpp
 * @author JC (193355797@qq.com)
 * @brief 这是个TCP客户端，效果是不断向服务器发送 "i am client at xxx"
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXLINE 4096

int main( int argc, char** argv )
{
    int sockfd, n;
    char buff_res[ 4096 ];
    std::string sendline;
    struct sockaddr_in servaddr;
    int count = 0;

    memset( &servaddr, 0, sizeof( servaddr ) );  //清空
    servaddr.sin_family      = AF_INET;
    servaddr.sin_port        = htons( 6000 );
    servaddr.sin_addr.s_addr = inet_addr( "127.0.0.1" );  //服务器IP地址

    if ( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 )
    {
        printf( "create socket error: %s(errno: %d)\n", strerror( errno ), errno );
        return 0;
    }

    if ( connect( sockfd, ( struct sockaddr* )&servaddr, sizeof( servaddr ) ) < 0 )
    {
        printf( "connect error: %s(errno: %d)\n", strerror( errno ), errno );
        return 0;
    }

    char recv_buf[ 1024 ];

    while ( 1 )
    {
        //** 发送消息 **//
        sendline = std::string( "i am client at " ) + std::to_string( count++ ) + std::string( "\n" );
        if ( send( sockfd, sendline.c_str( ), sendline.length( ), 0 ) < 0 )
        {
            printf( "send msg error: %s(errno: %d)\n", strerror( errno ), errno );
            return 0;
        }
        //**-------------------------------**//

        //**接受消息 **//
        int len = recv( sockfd, recv_buf, BUFSIZ, 0 );

        if ( len > 0 )
        {
            recv_buf[ len ] = '\0';
            std::cout << "Received=" << recv_buf << " ，Info Length=" << len << std::endl;
        }
        //**-------------------------------**//

        sleep( 1 );
    }

    close( sockfd );
    return 0;
}
