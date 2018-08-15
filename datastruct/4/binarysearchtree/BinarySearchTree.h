#ifndef BIARYSEARCHTREE
#define BIARYSEARCHTREE 1
#include <iostream>
#include <string>

using namespace std;

template<class Comparable>
class BinarySearchTree{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& rhs);
 ~BinarySearchTree();

  const Comparable& findMin()const;
  const Comparable& findMax()const;
  bool contains(const Comparable& x)const;
  bool isEmpty()const;
  void printTree()const;

  void makeEmpty();
  void insert(const Comparable& x);
  void remove(const Comparable& x);

  const BinarySearchTree& operator=(const BinarySearchTree& rhs);

//private:
//  typedef BinaryNode BinaryNod;
  struct BinaryNode{
    Comparable element;	
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const Comparable& theElement,BinaryNode *lt,BinaryNode *rt)
    :element(theElement),left(lt),right(rt){}
  };

  BinaryNode *root;

  void insert(const Comparable& x,BinaryNode * &t);
  void remove(const Comparable& x,BinaryNode * &t);
  const BinaryNode * findMin(BinaryNode* const&t)const;
  const BinaryNode * findMax(BinaryNode * const&t)const;
  bool contains(const Comparable& x,BinaryNode * &t)const;
  void makeEmpty(BinaryNode* &t);
  void printTree(const BinaryNode* const&t)const;
  BinaryNode* clone(BinaryNode *t)const;

};

#endif
