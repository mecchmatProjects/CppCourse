#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10;
const int M = 10;

int main(){

  int n,m;
  int a[N][M];
   char buf[10];

  cin>>n;
  cin>>m;
  
  for (int i=0; i<n;++i){
    cout<<"row "  <<i<<":";
    for (int j=0; j<m;++j){
       cin.getline(buf,1,' ');
       sprintf(buf,"%d",&a[i][j]);
    }    
  }

  
for (int i=0; i<n;++i){
    cout<<endl;
    for (int j=0; j<m;++j){
       cout<< a[i][j];
    }    
    
  }

}
