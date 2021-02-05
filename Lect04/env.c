#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Directory Python = %s\n",getenv("PATH"));

  setenv("PYTHON3", "/usr/bin/python3.6",50);
  printf("File = %s\n", getenv("PYTHON3"));

  setenv("DIR", "/home/albatros/TUTORIAL",50);
  printf("Directory name before modifying =%s\n", getenv("DIR"));
  putenv("DIR=/home/albatros/CPP_TUTORIAL");
  printf("Directory name after modifying =%s\n", getenv("DIR"));

  return 0;
}
