#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main ()
{
  char str[] = " Програмування рядків на Сі,   це  ... щось.";
  char *words[10]; 
  int k =0;
  printf("Розділення рядку \"%s\" на лексеми.", str);
  char *pch = strtok (str, " ,."); //в другому аргументі роздільники (пробіл, кома, крапка)
  printf("\nЛексеми:");
  while (pch != NULL) //поки є лексеми
  {
      printf("\n%s", pch);
      words[k] = (char*) malloc(strlen(pch) * sizeof(pch[0])); 
      strcpy(words[k++],pch);
      pch = strtok (NULL, " ,.-");
  }
  printf("\n");
  for(int i=0;i<k;i++){
      printf("%s,", words[i]);
  }

  return 0;
}
