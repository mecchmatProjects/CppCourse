#include "Source.cpp"
void testFile(const char *);
void testConsole();

int main() {
 int otvet;
 cout<<"Type of input "<<endl;				//выбираем тип тестирования(через файл или консоль)
 cout<<"1. Console "<<endl;
 cout<<"2. Text  "<<endl;
 while(cin>>otvet){
 if(otvet==2){
   testFile("input.txt");
   break;
 }
 if(otvet==1){
   testConsole();
   break;
 }
 cout<<"Type of input "<<endl;
 cout<<"1. Console "<<endl;
 cout<<"2. Text  "<<endl;
 }
 system("pause");
 return 0;
}

void testConsole() {									//тест через консоль
 ui n1, n2;

 cout << "Type size of polynom A:\t";
 cin >> n1;
 if(n1<=0){
  cout<<"Wrong data";
 }
 
 vector <ui> a(n1 + 1);
 cout << "\nType the coefficients of polynom A for powers from 0 to " << n1 << endl;
 for (int i = 0; i <= n1; i++)
  cin >> a[i];
 
 cout << "Type size of polynom B:\t";
 cin >> n2;
 if(n2<=0){
  cout<<"Wrong data";
 }

 
 vector <ui> b(n2 + 1);
 cout << "\nType the coefficients of polynom B for powers from 0 to " << n2 << endl;
 for (int i = 0; i <= n2; i++)
  cin >> b[i];
 cout << endl;

 IPoly A(a), B(b), t1, t2, t3, t4, t5, t6, t7;
 t1 = A + B;
 cout << "A + B = \t";
 t1.print(cout);
 t2 = A - B;
 cout << endl << "A - B = \t";
 t2.print(cout);
 t3 = A * B;
 cout << endl << "A * B = \t";
 t3.print(cout);
 t4 = A / B;
 cout << endl << "A / B = \t";
 t4.print(cout);
 t5 = A % B;
 cout << endl << "A % B = \t";
 t5.print(cout);
 t6 = A.derivate();
 cout << endl << "dA/dx = \t";
 t6.print(cout);
 t7 = A.integrate();
 cout << endl << "integral Adx = \t";
 t7.print(cout);
 int t8 = A.integrate(0, 10);
 cout << endl << "integral Adx from 0 to " << 10 << " = \t" << t8 << endl;
}

void testFile(const char * filename) {					//тест из файла
 ifstream fin(filename);
 ifstream infile(filename);
 infile.seekg(ios::beg);
 ofstream fout("output.txt");
 ui n1, n2;

 fin >> n1;
 if(n1<=0){
  cout<<"Wrong data";
 }

 vector <ui> a(n1 + 1);
 for (int i = 0; i <= n1; i++)
  fin >> a[i];
 

 fin >> n2;
 if(n2<=0){
  cout<<"Wrong data";
 }

 vector <ui> b(n2 + 1);
 for (int i = 0; i <= n2; i++)
  fin >> b[i];
 
 fout << endl;

 IPoly A(a), B(b), t1, t2, t3, t4, t5, t6, t7;
 t1 = A + B;
 fout << "A + B = \t";
 t1.print(fout);
 t2 = A - B;
 fout << endl << "A - B = \t";
 t2.print(fout);
 t3 = A * B;
 fout << endl << "A * B = \t";
 t3.print(fout);

 t4 = A / B;
 fout << endl << "A / B = \t";
 t4.print(fout);
 t5 = A % B;
 fout << endl << "A % B = \t";
 t5.print(fout);
 t6 = A.derivate();
 fout << endl << "dA/dx = \t";
 t6.print(fout);
 t7 = A.integrate();
 fout << endl << "integral Adx = \t";
 t7.print(fout);
 int t8 = A.integrate(0, 10);
 fout << endl << "integral Adx from 0 to " << 10 << " = \t" << t8 << endl;
 fin.close();
 fout.close();
}

