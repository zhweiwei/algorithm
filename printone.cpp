#include <iostream>

using namespace std;

int  printon(double a){
  if(a <10 ){
    cout << a;
  }else{
    double k = (int)a % 10;
    cout<< k;
    printon((a-k)/10);
  }
}

int main(){
 double a;
  cin >> a;
  printon(a);
  cout << endl<<(int) a << endl;

}
