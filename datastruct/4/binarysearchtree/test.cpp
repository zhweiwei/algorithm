#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class temp:public unary_function<void,int>{
public:
  int operator()(){return rand()%100;}
};

int main(){
vector<int> a(10);
generate(a.begin(),a.end(),temp());
vector<int> e(a.begin(),a.end());
vector<int>::iterator p = a.begin();
while(p != a.end())
cout << *p++ << " ";
cout << endl;
reverse(a.begin(),a.end());
p = a.begin();
while(p != a.end())
cout << *p++ << " ";
cout << endl;

rotate(e.begin(),e.begin()+3,e.end());
p = e.begin();
while(p != e.end())
cout << *p++ << " ";
cout << endl;
vector s;

}
