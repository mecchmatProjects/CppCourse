#include <iostream>
#include <cstring>
#include <string>


using namespace std;

class Human{

  protected:
  string PIB; // char PIB[20];
  unsigned age;

  bool gender;// true - man, false - woman
  public:

  Human(){}
  Human(string s, unsigned x, bool g):PIB(s),age(x),gender(g){}

  friend ostream& operator<<(ostream & ost, const Human & h){
         const char* gen = h.gender?"Male":"Female";
         ost << h.PIB << ", " << h.age <<"," << gen<<endl;
  }


 bool input(){
  string pib; // char PIB[20];
  unsigned ag;
  bool gend;

    cout<<"PIB:";
    cin>> pib;
    cout<<"age:";
    cin>> ag;
    cout<<"Male or Female? M/F?";
    string sex;
    cin>>sex;
    if (tolower(sex[0])=='f'){
    gend =false;
   }
   else{
    gend =true;
   }

  PIB =pib;
  age=ag;
  gender = gend;
  return true;
 }

  int getAge(){
   return age;
 }

 virtual void show(){
  cout<<*this;
 }

};



class Student : public Human{
protected:
  string VUZ;
  unsigned char kurs;
  char grupa[3];

  public:

  Student(){};

  Student(string s, unsigned x, bool g, string V, unsigned char k, const char grup[3]):Human(s,x,g){
   VUZ = V;
   kurs=k;
   strcpy(grupa,grup); // const_cast<...>
  }


  friend ostream& operator<<(ostream & ost, const Student & h){
         const char* gen = h.gender?"Male":"Female";
         ost << h.PIB << " , " << h.age <<" ," << gen<<" VUZ: "<< h.VUZ <<" Kurs: "<<h.kurs <<"," <<"Grupa: "<<h.grupa<<endl;
  }


  // method of input for class Student
  void input(){
  string VU;
  unsigned char kur;
  char grup[3];
   Human::input();
   cout<<"Vuz";
   cin>> VU;
    cout<<"Kurs";
   cin>>kur;
   cout<<"Group";
   cin>>grup;
   VUZ=VU;
   kurs= kur;

 strcpy(grupa,grup);
  }

virtual void show(){
 cout<<*this;
}

};


class Lecturer: public Human{
protected:
  string VUZ;

  public:
  Lecturer(){};

  Lecturer(string s, unsigned x, bool g, string V):Human(s,x,g){
   VUZ = V;
  }

 friend ostream& operator<<(ostream & ost, const Lecturer & h){
         const char* gen = h.gender?"Male":"Female";
         ost << h.PIB << ", " << h.age <<", " << gen<<", " <<" VUZ : "<<h.VUZ<<endl;
  }

  bool input(){
  string VU;
  Human::input();
  cout<<"Vuz";
  cin>> VU;
  VUZ = VU;
  return true;
 }
 void show(){
 cout<<*this;
}

};


class Aspirant: public Student{
  string kafedra;
public:
Aspirant(){};

Aspirant(string s, unsigned x, bool g, string V, unsigned char kur, const char grup[3], string kaf): Student(s,x,g, V, kur, grup){
   kafedra = kaf;
  }

  friend ostream& operator<<(ostream & ost, const Aspirant & h){
         const char* gen = h.gender?"Male":"Female";
         ost << h.PIB << " , " << h.age <<" ," << gen<<" VUZ: "<< h.VUZ <<" Kurs: "<<h.kurs <<"," <<"Grupa: "<<h.grupa<<"," << "Kafedra : "<<h.kafedra<<endl;
  }

  bool input(){
  string kaf;
  Student::input();
  cout <<  "Kafedra : ";
  cin >>  kaf;
  kafedra = kaf;
  return true;
 }

 void show(){
 cout<<*this;
}
};



int main(){
int N=3;

Human* m1[10];

  //int N=2;
for(int i=0;i<N;++i){
   cout<<"Lecturer, student or aspirant ? l/s/a?";
   string str;
   cin>>str;
   if (tolower(str[0])=='l'){
     Lecturer* l = new Lecturer();
     l->input();

     m1[i] =l;
   }
  if(tolower(str[0])=='s') {
     Student* l = new Student;
     l->input();

     m1[i] = l;
   }
   if(tolower(str[0])=='a'){
      Aspirant* l = new Aspirant;
      l->input();

      m1[i] = l;
    }


 }
 for(int i=0;i<N;++i){
 cout<<(*m1[i]);
 m1[i]->show();
 }

}
