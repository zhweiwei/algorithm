#include "avlnode.h"
#include <iostream>

using namespace std;

int main(){
  AvlTree<int> a;
  a.insert(21);
  a.insert(2);
  a.insert(43);
  a.printTree();
}
