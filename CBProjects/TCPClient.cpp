
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
 				error( 1, errno, "ошибка вызова socket" );
		if ( connect( s, ( struct sockaddr * )&peer,
			 	sizeof( peer ) ) )
				error( 1, errno, "ошибка вызова connect" );
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
 			error( 1, errno, "ошибка вызова socket" );
    if ( connect( s, ( struct sockaddr * )&peer,
			 sizeof( peer ) ) )
			error( 1, errno, "ошибка вызова connect" );
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

/*Функция служит для чтения данных из сокета.

int recv(int s, char * buf, int len, int flags);

Первый аргумент - сокет-дескриптор, из которого читаются данные. Второй и третий аргументы - соответственно,
адрес и длина буфера для записи читаемых данных. Четвертый параметр - это комбинация битовых флагов,
управляющих режимами чтения. Если аргумент flags равен нулю, то считанные данные удаляются из сокета.
Если значение flags есть MSG_PEEK, то данные не удаляются и могут быть считаны последущим вызовом ( или вызовами ) recv.

Функция возвращает число считанных байтов или -1 в случае ошибки. Следует отметить, что нулевое значение не является ошибкой.
Оно сигнализирует об отсутствии записанных в сокет процессом-поставщиком данных.
*/

    if ( rc<=0 )
        break;
    write(1, buf , rc );

    }
}


//////////////////////Клиент,посылающий записи переменной длины////////////////////////////////
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
            Функция fgets считывает символы из потока и сохраняет их в виде строки в параметр string
            до тех пор пока не наступит конец строки или пока не будет достигнут конец файла.

    Параметры:
    string
    Указатель на массив типа char, в который сохраняются считанные символы.
    num
    Максимальное количество символов для чтения, включая нулевой символ.
    filestream
    Указатель на объект типа FILE, который идентифицирует поток, из которого считываются символы.

    Для чтения из стандартного ввода, stdin может быть использован в качестве этого параметра.

    В случае успеха, функция возвращает указатель на string. Если конец файла был достигнут и ни один символ не был прочитан,
    содержимое string остается неизменными и возвращается нулевой указатель. Если происходит ошибка, возвращается нулевой указатель.
    В случае успеха, функция возвращает указатель на string. Если конец файла был достигнут и ни один символ не был прочитан,
    содержимое string остается неизменными и возвращается нулевой указатель. Если происходит ошибка, возвращается нулевой указатель.


		*/
		while ( fgets( packet.buf, sizeof( packet.buf ), stdin )//считали все данные с потока ввода в буфер
			!= NULL )
		{
			n = strlen( packet.buf );// вычислили размер буфера с данными
			packet.reclen = htonl( n );//записали этот размер в перуменную(в сетевом порядке)
			if ( send( s, ( char * )&packet,
				 n + sizeof( packet.reclen ), 0 ) < 0 )//отправляем пакет серверу
				error( 1, errno, "ошибка вызова send" );
		}
		EXIT( 0 );
 }
