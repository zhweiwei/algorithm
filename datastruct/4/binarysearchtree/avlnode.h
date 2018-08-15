#ifndef AVLNODE_H
#define AVLNODE_H 1
#include <iostream>
#include <string>

using namespace std;

template<class Comparable>
class AvlTree{
public:
  AvlTree():root(NULL){};
  AvlTree(const AvlTree& rhs);
 ~AvlTree();

//  const Comparable& findMin()const;
//  const Comparable& findMax()const;
//  bool contains(const Comparable& x)const;
  bool isEmpty()const;
  void printTree()const;

  void makeEmpty();
  void insert(const Comparable& x);
  void remove(const Comparable& x);

  //const AvlTree& operator=(const AvlTree& rhs);

  struct AvlNode{
    Comparable element;	
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(const Comparable& theElement,AvlNode *lt,AvlNode *rt,int h = 0)
    :element(theElement),left(lt),right(rt),height(h){}
  };

  AvlNode *root;
  
  void insert(const Comparable& x,AvlNode* & t);
  int height(AvlNode* &);
  int max(int a,int b);
  void rotateWithLeftChild(AvlNode * & k);
  void rotateWithRightChild(AvlNode * & k);
  void doubleWithLeftChild(AvlNode * & K);
  void doubleWithRightChild(AvlNode * & k);
  void makeEmpty(AvlNode * & k);
  void printNode(AvlNode* const& k)const;
};
#endif

template<class Comparable>
  int AvlTree<Comparable>::height(AvlNode * & t){
    return t == NULL?-1:t->height;
}
 
template<class Comparable>
 void AvlTree<Comparable>::insert(const Comparable& x,AvlNode* & t){
  if(t == NULL)
    t = new AvlNode(x,NULL,NULL);
 else if(x < t->element){
    insert(x,t->left);
  if(height(t->left) - height(t->right) == 2)
    if(x < t->left->element)
      rotateWithLeftChild(t);
    else
      doubleWithLeftChild(t);
  }else if(t->element < x){
    insert(x,t->right);
  if(height(t->right) - height(t->left) == 2)
    if(t->right->element < x)
      rotateWithRightChild(t);
    else
      doubleWithRightChild(t);
  }else
    t->height = max(height(t->left),height(t->right)) +1;
}

template<class Comparable>
int AvlTree<Comparable>::max(int a,int b){
  return a > b?a:b;
}

template<class Comparable>
void AvlTree<Comparable>::rotateWithLeftChild(AvlNode * & k2){
  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left),height(k2->right))+1;
  k1->height = max(height(k1->left),height(k1->right))+1;
  k2= k1;  
}

template<class Comparable>
void AvlTree<Comparable>::rotateWithRightChild(AvlNode * & k2){
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left),height(k2->right))+1;
    k1->height = max(height(k1->left),height(k1->right))+1;
    k2= k1;
}

template<class Comparable>
void AvlTree<Comparable>::doubleWithLeftChild(AvlNode * & k3){
  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}

template<class Comparable>
void AvlTree<Comparable>::doubleWithRightChild(AvlNode * & k3){
  rotateWithLeftChild(k3->right);
  rotateWithRightChild(k3);
}

template<class Comparable>
void AvlTree<Comparable>::makeEmpty(AvlNode * & k){
  if(k != NULL){
    makeEmpty(k->left);
    makeEmpty(k->right);
    delete k;
  }
  k =NULL;
}

template<class Comparable>
void AvlTree<Comparable>::makeEmpty(){
  makeEmpty(root);
}

template<class Comparable>
void AvlTree<Comparable>::printNode(AvlNode* const & k)const{
  if(k != NULL){
    cout << k->element << " ";
    printNode(k->left);
    printNode(k->right);
  }
}

template<class Comparable>
void AvlTree<Comparable>::insert(const Comparable& x){
  insert(x,root);
}

template<class Comparable>
void AvlTree<Comparable>::printTree()const{
  printNode(root);
}

template<class Comparable>
AvlTree<Comparable>::~AvlTree(){
  makeEmpty(root);
}

template<class Comparable>
bool AvlTree<Comparable>::isEmpty()const{
  return root == NULL?true:false;
}

/*
AvlTree(const AvlTree& rhs){
  if(*this == rhs)
    return;
  makeEmpty(root);
}
*/


