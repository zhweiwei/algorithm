#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int maxSub4(const vector<int>& a){
  int maxSum = 0,thisSum = 0;
  for(int j = 0;j < a.size();j++){
    thisSum +=a[j];
    if(maxSum < thisSum) maxSum = thisSum;
    else if(thisSum < 0) thisSum = 0;
    
  }
return maxSum;
}

int main(){
  int a[] = {12,2,-23,4,3,-34,54,65,23,-23,-45,4,56,-34,-65};
  vector<int> v(a,a+15);
  int max = maxSub4(v);
  cout <<"max = " << max << endl;
  vector<int>::iterator p = v.begin();
  while(p != v.end())cout <<*p++ <<" ";
  cout << endl;
}
