#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<class Comparable>
int binarySearch(const vector<Comparable>& a,const Comparable& x){
  int low = 0,hight = a.size()-1;
  while(low <= hight){
    int mid = (low+hight)/2;  
    if(x < a[mid]) {
    hight = mid -1;
    break;
    }
    else if(x >a[mid]){
    low = mid+1;
    break;
  }
  return mid;
  }
  return -1;
}

int main(){
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> p(a,a+10);
  cout << binarySearch(p,5) <<endl;
}
