#include <iostream>
#include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <stdarg.h>
 #include <string.h>
  #include <errno.h>
 // #include <netdb.h>
 #include <fcntl.h>
 // #include <sys/time.h>
//   #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
#include <winsock.h>

using std::cout;
using std::cin;

struct
{
    uint32_t len;
    char buf[128];
}packet;
int main()
    {

       fgets(packet.buf, sizeof(packet.buf), stdin) != NULL;
       cout<<packet.buf;
        return 0;
    }
