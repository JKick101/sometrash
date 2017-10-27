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
		struct sockaddr_in local; //структура для подключения
		struct sockaddr_in peer;
		/*struct sockaddr_in{
    short sin_family;  //семейство адресов
    unsigned short sin_port;  //порт(нужен сетевой порядок байт)
    struct in_addr sin_addr;  //адрес
    char sin_zero[8];  //заполняется нулями
    };*/
		char *hname; //adress
		char *sname; //port
		int peerlen;
		SOCKET s1;
		SOCKET s;
		const int on = 1;
		INIT();
		if ( argc == 2 )// если указан только номер порта
		{
			hname = NULL;
			sname = argv[ 1 ];
		}
		else //если указан номер порта и адрес
		{
			hname = argv[ 1 ];
			sname = argv[ 2 ];
		}

		set_address( hname, sname, &local, "tcp" );
		s = socket( AF_INET, SOCK_STREAM, 0 );//создаем сокет с IPv4 и TCP

		if ( !isvalidsock( s ) ) //макрос прописанный в skel.h (s>=0)
			error( 1, errno, "ошибка вызова socket" );

		if ( setsockopt( s, SOL_SOCKET, SO_REUSEADDR, &on,
			 sizeof( on ) ) )//задает опцию сокета.Если ошибка не возникает, setsockopt возвращает ноль.
			 //В противном случае возвращается значение SOCKET_ERROR, и конкретный код ошибки можно получить,
			 // вызвав WSAGetLastError.

/*			 int setsockopt(
  _In_       SOCKET s,
  _In_       int    level,
  _In_       int    optname,
  _In_ const char   *optval,
  _In_       int    optlen
);

S [in]
     Дескриптор, который идентифицирует сокет.

Уровень [в]
     Уровень, на котором определена опция (например, SOL_SOCKET).

Optname [in]
     Опция сокета, для которой должно быть установлено значение (например, SO_BROADCAST).
      Параметр optname должен быть опцией сокета, определенной на указанном уровне, или поведение не определено.

Optval [in]
     Указатель на буфер, в котором указано значение для запрошенной опции.

Optlen [in]
     Размер в байтах буфера, на который указывает параметр optval.*/

			error( 1, errno, "ошибка вызова setsockopt" );

		if ( bind( s, ( struct sockaddr * ) &local,
			 sizeof( local ) ) )
			// int bind(int sockd, struct sockaddr *my_addr, int addrlen);
			//Системный вызов bind служит для привязки созданного сокета к определенному полному адресу вычислительной сети.
/*
Эта функция используется сервером для присваивания сокету имени.
До выполнения функции bind (т.е. присваивания какого-либо имени,
вид которого зависит от адресного домена ) сокет недоступен программам-клиентам.
			struct sockaddr {
                short sa_family;
                char sa_data[14];
                    };*/

			error( 1, errno, "ошибка вызова bind" );

		if ( listen( s, NLISTEN ) )
//Функция listen используется сервером, чтобы информировать ОС, что он ожидает ("слушает") запросы связи на данном сокете.
//Без такой функции всякое требование связи с этим сокетом будет отвергнуто.
            //Функция listen помещает сокет в состояние, в котором он прослушивает входящее соединение.
            //int listen(SOCKET s,int   backlog);
            //NLISTEN Максимальная длина очереди ожидающих соединений.
			error( 1, errno, "ошибка вызова listen" );

		do
		{
			peerlen = sizeof( peer );
			s1 = accept( s, ( struct sockaddr * )&peer, &peerlen );
/* Эта функция используется сервером для принятия связи на сокет. Сокет должен быть уже слушающим в момент вызова функции.
Если сервер устанавливает связь с клиентом, то функция accept возвращает новый сокет-дескриптор, через который и
происходит общение клиента с сервером. Пока устанавливается связь клиента с сервером, функция accept блокирует другие
запросы связи с данным сервером, а после установления связи "прослушивание" запросов возобновляется.

Прототип: int accept(int s, char * name, int* anamelen);

Первый аргумент функции - сокет-дескриптор для принятия связей от клиентов.
Второй аргумент - указатель на адрес клиента (структура sockaddr ) для соответствующего домена.
Третий аргумент - указатель на целое число - длину структуры адреса.
Второй и третий аргументы заполняются соответствующими значениями в момент установления связи клиента с сервером и
позволяют серверу точно определить, с каким именно клиентом он общается. Если сервер не интересуется адресом клиента,
в качестве второго и третьего аргументов можно задать NULL-указатели.
*/
			if ( !isvalidsock( s1 ) )
				error( 1, errno, "ошибка вызова accept" );
			server( s1, &peer );
			CLOSE( s1 );
		} while ( 1 );
		EXIT( 0 );
 }


 static void set_address( char *hname, char *sname,
 		struct sockaddr_in *sap, char *protocol )
  {
		struct servent *sp;//Структура обслуживающего устройства используется для хранения или возврата имени и
		// номера службы для данного имени службы.
 		struct hostent *hp;//Структура хоста используется функциями для хранения информации о данном хосте,
 		// например, имя хоста, адрес IPv4 и т. Д. Приложению никогда не следует пытаться модифицировать эту структуру или
 		// освобождать какие-либо ее компоненты. Более того, только одна копия структуры хоста выделяется для каждого потока,
 		//и поэтому приложение должно копировать любую информацию, которая ему нужна, до выдачи любых других вызовов Windows Sockets API.
 /*
 typedef struct hostent {
  char FAR      *h_name;
  char FAR  FAR **h_aliases;
  short         h_addrtype;
  short         h_length;
  char FAR  FAR **h_addr_list;
} HOSTENT, *PHOSTENT, FAR *LPHOSTENT;

H_name
Официальное имя хоста (ПК). Если используется DNS или аналогичная система разрешения,
то полное доменное имя (FQDN) заставляет сервер возвращать ответ. Если используется файл локальных хостов,
это первая запись после адреса IPv4.

H_aliases
Массив чередующихся имен с NULL-концом.

h_addrtype
Тип возвращаемого адреса.

H_length
Длина в байтах каждого адреса.

H_addr_list
Список адресов, заканчивающихся NULL для хоста. Адреса возвращаются в сетевом порядке байтов.
Макрос h_addr определяется как h_addr_list [0] для совместимости со старым программным обеспечением.
*/

 		char *endptr;
 		short port;
 		bzero( sap, sizeof( *sap ) );//Функция bzero заполняет первые n байт, начиная с адреса sap,
 		//нулевыми значениями. Функция ничего не возвращает.(короче обнуляет структуру)
 		sap->sin_family = AF_INET;//устанавливаем скмейство адресов

 		//если был введен IP
		if ( hname != NULL )
		{
			if ( !inet_aton( hname, &sap->sin_addr ) )//Функция inet_aton() переводит символьный IP-адрес
			//в числовое представление в сетевом порядке байт и заносит его во второй параметр
            //тоесть бурет строку hname преобразует в число и занист в поле sin_addr структуры sockaddr_in
			{
				//если получили ошибку то используем gethostbyname
				//Функция gethostbyname извлекает информацию о хосте, соответствующую имени хоста из базы данных хоста.
				hp = gethostbyname( hname );
				if ( hp == NULL )
					error( 1, 0, "неизвестный хост: %s\n", hname );//если и это не помогло выкидываем ошибку и выходим
				sap->sin_addr = *( struct in_addr * )hp->h_addr;
/*
Структура in_addr представляет собой адрес интернета.

struct in_addr {
	union {
		struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { u_short s_w1,s_w2; } S_un_w;
		u_long S_addr;
	} S_un;
};

S_un_b - адрес в формате как четыре u_chars.
S_un_w - адрес в формате как два u_shorts.
S_addr - адрес в формате u_long.

Как обращаться к этим данным ?? Вот, например, как можно заполнить эту стуктуру:

in_addr adr2;
adr2.s_addr=inet_addr("124.23.45.67");
*/
			}
		}
		else
            //если не было написано адреса то берем любой входящий
			sap->sin_addr.s_addr = htonl( INADDR_ANY );//Функция htonl осуществляет перевод целого длинного числа из порядка байт,
			//принятого на компьютере, в сетевой порядок байт.
		port = strtol( sname, &endptr, 0 );//Функция strtol преобразовывает строку в long int.
		//Анализируя строку string, strtol интерпретирует её содержимое в целое число типа long int.
		//long int strtol( const char * string, char ** endptr, int basis );
                        // string
                        //Си-строка для выполнения преобразования.

                        // endptr
                        // Ссылка на объект типа char*, значение которой содержит адрес следующего символа в строке string,
                        // сразу после предыдущего найденного числа. Если этот параметр не используется,
                        //он должен быть нулевым указателем.

                        // basis
                        // Основание системы исчисления.

		if ( *endptr == '\0' )
			sap->sin_port = htons( port );//Функция htons осуществляет перевод целого короткого числа из порядка байт,
			// принятого на компьютере, в сетевой порядок байт.
		else
		{
			sp = getservbyname( sname, protocol );//Функция getservbyname извлекает служебную информацию,
			//соответствующую имени и протоколу службы.
			//Если ошибка не возникает, getservbyname возвращает указатель на структуру servent.
			// В противном случае он возвращает нулевой указатель, и конкретный номер ошибки можно получить,
			//вызвав WSAGetLastError.
			if ( sp == NULL )
				error( 1, 0, "неизвестный сервис: %s\n", sname );
			sap->sin_port = sp->s_port;//берем из возвращенной структуры номер порта в сетевом порядке
		}

   void error( int status, int err, char *fmt, ... )
 {
 		va_list ap;//Этот тип используется в качестве параметра для макросов,
 		// определенных в <cstdarg> для извлечения дополнительных аргументов функции.
 		//va_list - Этот тип применяется для объявления локальной переменной состояния с общепринятым именем ap,
 		// используемой для передачи параметров.
 		va_start( ap, fmt );
 		/*void va_start(  va_list arg_ptr,  prev_param );*/
 		//va_start задает указатель arg_ptr на первый необязательный аргументу в списке аргументов,
 		// который передан функции. Аргумент arg_ptr должен иметь тип va_list.
 		//Аргумент prev_param — это имя обязательного параметра, который непосредственно предшествует первому
 		//необязательному аргументу в списке аргументов. Если параметр prev_param объявлен в классе регистрового хранения,
 		//поведение макроса не определено. va_start необходимо использовать до первого использования va_arg.
 		//va_start - Этот макрос инициализирует переменную состояние ap. Его необходимо вызвать до первого вызова
 		//va_arg и va_end. В традиционном C va_start устанавливает в ap внутрений указатель на первый из передаваемых
 		//функции аргументов; в Standart C va_start содержит дополнительный параметр - имя последнего фиксированого
 		//параметра, - и устанавливает внутрений указатель в ap на первый аргумент списка переменной длины.
 		fprintf( stderr, "%s: ", program_name );
 		vfprintf( stderr, fmt, ap );
 		va_end( ap );//После получения всех аргументов va_end сбрасывает указатель на NULL.
 		// va_end должен вызываться для каждого списка аргументов, который инициализируется va_start или va_copy,
 		//до выполнения возврата функцией.
 		//va_end - Эту функцию (или макрос) необходимо вызвать после считывания макросом va_arg всех аргументов.
 		//Он выполняет все необходимые обнуления переменных ap и va_alist.
 		if ( err )//если err не ноль то считается что это значение errno
 			fprintf( stderr, ": %s (%d)\n", strerror( err ), err );
		if ( status )//если статус 0 то производится выход,иначе управление передается обратно
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
 			error( 1, errno, "ошибка вызова socket" );
		if ( setsockopt( s, SOL_SOCKET, SO_REUSEADDR,
			( char * )&on, sizeof( on ) ) )
			error( 1, errno, "ошибка вызова setsockopt" );
		if ( bind( s, ( struct sockaddr * ) &local,
			 sizeof( local ) ) )
			error( 1, errno, "ошибка вызова bind" );
		if ( listen( s, NLISTEN ) )
			error( 1, errno, "ошибка вызова listen" );
		return s;
 }

int readn(SOCET fd, char *bp, size_t len) //функция, считывающая len байт
{

    int cnt;
    int rc;

    cnt = len;
    while ( cnt > 0) //пока не считаются все байты
    {
        rc = recv(fd, bp, cnt, 0);
        if ( rc < 0 )//в случае ошибки
        {
            if ( errno == EINTR)//возобновляет выполнение recv если он прерван сигналом
                continue;
            return -1;
        }
        if ( rc == 0)//если данные не были записаны
            return len - cnt;
        bp += rc;//переходим к следующей пачке данных
        cnt -= rc;//вычитаем пачку данных из общего колличества байт
    }
    return len;
}

//ЕСЛИ НУЖНО СЧИТЫВАТЬ ДАННЫЕ ПЕРЕМЕННОЙ ДЛИНЫ
int readvrec(SOCKET fd, char *bp, size_t len)
{
    u_int32_t reclen;//uint32_t
    int rc;
    /*
        Длина записи считывается в переменную reclen.Функция readvrec возвращает 0
        если число байтов прочитанных readn не точно совпадает с
        размером целого, или -1 в случае ошибки.
    */
    rc = readn(fd, (char*)&reclen, sizeof(u_int32_t));
    if ( rc != sizeof(u_int32_t))
        return rc < 0 ? -1 : 0;
    reclen = ntohl(reclen);//преобразуем размер записи в машинный порядок
    if (reclen > len)//если объем буфера оказался мал
    {
        /*
         Не хвтатет места в буфере для раззмещения данных-
         отбросить их и вернуть код ошибки.
        */
    while ( recelen > 0)//пока все не считается
        {
            /*
                Считывание данных в буфер порциями по len
            */
            rc = readn(fd, bp, len);
            if (rc != len )//если считалось не все
                return rc < 0 ? -1 : 0;
            reclen -= len;//вычитаем считанные данные
            if (reclen < len )
                len = reclen;
        }
        set_errno ( EMSGSIZE );//возвращаем управление с ошибкой
        return -1;
    }
        /* Прочитать запись
        если длина буфера соответствует то просто считываем запись
        */

    rc = readn( fd, bp, reclen );
    if ( rc != reclen )
        return rc < 0 ? -1 : 0;
    return rc;
}

//////////////////////Применение функции readvrec//////////////////////////////
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
			error( 1, errno, "ошибка вызова accept" );
		for ( ;; )
		{
			n = readvrec( s1, buf, sizeof( buf ) );
			if ( n < 0 )
				error( 0, errno, "readvrec вернула код ошибки" );
			else if ( n == 0 )
				error( 1, 0, "клиент отключился\n" );
			else
				write( 1, buf, n );
		}
		EXIT( 0 );		/* Сюда не попадаем. */
 }
