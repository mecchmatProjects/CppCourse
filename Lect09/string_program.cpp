#include <iostream>
#include <string>
#include <cstring> // Required by strcpy()
#include <cstdlib> // Required by malloc()

#include <sstream> // ostringstream

using namespace std;
//C++11: std::string to_string( int value );


string int2string(const int& number)
{
    ostringstream oss;
    oss << number;
    return oss.str();
}

// Read lines from standard input:
int input(int m){
    string sLine;
    int i=0;
    while(getline(std::cin, sLine)){
        if( sLine.empty() );// Ignore empty lines
        else{
            cout<<sLine;
            cout << sLine[0] << sLine[1] << endl;
            i++;
            if(i>=m) break;
        }
    }
    return 0;
}


string app1(string name, int n){
    string res(name + "_");
    res.append(to_string(n));//c++11
    return res;
}
string app2(string name, int n){
    ostringstream os1;
    os1 <<name<<"_"<< n;
    return os1.str();
}
string app3(string name, int n){
    char num[10];
    sprintf(num, "%s_%d",name.c_str(), n); // Could have printed directly using printf()
    //string res1(num);
    return string(num);
}


#define SYS_CONFIG_FILE "config.tmp.txt"
//#include <algorithm>
//#include <vector>
#include <cctype>

#include <fstream>

int fun2()
{
    string::size_type posBeginIdx, posEndIdx;
    string::size_type ipos=0;
    string sLine, sValue;
    string sKeyWord;
    const string sDelim(" ");
    string sError;
    
    ifstream myInputFile(SYS_CONFIG_FILE, ios::in);
    if(!myInputFile){
        sError = "File SYS_CONFIG_FILE could not be opened";
        return -1;// ERROR
    }
    cerr<<"Line";
    while(getline(myInputFile, sLine)){
     
        cerr<<sLine;
        if(myInputFile.bad()) break;
        if( !sLine.empty()){
            posEndIdx = sLine.find_first_of(sDelim);
            if(posEndIdx==string::npos) break;   
            sKeyWord = sLine.substr( ipos, posEndIdx ); // Extract word
            posBeginIdx = posEndIdx + 1; // Beginning of next word (after ':')
            cout<<posBeginIdx<<sKeyWord<<posEndIdx;
            ipos++;
            }
        }
    return ipos;//???
}
//    • Strip blank characters:
void stripLeadingAndTrailingBlanks(string& StringToModify)
{
    if(StringToModify.empty()) return;
    int startIndex = StringToModify.find_first_not_of(" ");
    int endIndex = StringToModify.find_last_not_of(" ");
    string tempString = StringToModify;
    StringToModify.erase();
    StringToModify = tempString.substr(startIndex, (endIndex-startIndex+ 1) );
}



int fun()
{
    string a("Preved Medved");
    string b{" i vsem privet"};
    string c;
    cout << a << " " << b << endl; // Output: abcd efg xyz ijk
    cout << "String empty: "<<boolalpha<<c.empty()<< endl;
    // String empty: 1  -  Yes it is empty. (TRUE)
    c = a + b; // concatenation
    cout << c << endl; // abcd efgxyz ijk
    cout <<"String length:"<<c.length()<< endl;
    // String length: 15
    cout << "String size: "<<c.size()<< endl;
    // String size: 15
    cout << "String capacity: "<< c.capacity() << endl;
    // String capacity: 15
    cout << "String empty: "<<c.empty()<<endl;
    // String empty: 0
    // Is string empty? No it is NOT empty. (FALSE)
    string d = c;
    cout << d << endl; // abcd efgxyz ij                    
    cout << "First character: " << c[0] << endl;// First character: a
    // Strings start with index 0 just like C.
    string f("    Leading and trailing blanks      ");
    cout << "String f:" << f << endl;
    cout << "String length: " << f.length() << endl;
    // String length: 37
    cout << "String f:"<< f.append("ZZZ")<< endl;
    // String f:    Leading and trailing blanks      ZZZ
    cout << "String length: " << f.length() << endl;
    // String length: 40
    string g("abc abc abd abc");
    cout << "String g: " << g << endl;
    // String g: abc abc abd abc
    cout << "Replace 12,1,\"xyz\",3: " << g.replace(12,1,"xyz",3) << endl;
    // Replace 12,1,"xyz",3: abc abc abd xyzbc
    cout << g.replace(0,3,"xyz",3) << endl;
    // xyz abc abd xyzbc
    cout << g.replace(4,3,"xyz",3) << endl;
    // xyz xyz abd xyzbc
    cout << g.replace(4,3,"ijk",1) << endl;
    // xyz i abd xyzbc
    cout << "Find: " << g.find("abd",1) << endl;
    // Find: 6
    cout << g.find("qrs",1) << endl;
    string h("abc abc abd abc");
    cout << "String h: " << h << endl;
    cout << "Find \"abc\",0: " << h.find("abc",0) << endl; // Find "abc",0: 0
    cout << "Find \"abc\",1: " << h.find("abc",1) << endl; // Find "abc",1: 4
    cout << "Find_first_of \"abc\",0: " << h.find_first_of("abc",0) << endl; // Find_first_of "abc",0: 0
    cout << "Find_last_of \"abc\",0: " << h.find_last_of("abc",0) << endl;
    // Find_last_of "abc",0: 0
    cout << "Find_first_not_of \"abc\",0: " << h.find_first_not_of("abc",0) << endl;
    // Find_first_not_of "abc",0: 3
    cout << "Find_first_not_of \" \": " << h.find_first_not_of(" ") << endl;
    // Find_first_not_of " ": 0
    cout << "Substr 5,9: " << h.substr(5,9) << endl;
    // Substr 5,9: bc abd ab
    cout << "Compare 0,3,\"abc\": " << h.compare(0,3,"abc") << endl;
    // Compare 0,3,"abc": 0
    cout << "Compare 0,3,\"abd\": " << h.compare(0,3,"abd") << endl;
    // Compare 0,3,"abd": -1
    cout << h.assign("xyz",0,3) << endl;
    // xyz
    cout << "First character: " << h[0] << endl; // Strings start with 0 // First character: x
    return 0;
}



int main(int argc, char **argv)
{

    char CC[17];// C character string (16 characters + NULL termination)
    char *CC2;   // C character string. No storage allocated.

    strcpy(CC,"This is a string");
    CC2 = (char *) malloc(17);    // Allocate memory for storage of string.
    //strcpy(CC2,"This is a string");
    strcpy(CC2,CC);

    cout << CC << endl;
    cout << CC2 << endl;

    string SS;   // C++ STL string
    string SS2;  // C++ STL string

    SS = "This is a string";
    SS2 = SS;

    cout << SS << endl;
    cout << SS2 << endl;


// Constructors:
//1 string sVar1(Literal);
//2 string sVar2(C-string-variable);   // Null terminated char
//3 string sVar3(int,Symbol);              // Generate string initialized to <int> Literals.
//4 string sVar4(Var1, string-index);  // Initialize with characters from string starting with index string-index.
//5 string sVar5(iterator-index-begin, iterator-index-end);

// 1 Var.~string();         // Destructor


    string sVar1("Програмування на Сі++");
    string sVar2(sVar1);
    string sVar3(5, '!');
    string sVar4(sVar1, 32);
    string sVar5(sVar4.begin(),sVar4.end());

    cout << sVar1 <<","<< sVar2<<","<< sVar3 <<","<< sVar4<<","<< sVar5<<",";



    string g("abc abc abd abc");
    cout << g.replace(4,1,"ijk",3) << endl;

    string h("abc abc abd abc");
    cout << h.replace(4,6,"ijk",3) << endl;

    string k("abc abc abd abc");
    cout << k.replace(4,3,"ijk",3) << endl;

    string l("abc abc abd abc");

    cout << k.replace(12,1,"xyz",3) << endl;

    cout<<g.find("abc");
    string s1;
    s1.assign("abc");
    s1="abc";
    cout<<g.find(s1);

    cout<<g.find("abc",6);

    cout<<g.find("abc",6,2);

    if(k.find("abcd") == string::npos) cout << "Not found" << endl;

    sVar2 =sVar1 + sVar3;
    sVar2 +=sVar3;
    sVar2.append(sVar3);
    sVar2.push_back('!');
    cout<< sVar2<<endl;
    sVar4.insert(4," та С");
    cout<<sVar4<<'\n';

    sVar5.erase();

    cout<<sVar5.empty()<<sVar4.empty();

    cout<<sVar4.size()<<" "<<sVar4.length()<<endl;


    getchar();

    string alphabetLC="abcdefghijklmnopqrstuvwxyz";
    string::const_iterator cii;
    int ii;
    for(cii=alphabetLC.begin(); cii!=alphabetLC.end(); cii++) {
        cout << ii++ << " " << *cii << endl;
    }
/*
    char phrase1[10] = "phrase";
    string phrase2("Second phrase");
    char phraseA[10];
    char* phraseB;
    strcpy(phraseA, phrase2.c_str());
    phraseB =(char*)strstr(phraseA, phrase1);
    printf("phraseA: %s\n",phraseA);
    printf("phraseB: %s\n",phraseB);
    printf("phrase2: %s\n",phrase2.c_str());
    */
    cout<<int2string(234);
    
    //input(3);
    for(int i=0;i<3;++i){
        cout<<app1("Lesson",i); 
    }   
    
    fun2();
    
    string text = "   sfs asdafgsdg g    gsdgdfgdf  ";
    stripLeadingAndTrailingBlanks(text);
    cout<<endl<<text;
    
    fun();
    
    return 0;
}
/*
This is a string
This is a string
This is a string
This is a string
Програмування на Сі++,Програмування на Сі++,!!!!!,Сі++,Сі++,



 *
*/
/*
abc ijkbc abd abc
abc ijkd abc
abc ijk abd abc
abc ijk abd xyzbc
 * abc ijkbc abd abc - Beginning with the 4th index (character number 5) replace one character with 3 characters from string "ijk"
abc ijkd abc
abc ijk abd abc
abc abc abd xyzbc
 *
 *
*/
