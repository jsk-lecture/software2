// server.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // sockaddr_in


int main ()
{
  int ip_port = 1024;

  // ソケットの生成
  //---------------------------------------------------
  int s;
  if ((s = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror ("server: socket");
      exit (1);
    }

  struct sockaddr_in sin;
  memset ((char *) &sin, 0, sizeof (struct sockaddr));
  sin.sin_family = AF_INET;        // アドレスの型の指定
  sin.sin_port = htons (ip_port);        // ポート番号
  sin.sin_addr.s_addr = htonl (INADDR_ANY);        // 待ち受けのIPアドレスの設定 

  // ソケットにパラメータを与える
  if ((bind (s, (struct sockaddr *) &sin, sizeof (sin))) < 0)
    {
      perror ("server: bind");
      exit (1);
    }

  // クライアントの接続を待つ
  //---------------------------------------------------
  if ((listen (s, 10)) < 0)
    {
      perror ("server: listen");
      exit (1);
    }

  int ns;
  printf ("waiting for connection\n");

  // クライアントからの接続をまつ
  //---------------------------------------------------
  if ((ns = accept (s, NULL, 0)) < 0) {
    perror ("server: accept");
    exit (1);
  }
  printf ("Connected : %d\n", ns);

  char buf[256];
  int size;

  // データを受信する
  size = read (ns, buf, 255);
  buf[size] = 0;
  printf("recv (%d) [%s]\n", size, buf);

  // データを送信する
  char buf2[256];
  sprintf(buf2, "Received '%s'!", buf);
  size = write (ns, buf2, strlen(buf2));
  printf ("send (%d) [%s]\n", size, buf2);

  close(s);

  exit (0);
}
