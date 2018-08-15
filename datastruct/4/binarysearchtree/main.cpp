#include "BinarySearchTree.h"

extern template class BinarySearchTree<int>;
int main(){
BinarySearchTree<int> a;
a.insert(10);
a.insert(1);
a.insert(4);
a.printTree();
}
