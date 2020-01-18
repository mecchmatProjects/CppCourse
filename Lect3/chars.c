
#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <ctype.h>
#include <string.h>

int init_out1 ()
{
char str [16] = { 'T', 'e', 'x', 't', ' ', 'a', 'n', 'd', ' ', 's', 't', 'o', 'p', '!' };
for (int i = 0; i <=sizeof(str); i++)
{
    printf("%c",str[i]);
}
printf("%s",str);
printf("\n");
return 0;
}

int init_out2 ()
{
    setlocale (LC_ALL, "Ukrainain");
    char str2[] = "Текст"; // '\0' присутній неявно
    printf("str=%s\n",str2);
    return 0;
}

void input0(){

  printf("Input 0:");    
  char str[20];
  int i=0;
     
  while((str[i]=getchar()) && str[i]!='\n' && i<19)
    {    i++;   } 
  str[i] ='\0';  
  puts(str); 
}


void input1 ()
{
    char name[20];
    
    printf("Input 1");
    //fflush (stdin); 
    //scanf("%s",name);
    //scanf("%[^\n]s",name);
    //scanf("  %s",name);
    scanf("  %[^\n]s",name);    
    printf("\nText:%s\n",name);
}

void input2 ()
{
    setlocale (LC_ALL, "Ukrainain");
    char Name[20] = "";

    printf("Input 2");
   
   //gets(siteName); // Old style: Unsecure!!!
    fgets(Name, 20, stdin); // good if 20<=strlen(Name)
    puts("Name=");
    puts(Name);
}

void input3 ()
{
    char name[20];
    
    printf("Input 3:");
    //fscanf(stdin,"%s",name);
    //fscanf(stdin,"%[^\n]s",name);
    //fscanf(stdin,"  %s",name);
    fscanf(stdin,"  %[^\n]s",name);    
    printf("\nText:%s\n",name);
}

char Name[20];

char* input4 ()
{
    char name[20];
    
    printf("Input 4:");
    //fscanf(stdin,"%s",name);
    //fscanf(stdin,"%[^\n]s",name);
    //fscanf(stdin,"  %s",name);
    //fread(Name, 1, sizeof(Name),stdin);    
    scanf("  %[^\n]s",Name); 
    printf("\nText:%s\n",Name);
    return Name;
}


int main(){
    init_out1();
    init_out2();
    char* a1 = input4();
    char* a2 = input4();
    char* a3 = input4();
    char* a4 = input4();
    //input2();

    comapare_names(a1,a2,a3,a4);

    return 0;
}
/*
 Text and stop!�
str=Текст
Input string1=ввожу рядок

Text:ввожу
ввожу
  
Text and stop!�
str=Текст
Input stringВввожу рядок
Name=
Вввожу ряд

 * */