/*
 * AVLTree.hpp
 *
 *  Created on: Dec 1, 2018
 *      Author: patrickshannon
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include "NodeT.hpp"
#include <string>
using namespace std;

class AVLTree {
	NodeT *root;
	int size;
	friend class AC;


public:
	AVLTree() ;
	bool insertit(string x);
	bool insertit(string x, string y);
	void adjustHeights(NodeT *n);
	void printTreeIO();
	void printTreeIO(NodeT *n);
	void printTreePre();
	void printTreePre(NodeT *n);
	void printTreePost();
	void printTreePost(NodeT *n);
	void myPrint();
	void myPrint(NodeT *n);
	NodeT *find(string x);
	NodeT *rotateRight(NodeT *n);
	NodeT *rotateLeft(NodeT *n);
	int findBalance(NodeT *n);

// For Extra Credit
	void myPrintEC();
	void myPrintEC(NodeT *n);
	bool remove(string s);
	void remove1(NodeT *n);
	void remove2(NodeT *n);
	void remove3(NodeT *n);
	NodeT *findMin(NodeT *n);
};






#endif /* AVLTREE_HPP_ */
