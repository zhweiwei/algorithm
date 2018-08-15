#include "BinarySearchTree.h"

template<class Comparable>
bool BinarySearchTree<Comparable>:: contains(const Comparable& x)const{
  return contains(x,root);
  }

template<class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x){
  insert(x,root);
}

template<class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x){
  remove(x,root);
}

template<class Comparable>
void BinarySearchTree<Comparable>::printTree()const{
  printTree(root);
}

template<class Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x,BinaryNode * &t)const{
  if(t == NULL)
    return false; 
  else if(x < t->element)
    contains(x,t->left);
  else if(x > t->element)
    contains(x,t->right);
  else
    return true;

}

template<class Comparable>
const typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::findMin(BinaryNode *const &t)const{
  if(t == NULL)
    return NULL;
  if(t->left == NULL)
    return t;
  findMin(t->left);
}

template<class Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin()const{
  const BinaryNode* temp = findMin(root);
    return temp->element;
  if(temp != NULL){
    return temp->element;
    temp = NULL;
  }
  return -1;
}

template<class Comparable>
const typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode * const& t)const{
  if(t == NULL)
    return NULL;
  if(t->right == NULL)
    return t;
  findMax(t->right);
}

template<class Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax()const{
  const BinaryNode* temp = findMax(root);
    return temp->element;
}

template<class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x,BinaryNode * &t){
  if(t == NULL)
    t = new BinaryNode(x,NULL,NULL);
  else if(t->element > x)
    insert(x,t->left);
  else if(t->element < x)
    insert(x,t->right);
  
}

template<class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x,BinaryNode * & t){
if(t == NULL)
  return;
else if(x < t->element)
  remove(x,t->left);
else if(x > t->element)
  remove(x,t->right);
else if(t->left != NULL && t->right != NULL){
    t->element = findMin(t->right)->element;
    remove(t->element,t->right);
  }else{
    BinaryNode * oldNode = t;
    t = (t->left != NULL)?t->left:t->right;
    delete oldNode;
  }

}

template<class Comparable>
 BinarySearchTree<Comparable>::~BinarySearchTree(){
  makeEmpty(root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode* & t){
  if(t != NULL){
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
  }
  t = NULL;
}

template<class Comparable>
const BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& rhs){
  if(this != rhs){
  makeEmpty(rhs);
  root = clone(rhs.root);
  }
  return *this;
}

template<class Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::clone(BinaryNode *t)const{
  if( t == NULL)
  return NULL;
  return new BinaryNode(t->element,clone(t->left),clone(t->right));
}

template<class Comparable>
void BinarySearchTree<Comparable>::printTree(const BinaryNode * const&t)const{
  if(t != NULL){
  cout << t->element << " ";
  printTree(t->left);
  printTree(t->right);
  } 
}

template<class Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(){
  root =NULL;
}
/*
int main(){
BinarySearchTree<int> a;
a.insert(10);
a.insert(1);
a.insert(4);
a.printTree();
}*/
