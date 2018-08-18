#include <sstream>
#include <iostream>

using namespace std;

int main(){
  char s[200];
cout <<"enter something";
  cin.getline(s,200);
  istringstream ist(s);
  string w;
  while(ist>> w) cout <<w << "\n";
}

