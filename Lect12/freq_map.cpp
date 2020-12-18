#include <iostream>
#include <fstream>
#include <iomanip>
#include <map> 	
#include <set> 	
#include <string>   
#include <cstdlib>   
using namespace std;

int main(){
// punctuation marks
char punct[] = {'.', ',', '?', '!', ':', ';','(', ')'};
set <char> punctuation(punct, punct + 8);
// load file prose.txt
ifstream in("prose.txt");
if (!in)  { cerr << "File not found\n"; exit(1);}
// frequency map as the map
map<string, int> wordCount;
string s;
// read strings till the end 
while (in >> s){
    // trim punctuations int the string
   int n = s.size();
   if (punctuation.count(s[n - 1])){
          s.erase(n - 1, n);
   }
   if (punctuation.count(s[0])){
          s.erase(0, 1);
   }
   wordCount[s]++; 
}
// output result to file
ofstream out("freq_map.txt");
map<string, int>::const_iterator it = wordCount.begin();
for (it; it  != wordCount.end(); ++it){ 
          out << setw(20) << left << it->first
          << setw(4) << right << it->second << endl;
}
cout <<"Results are in file freq_map.txt" << endl;
out.close();
}
