#include <winsock2.h>

SOCKET socket(int domain, int type, int protocol);//ОНКСВЕМХЕ ЯНЙЕРЮ
//SOCKET socket(AF_INET | AF_LOCAL, SOCK_STREAM | SOCK_DGRAM | SOCK_RAW, 0);

//сярюмнбкемхе янедхмемхъ
int connect(SOCKET s, const struct sockaddr* peer, int peer_len);

//опхел-оепедювю
//TCP
int recv( SOCKET s, void *buf, size_t len, int flags );

int send( SOCKET s, const void *bud, size_t len, int flags );
//UDP
int recvfrom( SOCKET s, void *buf, size_t len, int flags,
         struct sockaddr* from, int* fromlen );

int sendto( SOCKET s, const void *bud, size_t len, int flags
         const struct sockaddr* to, int tolen);

//опхбъгйю юдпеяю хмрептеияю х мнлепю онпрю й опняксьхбючыелс янйерс

int bind(SOCKET s, const struct sockaddr *name, int namelen);
