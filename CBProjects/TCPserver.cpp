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
 char *program_name;
 int main( int argc, char **argv )
 		{
		struct sockaddr_in local; //��������� ��� �����������
		struct sockaddr_in peer;
		/*struct sockaddr_in{
    short sin_family;  //��������� �������
    unsigned short sin_port;  //����(����� ������� ������� ����)
    struct in_addr sin_addr;  //�����
    char sin_zero[8];  //����������� ������
    };*/
		char *hname; //adress
		char *sname; //port
		int peerlen;
		SOCKET s1;
		SOCKET s;
		const int on = 1;
		INIT();
		if ( argc == 2 )// ���� ������ ������ ����� �����
		{
			hname = NULL;
			sname = argv[ 1 ];
		}
		else //���� ������ ����� ����� � �����
		{
			hname = argv[ 1 ];
			sname = argv[ 2 ];
		}

		set_address( hname, sname, &local, "tcp" );
		s = socket( AF_INET, SOCK_STREAM, 0 );//������� ����� � IPv4 � TCP

		if ( !isvalidsock( s ) ) //������ ����������� � skel.h (s>=0)
			error( 1, errno, "������ ������ socket" );

		if ( setsockopt( s, SOL_SOCKET, SO_REUSEADDR, &on,
			 sizeof( on ) ) )//������ ����� ������.���� ������ �� ���������, setsockopt ���������� ����.
			 //� ��������� ������ ������������ �������� SOCKET_ERROR, � ���������� ��� ������ ����� ��������,
			 // ������ WSAGetLastError.

/*			 int setsockopt(
  _In_       SOCKET s,
  _In_       int    level,
  _In_       int    optname,
  _In_ const char   *optval,
  _In_       int    optlen
);

S [in]
     ����������, ������� �������������� �����.

������� [�]
     �������, �� ������� ���������� ����� (��������, SOL_SOCKET).

Optname [in]
     ����� ������, ��� ������� ������ ���� ����������� �������� (��������, SO_BROADCAST).
      �������� optname ������ ���� ������ ������, ������������ �� ��������� ������, ��� ��������� �� ����������.

Optval [in]
     ��������� �� �����, � ������� ������� �������� ��� ����������� �����.

Optlen [in]
     ������ � ������ ������, �� ������� ��������� �������� optval.*/

			error( 1, errno, "������ ������ setsockopt" );

		if ( bind( s, ( struct sockaddr * ) &local,
			 sizeof( local ) ) )
			// int bind(int sockd, struct sockaddr *my_addr, int addrlen);
			//��������� ����� bind ������ ��� �������� ���������� ������ � ������������� ������� ������ �������������� ����.
/*
��� ������� ������������ �������� ��� ������������ ������ �����.
�� ���������� ������� bind (�.�. ������������ ������-���� �����,
��� �������� ������� �� ��������� ������ ) ����� ���������� ����������-��������.
			struct sockaddr {
                short sa_family;
                char sa_data[14];
                    };*/

			error( 1, errno, "������ ������ bind" );

		if ( listen( s, NLISTEN ) )
//������� listen ������������ ��������, ����� ������������� ��, ��� �� ������� ("�������") ������� ����� �� ������ ������.
//��� ����� ������� ������ ���������� ����� � ���� ������� ����� ����������.
            //������� listen �������� ����� � ���������, � ������� �� ������������ �������� ����������.
            //int listen(SOCKET s,int   backlog);
            //NLISTEN ������������ ����� ������� ��������� ����������.
			error( 1, errno, "������ ������ listen" );

		do
		{
			peerlen = sizeof( peer );
			s1 = accept( s, ( struct sockaddr * )&peer, &peerlen );
/* ��� ������� ������������ �������� ��� �������� ����� �� �����. ����� ������ ���� ��� ��������� � ������ ������ �������.
���� ������ ������������� ����� � ��������, �� ������� accept ���������� ����� �����-����������, ����� ������� �
���������� ������� ������� � ��������. ���� ��������������� ����� ������� � ��������, ������� accept ��������� ������
������� ����� � ������ ��������, � ����� ������������ ����� "�������������" �������� ��������������.

��������: int accept(int s, char * name, int* anamelen);

������ �������� ������� - �����-���������� ��� �������� ������ �� ��������.
������ �������� - ��������� �� ����� ������� (��������� sockaddr ) ��� ���������������� ������.
������ �������� - ��������� �� ����� ����� - ����� ��������� ������.
������ � ������ ��������� ����������� ���������������� ���������� � ������ ������������ ����� ������� � �������� �
��������� ������� ����� ����������, � ����� ������ �������� �� ��������. ���� ������ �� ������������ ������� �������,
� �������� ������� � �������� ���������� ����� ������ NULL-���������.
*/
			if ( !isvalidsock( s1 ) )
				error( 1, errno, "������ ������ accept" );
			server( s1, &peer );
			CLOSE( s1 );
		} while ( 1 );
		EXIT( 0 );
 }


 static void set_address( char *hname, char *sname,
 		struct sockaddr_in *sap, char *protocol )
  {
		struct servent *sp;//��������� �������������� ���������� ������������ ��� �������� ��� �������� ����� �
		// ������ ������ ��� ������� ����� ������.
 		struct hostent *hp;//��������� ����� ������������ ��������� ��� �������� ���������� � ������ �����,
 		// ��������, ��� �����, ����� IPv4 � �. �. ���������� ������� �� ������� �������� �������������� ��� ��������� ���
 		// ����������� �����-���� �� ����������. ����� ����, ������ ���� ����� ��������� ����� ���������� ��� ������� ������,
 		//� ������� ���������� ������ ���������� ����� ����������, ������� ��� �����, �� ������ ����� ������ ������� Windows Sockets API.
 /*
 typedef struct hostent {
  char FAR      *h_name;
  char FAR  FAR **h_aliases;
  short         h_addrtype;
  short         h_length;
  char FAR  FAR **h_addr_list;
} HOSTENT, *PHOSTENT, FAR *LPHOSTENT;

H_name
����������� ��� ����� (��). ���� ������������ DNS ��� ����������� ������� ����������,
�� ������ �������� ��� (FQDN) ���������� ������ ���������� �����. ���� ������������ ���� ��������� ������,
��� ������ ������ ����� ������ IPv4.

H_aliases
������ ������������ ���� � NULL-������.

h_addrtype
��� ������������� ������.

H_length
����� � ������ ������� ������.

H_addr_list
������ �������, ��������������� NULL ��� �����. ������ ������������ � ������� ������� ������.
������ h_addr ������������ ��� h_addr_list [0] ��� ������������� �� ������ ����������� ������������.
*/

 		char *endptr;
 		short port;
 		bzero( sap, sizeof( *sap ) );//������� bzero ��������� ������ n ����, ������� � ������ sap,
 		//�������� ����������. ������� ������ �� ����������.(������ �������� ���������)
 		sap->sin_family = AF_INET;//������������� ��������� �������

 		//���� ��� ������ IP
		if ( hname != NULL )
		{
			if ( !inet_aton( hname, &sap->sin_addr ) )//������� inet_aton() ��������� ���������� IP-�����
			//� �������� ������������� � ������� ������� ���� � ������� ��� �� ������ ��������
            //������ ����� ������ hname ����������� � ����� � ������ � ���� sin_addr ��������� sockaddr_in
			{
				//���� �������� ������ �� ���������� gethostbyname
				//������� gethostbyname ��������� ���������� � �����, ��������������� ����� ����� �� ���� ������ �����.
				hp = gethostbyname( hname );
				if ( hp == NULL )
					error( 1, 0, "����������� ����: %s\n", hname );//���� � ��� �� ������� ���������� ������ � �������
				sap->sin_addr = *( struct in_addr * )hp->h_addr;
/*
��������� in_addr ������������ ����� ����� ���������.

struct in_addr {
	union {
		struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { u_short s_w1,s_w2; } S_un_w;
		u_long S_addr;
	} S_un;
};

S_un_b - ����� � ������� ��� ������ u_chars.
S_un_w - ����� � ������� ��� ��� u_shorts.
S_addr - ����� � ������� u_long.

��� ���������� � ���� ������ ?? ���, ��������, ��� ����� ��������� ��� ��������:

in_addr adr2;
adr2.s_addr=inet_addr("124.23.45.67");
*/
			}
		}
		else
            //���� �� ���� �������� ������ �� ����� ����� ��������
			sap->sin_addr.s_addr = htonl( INADDR_ANY );//������� htonl ������������ ������� ������ �������� ����� �� ������� ����,
			//��������� �� ����������, � ������� ������� ����.
		port = strtol( sname, &endptr, 0 );//������� strtol ��������������� ������ � long int.
		//���������� ������ string, strtol �������������� � ���������� � ����� ����� ���� long int.
		//long int strtol( const char * string, char ** endptr, int basis );
                        // string
                        //��-������ ��� ���������� ��������������.

                        // endptr
                        // ������ �� ������ ���� char*, �������� ������� �������� ����� ���������� ������� � ������ string,
                        // ����� ����� ����������� ���������� �����. ���� ���� �������� �� ������������,
                        //�� ������ ���� ������� ����������.

                        // basis
                        // ��������� ������� ����������.

		if ( *endptr == '\0' )
			sap->sin_port = htons( port );//������� htons ������������ ������� ������ ��������� ����� �� ������� ����,
			// ��������� �� ����������, � ������� ������� ����.
		else
		{
			sp = getservbyname( sname, protocol );//������� getservbyname ��������� ��������� ����������,
			//��������������� ����� � ��������� ������.
			//���� ������ �� ���������, getservbyname ���������� ��������� �� ��������� servent.
			// � ��������� ������ �� ���������� ������� ���������, � ���������� ����� ������ ����� ��������,
			//������ WSAGetLastError.
			if ( sp == NULL )
				error( 1, 0, "����������� ������: %s\n", sname );
			sap->sin_port = sp->s_port;//����� �� ������������ ��������� ����� ����� � ������� �������
		}

   void error( int status, int err, char *fmt, ... )
 {
 		va_list ap;//���� ��� ������������ � �������� ��������� ��� ��������,
 		// ������������ � <cstdarg> ��� ���������� �������������� ���������� �������.
 		//va_list - ���� ��� ����������� ��� ���������� ��������� ���������� ��������� � ������������ ������ ap,
 		// ������������ ��� �������� ����������.
 		va_start( ap, fmt );
 		/*void va_start(  va_list arg_ptr,  prev_param );*/
 		//va_start ������ ��������� arg_ptr �� ������ �������������� ��������� � ������ ����������,
 		// ������� ������� �������. �������� arg_ptr ������ ����� ��� va_list.
 		//�������� prev_param � ��� ��� ������������� ���������, ������� ��������������� ������������ �������
 		//��������������� ��������� � ������ ����������. ���� �������� prev_param �������� � ������ ������������ ��������,
 		//��������� ������� �� ����������. va_start ���������� ������������ �� ������� ������������� va_arg.
 		//va_start - ���� ������ �������������� ���������� ��������� ap. ��� ���������� ������� �� ������� ������
 		//va_arg � va_end. � ������������ C va_start ������������� � ap ��������� ��������� �� ������ �� ������������
 		//������� ����������; � Standart C va_start �������� �������������� �������� - ��� ���������� �������������
 		//���������, - � ������������� ��������� ��������� � ap �� ������ �������� ������ ���������� �����.
 		fprintf( stderr, "%s: ", program_name );
 		vfprintf( stderr, fmt, ap );
 		va_end( ap );//����� ��������� ���� ���������� va_end ���������� ��������� �� NULL.
 		// va_end ������ ���������� ��� ������� ������ ����������, ������� ���������������� va_start ��� va_copy,
 		//�� ���������� �������� ��������.
 		//va_end - ��� ������� (��� ������) ���������� ������� ����� ���������� �������� va_arg ���� ����������.
 		//�� ��������� ��� ����������� ��������� ���������� ap � va_alist.
 		if ( err )//���� err �� ���� �� ��������� ��� ��� �������� errno
 			fprintf( stderr, ": %s (%d)\n", strerror( err ), err );
		if ( status )//���� ������ 0 �� ������������ �����,����� ���������� ���������� �������
			EXIT( status );
 }


 SOCKET tcp_server( char *hname, char *sname )
  {
 		struct sockaddr_in local;
 		SOCKET s;
 		const int on = 1;
 		set_address( hname, sname, &local, "tcp" );
 		s = socket( AF_INET, SOCK_STREAM, 0 );
 		if ( !isvalidsock( s ) )
 			error( 1, errno, "������ ������ socket" );
		if ( setsockopt( s, SOL_SOCKET, SO_REUSEADDR,
			( char * )&on, sizeof( on ) ) )
			error( 1, errno, "������ ������ setsockopt" );
		if ( bind( s, ( struct sockaddr * ) &local,
			 sizeof( local ) ) )
			error( 1, errno, "������ ������ bind" );
		if ( listen( s, NLISTEN ) )
			error( 1, errno, "������ ������ listen" );
		return s;
 }

int readn(SOCET fd, char *bp, size_t len) //�������, ����������� len ����
{

    int cnt;
    int rc;

    cnt = len;
    while ( cnt > 0) //���� �� ��������� ��� �����
    {
        rc = recv(fd, bp, cnt, 0);
        if ( rc < 0 )//� ������ ������
        {
            if ( errno == EINTR)//������������ ���������� recv ���� �� ������� ��������
                continue;
            return -1;
        }
        if ( rc == 0)//���� ������ �� ���� ��������
            return len - cnt;
        bp += rc;//��������� � ��������� ����� ������
        cnt -= rc;//�������� ����� ������ �� ������ ����������� ����
    }
    return len;
}

//���� ����� ��������� ������ ���������� �����
int readvrec(SOCKET fd, char *bp, size_t len)
{
    u_int32_t reclen;//uint32_t
    int rc;
    /*
        ����� ������ ����������� � ���������� reclen.������� readvrec ���������� 0
        ���� ����� ������ ����������� readn �� ����� ��������� �
        �������� ������, ��� -1 � ������ ������.
    */
    rc = readn(fd, (char*)&reclen, sizeof(u_int32_t));
    if ( rc != sizeof(u_int32_t))
        return rc < 0 ? -1 : 0;
    reclen = ntohl(reclen);//����������� ������ ������ � �������� �������
    if (reclen > len)//���� ����� ������ �������� ���
    {
        /*
         �� ������� ����� � ������ ��� ����������� ������-
         ��������� �� � ������� ��� ������.
        */
    while ( recelen > 0)//���� ��� �� ���������
        {
            /*
                ���������� ������ � ����� �������� �� len
            */
            rc = readn(fd, bp, len);
            if (rc != len )//���� ��������� �� ���
                return rc < 0 ? -1 : 0;
            reclen -= len;//�������� ��������� ������
            if (reclen < len )
                len = reclen;
        }
        set_errno ( EMSGSIZE );//���������� ���������� � �������
        return -1;
    }
        /* ��������� ������
        ���� ����� ������ ������������� �� ������ ��������� ������
        */

    rc = readn( fd, bp, reclen );
    if ( rc != reclen )
        return rc < 0 ? -1 : 0;
    return rc;
}

//////////////////////���������� ������� readvrec//////////////////////////////
int main( int argc, char **argv )
  {
 		struct sockaddr_in peer;
 		SOCKET s;
 		SOCKET s1;
 		int peerlen = sizeof( peer );
 		int n;
    char buf[ 10 ];
		INIT();
		if ( argc == 2 )
			s = tcp_server( NULL, argv[ 1 ] );
		else
			s = tcp_server( argv[ 1 ], argv[ 2 ] );
		s1 = accept( s, ( struct sockaddr * )&peer, &peerlen );
		if ( !isvalidsock( s1 ) )
			error( 1, errno, "������ ������ accept" );
		for ( ;; )
		{
			n = readvrec( s1, buf, sizeof( buf ) );
			if ( n < 0 )
				error( 0, errno, "readvrec ������� ��� ������" );
			else if ( n == 0 )
				error( 1, 0, "������ ����������\n" );
			else
				write( 1, buf, n );
		}
		EXIT( 0 );		/* ���� �� ��������. */
 }
