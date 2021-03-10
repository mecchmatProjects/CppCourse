// C program to demonstrate the problem when 
// scanf() is used in a loop 
#include<stdio.h> 

int main() 
{ 
	char c; 
	printf("......Enter q to quit......\n"); 
	do
	{ 
		printf("Enter a character\n"); 
		scanf("%c", &c); // scanf() leaves a newline character in buffer that is read by next scanf.
		printf("%c\n", c); 
	} 
	while (c != 'q'); 
	return 0; 
} 

/*
1) Use getchar() after scanf, fgets
2) use scanf("%c\n", &c);
*/
