#include "avlnode.h"
#include <iostream>

using namespace std;

int main(){
  AvlTree<int> a;
  a.insert(21);
  a.insert(2);
  a.insert(43);
  a.insert(3);
  a.insert(4);
  a.insert(34);
  a.printTree();
  a.printLeftTree();
  a.printlevel();
}
