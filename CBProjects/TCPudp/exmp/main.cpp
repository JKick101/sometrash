#include <iostream>

#include <winsock2.h>

#include <conio.h>

#include <stdio.h>

#include <tchar.h>

//#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int _tmain(int argc, _TCHAR* argv[])

{

// ������ ����������. ������� � ����� �������� - ��� ���������� (�� �����������)

WSADATA wsa;

if (WSAStartup (0x0202, &wsa) != 0)

{

cout << "\nshit happens =(\n";

_getch();

return 0;

}

// �������� ������

int channel = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(channel == INVALID_SOCKET)
        std::cout<< WSAGetLastError();
if (channel == -1)

{

cout << "Creation socket error: " << GetLastError() << endl;

return 0;

}

int val = 1;

setsockopt(channel, SOL_SOCKET, SO_REUSEADDR, (const char*)&val, sizeof(val));

setsockopt(channel, SOL_SOCKET, SO_BROADCAST, (const char*)&val, sizeof(val));

// ���������� ��������� address

sockaddr_in address;

//sin_family �������� ����� ��, ��� � ������

address.sin_family = AF_INET;


int port;

cout << "Enter port: \n";

cin >> port;

// ������� ����

address.sin_port = htons(port);

char addr[100];

cout << "\nEnter address: \n";

cin >> addr;

// � ����������� ������������ ��������. � ������� ��������� ���������� �������������� �� ������

address.sin_addr.S_un.S_addr = inet_addr(addr);


// �������� ������

int bind_result = bind(channel, (const sockaddr*)&address, sizeof(address));

if (bind_result == -1)

{

cout << "Binding error code: " << WSAGetLastError() << endl;

return 0;

}

int destPort = 0;

int number = 0;

int source_size = 0;

char send_buff[512];

char receive_buff[512];

int send_result = 0;

int receiv_result = 0;

bool exit = false;

sockaddr send_address;

while (!exit)

{

cout << "\n***MENU***\n"

<< "1 - Send\n"

<< "2 - Receive\n"

<< "3 - Close Socket\n";

cin >> number;

switch (number)

{

case 1:

sockaddr_in destination;

destination.sin_family = AF_INET;


cout << "Enter message:\n";

cin >> send_buff;


cout << "Enter receiver port:\n";

cin >> destPort;

destination.sin_port = htons(destPort);


char destAddr[100];

cout << "Enter receiver address:\n";

cin >> destAddr;

destination.sin_addr.S_un.S_addr = inet_addr(destAddr);


send_result = sendto(channel, (const char*)send_buff, sizeof(send_buff), 0, (const sockaddr*)&destination, sizeof(destination));

if (send_result == -1)

{

cout << "Error code: " << WSAGetLastError() <<endl;

}

break;


case 2:

// �������� "����������" ��� �������� ������� ������

source_size = sizeof(send_address);

// ����� ��������� � �������� - ����� ������ ����������� � ������ ������ �����������

receiv_result = recvfrom(channel, receive_buff, sizeof(receive_buff), 0, &send_address, &source_size);


if (receiv_result == -1)

{

cout << "Error code: " << WSAGetLastError() <<endl;

break;

}


cout << "Message is: " << receive_buff << endl;

cout << "Sender address is: " << inet_ntoa(address.sin_addr)<< endl;

cout << "Sender port is: " << (unsigned)ntohs(address.sin_port)<<endl;

break;

case 3:

closesocket(channel);

break;

default:

break;

}

}

_getch();

return 0; }
