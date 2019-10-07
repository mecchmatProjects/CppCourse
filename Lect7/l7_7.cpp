#include <iostream>

int main(void) { 
const size_t len = 100; 
char name[len]; 
int count = 0; 
std::cout << "Enter your name" << std::endl; 
std::cin.getline(name, len); 
count = std::cin.gcount(); 
/* Зменшуємо значення лічильника на 1, тому що getlіne() не 
поміщає обмежувач в буфер*/ 
std::cout << "Number of symbols is " << count - 1 << std::endl; 
} 

