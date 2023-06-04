/* test-fork.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* exit */
#include <sys/wait.h> /* wait */

int main () {
  int shared_resource = 100;
  
  pid_t pid;
  pid = fork();

  if ( pid == 0 ) {
    /* 子プロセス */
    int i;
    for (i = 0; i < 10; i++ ) {
      printf("Process [%d]: %d\n", pid, i);
      shared_resource++;
      sleep(1);
    }
    printf("Process %d finished, return %d.\n", pid, shared_resource);
    exit(0);
  } else if ( pid > 0 ) {
    /* 親プロセス */
    int i;
    for (i = 0; i < 20; i++ ) {
      printf("Process [%d]: %d\n", pid, i);
      shared_resource++;
      usleep(300*1000); // 300 msec
    }
    int status;
    wait(&status);
    printf("Process %d finished, return %d.\n", pid, shared_resource);
  }
  return 0;
}
