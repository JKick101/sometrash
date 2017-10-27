
 #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <stdarg.h>
 #include <string.h>
  #include <errno.h>
//  #include <netdb.h>
 #include <fcntl.h>
  #include <sys/time.h>
//   #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
 #include "skel.h"





  int main( int argc, char **argv )
  {
    struct sockaddr_in *peer;
 		SOCKET s;
 		INIT();
 		set_address( argv[ 1 ], argv[ 2 ], &peer, "tcp" );
 		s = socket( AF_INET, SOCK_STREAM, 0 );
 		if ( !isvalidsock( s ) )
 				error( 1, errno, "������ ������ socket" );
		if ( connect( s, ( struct sockaddr * )&peer,
			 	sizeof( peer ) ) )
				error( 1, errno, "������ ������ connect" );
		client( s, &peer );
		EXIT( 0 );
  }


 SOCKET tcp_client( char *hname, char *sname )
 {
 		struct sockaddr_in peer;
 		SOCKET s;
 		set_address( hname, sname, &peer, "tcp" );
 		s = socket( AF_INET, SOCK_STREAM, 0 );
 		if ( !isvalidsock( s ) )
 			error( 1, errno, "������ ������ socket" );
    if ( connect( s, ( struct sockaddr * )&peer,
			 sizeof( peer ) ) )
			error( 1, errno, "������ ������ connect" );
		return s;
 }

//For tests
static void client (SOCKET s, struct sockaddr_in &peerp )
{
    int rc;
    char buf[120];

    for(;;)
    {
        rc=recv(s, buf, sizeof(buf), 0);

/*������� ������ ��� ������ ������ �� ������.

int recv(int s, char * buf, int len, int flags);

������ �������� - �����-����������, �� �������� �������� ������. ������ � ������ ��������� - ��������������,
����� � ����� ������ ��� ������ �������� ������. ��������� �������� - ��� ���������� ������� ������,
����������� �������� ������. ���� �������� flags ����� ����, �� ��������� ������ ��������� �� ������.
���� �������� flags ���� MSG_PEEK, �� ������ �� ��������� � ����� ���� ������� ���������� ������� ( ��� �������� ) recv.

������� ���������� ����� ��������� ������ ��� -1 � ������ ������. ������� ��������, ��� ������� �������� �� �������� �������.
��� ������������� �� ���������� ���������� � ����� ���������-����������� ������.
*/

    if ( rc<=0 )
        break;
    write(1, buf , rc );

    }
}


//////////////////////������,���������� ������ ���������� �����////////////////////////////////
 int main( int argc, char **argv )
  {
 		SOCKET s;
 		int n;
 		struct
 		{
 			u_int32_t reclen;//uint32_t
 		char buf[ 128 ];
		} packet;
		INIT();
		s = tcp_client( argv[ 1 ], argv[ 2 ] );
		/*
            char * fgets( char * string, int num, FILE * filestream );
            ������� fgets ��������� ������� �� ������ � ��������� �� � ���� ������ � �������� string
            �� ��� ��� ���� �� �������� ����� ������ ��� ���� �� ����� ��������� ����� �����.

    ���������:
    string
    ��������� �� ������ ���� char, � ������� ����������� ��������� �������.
    num
    ������������ ���������� �������� ��� ������, ������� ������� ������.
    filestream
    ��������� �� ������ ���� FILE, ������� �������������� �����, �� �������� ����������� �������.

    ��� ������ �� ������������ �����, stdin ����� ���� ����������� � �������� ����� ���������.

    � ������ ������, ������� ���������� ��������� �� string. ���� ����� ����� ��� ��������� � �� ���� ������ �� ��� ��������,
    ���������� string �������� ����������� � ������������ ������� ���������. ���� ���������� ������, ������������ ������� ���������.
    � ������ ������, ������� ���������� ��������� �� string. ���� ����� ����� ��� ��������� � �� ���� ������ �� ��� ��������,
    ���������� string �������� ����������� � ������������ ������� ���������. ���� ���������� ������, ������������ ������� ���������.


		*/
		while ( fgets( packet.buf, sizeof( packet.buf ), stdin )//������� ��� ������ � ������ ����� � �����
			!= NULL )
		{
			n = strlen( packet.buf );// ��������� ������ ������ � �������
			packet.reclen = htonl( n );//�������� ���� ������ � ����������(� ������� �������)
			if ( send( s, ( char * )&packet,
				 n + sizeof( packet.reclen ), 0 ) < 0 )//���������� ����� �������
				error( 1, errno, "������ ������ send" );
		}
		EXIT( 0 );
 }
