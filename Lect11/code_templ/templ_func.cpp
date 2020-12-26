#include<iostream>
#include<cstdio>

using namespace std;

template <class My_type> //Оголошення
void sorting(My_type &,My_type &,My_type &); //шаблону



int main(){
 
  int k;
  cout<<"Введ. 1 для впорядкування чисел, 0 - символiв: ";
  cin>>k;
  if (k==1){
    int nx,ny,nz;
    cout<<"Три довiльнi цiлi числа: ";
    cin>>nx>>ny>>nz;
    sorting(nx,ny,nz); //створення екземпляру шаблону
    cout<<"Цi числа в порядку зростання: " <<nx<<" "<<ny<<" "<<nz<<endl;
   }
  if (k==0){
    char nx,ny,nz;
    cout<<"Три довiльнi символи: ";
    cin>>nx>>ny>>nz;
    sorting(nx,ny,nz); //створення екземпляру шаблону
    cout<<"Цi символи в порядку зростання: "<<nx<<" "<<ny<<" "<<nz<<endl;
  }
  getchar();
}

//Опис шаблону
//--------------------------------------------------------------
template <class My_type>
void sorting(My_type &a,My_type &b,My_type &c){
My_type t;
if (a > b) {t = a; a = b; b = t;}
if (b > c) {t = b; b = c; c = t;}
if (a > b) {t = a; a = b; b = t;}
}

