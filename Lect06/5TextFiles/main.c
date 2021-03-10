// C program to read Student records 
// like id, name and age, 
// and display them in sorted order by Name 
  
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
  
// struct person with 3 fields 
typedef struct Student { 
    char name[10]; 
    int id; 
    char age; 
}Student; 
  
// setting up rules for comparison 
// to sort the students based on names 
int comparator(const void* p, const void* q) 
{ 
    return strcmp(((struct Student*)p)->name, 
                  ((struct Student*)q)->name); 
} 


int createTextFile(const char* fname){
   
    FILE* f = fopen(fname, "wt");
    if(f==NULL) return EXIT_FAILURE;
    int k=0;


        int id;
        int age;
        char name[10];
        char str[20];
        char c;
        int input_done = 0;
    do{
        
        printf("Input student %d: id  age name:\n",k);
        fflush(stdin);
        //fgets(str, 20, stdin);
        //fflush(stdin);
        
        input_done = scanf("%d %d %s", &id,&age, name);
        
        //scanf("%s",name);
        //sscanf(str, "%d %d %s", &id, &age, name); //VERY dangerous
        //fflush(stdin);
        if(input_done==3){
           printf("Student %d: %d %d %s\n",k,id,age,name);
           fprintf(f,"%d %c %s\n", id, (char)age, name);
        }
        else{
           fprintf(stderr,"Error in input: cycle breaks\n");     
           fflush(stdin);
        }
        printf("Do You want to enter another student?y/n\n");
        scanf("\n%c",&c);
        
        k++;  
    }while(tolower(c)=='y' || isspace(c));
    fclose(f);
    return EXIT_SUCCESS;
}


int readTextFile(const char* fname, Student* mas){

    int id;
    char age;
    char name[10];
    int i=0;

    FILE* f = fopen(fname, "rt");
    if (f==NULL) return EXIT_FAILURE;

    do{   
        //fscanf(f,"%d ", &id);
        //fscanf(f,"%c", &age);
        //fscanf(f,"%s", name);
        fscanf(f,"%d %c %s", &id, &age, name); //dangerous
        //fprintf(stdout,"%d %d %s\n", id, (int)age, name);
        
        mas[i].age = age;
        mas[i].id = id;
        strcpy(mas[i].name , name); 
        i++;
    }while(!feof(f));
    fclose(f);
    return i-1;
}



int main(int argc, char **argv)
{
    const char fname[] = "studs.txt";

    createTextFile(fname);
    Student studs[10];
    int k = readTextFile(fname, studs);
    if (k<0) return EXIT_FAILURE;
    int i=0;
    
    for(Student* strt=studs;strt<&studs[k]; ++strt){
        fprintf(stdout,"\n Stud [%d]= %d %d %s", i++, strt->id, (int)strt->age, strt->name);
    }
    
    // Sort the structure 
    // based on the specified comparator 
    qsort(studs, k, sizeof(Student), comparator); 
  
    // Print the Sorted Structure 
    printf("\n\nStudent Records sorted by Name:\n"); 
    for (i = 0; i < k; i++) { 
        printf("Id = %d, Name = %s, Age = %d \n", 
               studs[i].id, studs[i].name, studs[i].age); 
    } 
  
    
	return 0;
}
