// client.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // sockaddr_in
#include <arpa/inet.h> // ip_addr

int main (int argc, char *argv[])
{
  if (argc == 1)
    {
      printf ("usage: client <server IP address>\n");
      exit (1);
    }

  char* ip_addr = argv[1];
  int ip_port = 1024;

  struct sockaddr_in sin;
  int s;

  // ソケットを生成する
  //---------------------------------------------------
  if ((s = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror ("client: socket");
      exit (1);
    }

  // サーバの情報を与える
  //---------------------------------------------------
  sin.sin_family = AF_INET;        // アドレスの型の指定
  sin.sin_port = htons (ip_port);        // ポート番号
  sin.sin_addr.s_addr = inet_addr (ip_addr);        // 宛先のアドレスの指定 IPアドレスの文字列を変換

  // サーバに接続する
  //---------------------------------------------------
  if ((connect (s, (struct sockaddr *) &sin, sizeof (sin))) < 0)
    {
      perror ("client: connect");
      exit (1);
    }
  printf ("established connection\n");

  char buf[256];
  int size;

  // データを送信する
  strncpy(buf, "Hello World", 12 /* strlen("Hello World") */);
  size = write (s, buf, strlen(buf));
  printf ("send (%d) [%s]\n", size, buf);


  // データを受信する
  size = read (s, buf, 255);
  buf[size] = 0;
  printf("recv (%d) [%s]\n", size, buf);

  close(s);

  exit (0);
}
