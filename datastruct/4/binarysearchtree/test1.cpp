#include<stdio.h>
using namespace std;
class Base{
public:
  void fun() {
    printf("Base fun.." );
  }
};
class Derive :public Base {
public:
  using  Base::fun;
  void fun() {
    printf( "Derive fun.." );
}
};

int main()
{
  printf("ssss");
 // b->fun();
  Derive d;
  d.fun();
 // system("pause");
    return 0;
}

