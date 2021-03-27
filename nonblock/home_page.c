#include    "web.h"

void
home_page(const char *host, const char *fname)
{
  int   fd, n;
  char  line[MAXLINE];

  fd = Tcp_connect(host, SERV); /* blocking connect() */

  n = snprintf(line, sizeof(line), GET_CMD, fname);
  Write(fd, line, n);

  for ( ; ; ) {
    if ( (n = Read(fd, line, MAXLINE)) == 0)
      break;        /* server closed connection */

    print("read %d bytes of home page\n", n);
  }
  printf("end-of-file on home page\n");
  Close(fd);
}
