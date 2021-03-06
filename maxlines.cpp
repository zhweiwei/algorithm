#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int max3(int,int,int);
int maxSum(const vector<int> & a,int left,int right){
  if(left == right)
    return a[left] > 0? a[left]: 0;
  int center = (left+right)/2;
  int leftMax = maxSum(a,left,center);
  int rightMax = maxSum(a,center+1,right);

  int borderleft = 0,maxBorderleft = 0;
  for(int i= center;i >= left;i--){
    borderleft +=a[i];
    if(borderleft > maxBorderleft)
      maxBorderleft = borderleft;
  }

  int borderright = 0,maxBorderright = 0;
for(int i =center+1;i <= right;i++){
    borderright += a[i];
  if(borderright > maxBorderright)
    maxBorderright = borderright;
  }
    
return max3(leftMax,rightMax,maxBorderleft+maxBorderright);

}

int max3(int a,int b,int c){
  return a>b?(a>c?a:c):(b>c?b:c);
}

int maxsub(const vector<int> &a){
  return maxSum(a,0,a.size()-1);
}

int main(){
  int i;
 int v[] = {12,2,-23,4,3,-34,54,65,23,-23,-45,4,56,-34,-65};
  vector<int> a(v,v+15);

  int max = maxsub(a);
  vector<int>::iterator p = a.begin();
  while(p != a.end()) cout << *p++ <<" " ;

  cout << endl << "max =  " << max;
}
