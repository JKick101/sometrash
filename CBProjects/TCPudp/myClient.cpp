#include <iostream>

#include <winsock2.h>

#include <conio.h>

#include <stdio.h>

#include <tchar.h>
#include <stdio.h>
#include <windows.h>

#pragma comment(lib, "Ws2_32.lib")

void client(SOCKET , struct sockaddr_in*  );

int main()
{

    WSADATA wsa;
if (WSAStartup (0x0202, &wsa) != 0)

    {

        std::cout << "Initialization failed";

        _getch();

        return 0;

    }

    SOCKET s;
    std::cout<<"Enter IP:";
    char IP[16];
    std::cin>>IP;
    std::cout<<"Enter port:";
    size_t port;
    std::cin>>port;

    struct sockaddr_in anAddr;
	anAddr.sin_family = AF_INET;
	anAddr.sin_port = htons(port);
	anAddr.sin_addr.s_addr = inet_addr(IP);
     s = socket( AF_INET, SOCK_STREAM, 0 );
     if(s == INVALID_SOCKET)
        std::cout<< WSAGetLastError();
	connect(s, (struct sockaddr *)&anAddr, sizeof(anAddr));

    client(s,&anAddr);
    //shutdown(s, 2);
        closesocket(s);
     _getch();



}

void client(SOCKET s, struct sockaddr_in* ppeer )
{

    do
    {
        std::cout<<"\t1 - Send\n"
                <<"\t2 - Receive\n"
                <<"\t3 - Enter value for sum\n"
                <<"\t4 - Sum of two matrix\n"
                <<"\t5 - Send the structure"<<std::endl;

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
                 std::cout<<"Message from client: "<<buf;
                 break;
            }
        case 3:
            {
                int value;
                int value2;
                int sum;
                std::cout<<"Enter two value to sum:";
                std::cin>>value>>value2;
                value = htonl(value);
                value2 = htonl(value2);
                send(s, (char*)&value, sizeof(value), 0);
                send(s, (char*)&value2, sizeof(value2), 0);
                int rc;
                rc=recv(s, (char*)&sum, sizeof(sum), 0);
                sum=ntohl(sum);
                std::cout<<"Sum is:"<<sum;
                break;
            }
        case 4:
            {
                int massiv[2][2] = {{2,2},
                                    {3,3}};
                int massiv1[2][2] = {{5,5},
                                    {10,7}};
                 int massivSum[2][2];
                 int rc;

                for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        {
                            massiv[i][j] = htonl(massiv[i][j]);
                            send(s, (char*)&massiv[i][j], sizeof(massiv[i][j]), 0);
                        }
                 for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        {
                            massiv1[i][j] = htonl(massiv1[i][j]);
                            send(s, (char*)&massiv1[i][j], sizeof(massiv1[i][j]), 0);
                        }

                for (int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        {
                           rc=recv(s, (char*)&massivSum[i][j], sizeof(massivSum[i][j]), 0);
                            massivSum[i][j] = ntohl(massivSum[i][j]);
                            std::cout<<massivSum[i][j]<<" ";
                        }
            }

        case 5:
            {
               struct MyStruct{
                    int value = 10;
                    double num = 19.9;
                    char str[20] = "abcdefghf";
               }MS;

               int value;
               double num;
               send(s, MS.str, sizeof(MS.str), 0);
               value=htonl(MS.value);
               send(s, (char*)&value, sizeof(value), 0);
               num=htonl(MS.num);
               send(s, (char*)&num, sizeof(num), 0);

               send(s, (char*)&MS, sizeof(MS), 0);
            }


        }
    }while(1);
}
