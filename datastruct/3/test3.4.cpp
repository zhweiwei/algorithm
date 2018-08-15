#include <iostream>
#include <list>
#include <iterator> 

using namespace std;

template<class T>
list<T> makeor(list<T>& a,list<T>& b){
   list<T> temp;
  typename list<T>::iterator n = a.begin();
  typename list<T>::iterator m = b.begin();
  while(n != a.end() && m != b.end()){
    if(*n < *m){
    temp.push_back(*n);
    n++;
    }else if(*n > *m){
    temp.push_back(*m);
    m++;
    }else{
    temp.push_back(*m);
    m++;
    n++;

  }
  }

  while(n != a.end()){
    temp.push_back(*n);
    n++;
  }

  while(m != b.end()){
    temp.push_back(*m);
    m++;
  }
  return temp;

}

int main(){
  list<int>a;
  list<int> b;
  int val;
 cout <<"plasea input a :";
  while(cin >> val)a.push_back(val);
 cout <<"plasea input b :";
  while(cin >> val)b.push_back(val);
  list<int> c = makeor(a,b);
  list<int>::iterator p = c.begin();
  while(p != c.end())
  cout << *p++ << " " <<endl;
}
