#include <iostream>

#include <winsock2.h>

#include <conio.h>

#include <stdio.h>

#include <tchar.h>
#include <stdio.h>
#include <windows.h>

#pragma comment(lib, "Ws2_32.lib")

void set_address(char* , size_t , struct sockaddr_in* , char* );
void server(SOCKET , struct sockaddr_in*  );

struct M{

    int z=5;
}Z;

int main()
{

WSADATA wsa;
if (WSAStartup (0x0202, &wsa) != 0)

    {

        std::cout << "Initialization failed";

        _getch();

        return 0;

    }

    char IP[16];
    size_t port;
    SOCKET s;
    SOCKET s1;
    struct sockaddr_in local;
    struct sockaddr_in peer;
    const int on = 1;
    int lenpeer;

    std::cout<<"Enter IP of server"<<std::endl;
    std::cin>>IP;
    std::cout<<"Enter Port of server"<<std::endl;
    std::cin>>port;



    set_address( IP, port, &local, "tcp" );
     s = socket( AF_INET, SOCK_STREAM, 0 );//создаем сокет
    if(s == INVALID_SOCKET)
        std::cout<< WSAGetLastError();
    if ( bind( s, ( struct sockaddr * ) &local,
			 sizeof( local ) ) == SOCKET_ERROR )
        std::cout<< "fail in bind "<<WSAGetLastError();
    if ( listen( s, 20 ) )
        std::cout<< "fail in listen "<<WSAGetLastError();


        lenpeer = sizeof(peer);
        s1 = accept( s, ( struct sockaddr * )&peer, &lenpeer );
        if(s1 == INVALID_SOCKET)
            std::cout<< WSAGetLastError();
        server( s1, &peer );
       // shutdown(s1, 2);
        closesocket(s1);

}

void set_address(char *ip, size_t port, struct sockaddr_in* sap, char* protocol)
{

    //bzero(sap,sizeof(sap));
    sap->sin_family = AF_INET;
    sap->sin_addr.s_addr = inet_addr(ip);
    sap->sin_port = htons( port );


}

void server(SOCKET s, struct sockaddr_in* ppeer )
{

    do
    {
        std::cout<<"\t1 - Send\n"
                <<"\t2 - Receive\n"
                <<"\t3 - Work with value\n"
                <<"\t4 - Sum of two matrix\n"
                <<"\t5 - See Struct"<<std::endl;

        int choose;
        std::cin>>choose;
        switch(choose)
        {
        case 1:
            {
                std::cout<<"Write message:";
                char msg[120];
                std::cin>>msg;
                if(send(s, msg, sizeof(msg), 0) == SOCKET_ERROR)
                    std::cout<< WSAGetLastError();
                break;
            }
        case 2:
            {
                int rc;
                char buf[120];
                 rc = recv(s, buf, sizeof(buf), 0);
                 std::cout<<"Message from client: "<<buf<<std::endl;
                 break;
            }
        case 3:
            {
                int rc;
                int value;
                int value2;
                int sum;
                rc = recv(s, (char*)&value, sizeof(value), 0);
                rc = recv(s, (char*)&value2, sizeof(value2), 0);
                value = ntohl(value);
                value2 = ntohl(value2);
                sum = value+value2;
                sum = htonl(sum);
                send(s, (char*)&sum, sizeof(sum), 0);
                break;
            }
        case 4:
            {
               int rc;

               int massiv[2][2];
                int massiv1[2][2];
                 int massivSum[2][2];
                for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        {

                            rc=recv(s, (char*)&massiv[i][j], sizeof(massiv[i][j]), 0);
                            massiv[i][j] = ntohl(massiv[i][j]);
                        }
                 for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        {
                           rc=recv(s, (char*)&massiv1[i][j], sizeof(massiv1[i][j]), 0);
                            massiv1[i][j] = ntohl(massiv1[i][j]);
                        }

                for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                    {
                        massivSum[i][j] =  massiv[i][j] +  massiv1[i][j];
                    }

                    for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        {
                            massivSum[i][j] = htonl(massivSum[i][j]);
                            send(s, (char*)&massivSum[i][j], sizeof(massivSum[i][j]), 0);
                        }

            }
        case 5:
            {


                struct MyStruct{
                    int value ;
                    double num ;
                    char str[20];
               }MM;


                int rc;
                char str[20];
                int value;
                double num;
                rc=recv(s, (char*)&str, sizeof(str), 0);
                std::cout<<str<<"  ";
                rc=recv(s, (char*)&value, sizeof(value), 0);
                            value = ntohl(value);
                std::cout<<value<<"  ";
                rc=recv(s, (char*)&num, sizeof(num), 0);
                            num = ntohl(num);
                std::cout<<num<<"  ";

                rc=recv(s, (char*)&MM, sizeof(MM), 0);
                std::cout<<MM.num;
            }

        }
    }while(1);
}
