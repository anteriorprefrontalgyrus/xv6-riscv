#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;

  for(i = 0; i < 3; i++){
    if(fork() == 0){
      pause(5);
      exit(0);
    }
  }

  printf("children: %d\n", headcount());

  for(i = 0; i < 3; i++)
    wait(0);

  exit(0);
}
