/*
 * AVLTree.cpp
 *
 *  Created on: Dec 1, 2018
 *      Author: patrickshannon
 */

#include "AVLTree.hpp"


AVLTree::AVLTree() {
	root = NULL;
	size = 0;
}


bool AVLTree::insertit(string x) {
	bool insert = false; // initialize boolean to be returned later
	NodeT *tmp = new NodeT(x); // make a node with data value x
	if (root == NULL){
		root = tmp;
		cout << "new root set" << endl;
		adjustHeights(root);
		insert = true;
	}
	else{
		//cout << "entered else" << endl;
		NodeT *trav = root; // node used to traverse the tree and compare to tmp

		while (!insert){ //traverse tree condition
			//cout << "entered while" << endl;
			if(tmp->w < trav->w){ // tree traversal left
				//cout << "entered if 1" << endl;
				if(trav->left == NULL){ // insert condition
					//cout << "entered if 2" << endl;
					trav->left = tmp; // insert tmp
					tmp->parent = trav; // assign tmp a parent
					insert = true; // change the bool value to be returned
					//cout << "pre adjust heights" << endl;
					adjustHeights(tmp); // check the heights of nodes above tmp
					//cout << "post adjust heights" << endl;
				}
				else{ // if insert condition is false
					//cout << "entered else 2" << endl;
					trav = trav->left; // move the traversal node
				}
			}
			else{ // tree traversal right
				//cout << "entered else 1" << endl;
				if(trav->right == NULL){ // insert condition
					//cout << "entered if 3" << endl;
					trav->right = tmp; // insert tmp
					tmp->parent = trav; // make tmp point to a parent node
					insert = true; // change boolean to be returned
					//cout << "pre adjust heights" << endl;
					adjustHeights(tmp); // check the heights of nodes above tmp
					//cout << "post adjust heights" << endl;

				}
				else{ // if insert condition is false
					//cout << "entered else 3" << endl;
					trav = trav->right; // move the traversal node
				}
			}
		}
		//cout << "exit while" << endl;
	}
	return insert; // return the bool value
}

bool AVLTree::insertit(string x, string y){
	bool insert = false; // initialize boolean to be returned later
	NodeT *tmp = new NodeT(x); // make a node with data value x
	if (root == NULL){
		root = tmp;
		//cout << "new root set" << endl;
		adjustHeights(root);
		insert = true;
	}
	else{
		//cout << "entered else" << endl;
		NodeT *trav = root; // node used to traverse the tree and compare to tmp

		while (!insert){ //traverse tree condition
			//cout << "entered while" << endl;
			if(tmp->w->word < trav->w->word){ // tree traversal left
				//cout << "entered if 1" << endl;
				if(trav->left == NULL){ // insert condition
					//cout << "entered if 2" << endl;
					trav->left = tmp; // insert tmp
					tmp->parent = trav; // assign tmp a parent
					insert = true; // change the bool value to be returned
					//cout << "pre adjust heights" << endl;
					adjustHeights(tmp); // check the heights of nodes above tmp
					//cout << "post adjust heights" << endl;
				}
				else{ // if insert condition is false
					//cout << "entered else 2" << endl;
					trav = trav->left; // move the traversal node
				}
			}
			else{ // tree traversal right
				//cout << "entered else 1" << endl;
				if(trav->right == NULL){ // insert condition
					//cout << "entered if 3" << endl;
					trav->right = tmp; // insert tmp
					tmp->parent = trav; // make tmp point to a parent node
					insert = true; // change boolean to be returned
					//cout << "pre adjust heights" << endl;
					adjustHeights(tmp); // check the heights of nodes above tmp
					//cout << "post adjust heights" << endl;

				}
				else{ // if insert condition is false
					//cout << "entered else 3" << endl;
					trav = trav->right; // move the traversal node
				}
			}
		}
		//cout << "exit while" << endl;
	}
	return insert; // return the bool value
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have
// this working now.  It should be called whenever you change the height of a
// a particular node.  So, for instance, when a new node is inserted as a leaf,
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of
// the height of the left child and the height of the right child, plus 1).  If
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.


void AVLTree::adjustHeights(NodeT *n) {
	if((n->left == NULL) && (n->right == NULL)){
		cout << "entered if AH" << endl;
		/*
		 * this is the base case for the height of a node.
		 *
		 */
		n->height = 1;
	}
	else if ((n->right != NULL) && (n->left != NULL)){
		if (findBalance(n) > 1){
			if(findBalance(n->left) < 0){
				NodeT * tmp = n->left;
				n = rotateLeft(tmp);
				NodeT *oldn = n->left;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
			else{
				n = rotateRight(n);
				NodeT *oldn = n->right;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
		}
		else if (findBalance(n) < -1){
			if(findBalance(n->right) > 0){
				NodeT *tmp = n->right;
				n = rotateRight(tmp);
				NodeT *oldn = n->right;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
				cout << "done" << endl;
			}
			else{
				n = rotateLeft(n);
				NodeT *oldn = n->left;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
		}
		if(n->right != NULL && n->left != NULL){
			n->height = max(n->left->height, n->right->height) + 1;
		}
		else if(n->left == NULL){
			n->height = n->right->height + 1;
		}
		else{
			n->height = n->left->height + 1;
		}
	}
	else if (n->left != NULL){
		if(findBalance(n) > 1){
			if(findBalance(n->left) < 0){
				NodeT * tmp = n->left;
				n = rotateLeft(tmp);
				NodeT *oldn = n->left;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
			else{
				n = rotateRight(n);
				NodeT *oldn = n->right;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
		}
		n->height = n->left->height + 1;
	}
	else{
		if(findBalance(n) < -1){
			if(findBalance(n->right) > 0){
				NodeT *tmp = n->right;
				n = rotateRight(tmp);
				NodeT *oldn = n->right;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
			else{
				n = rotateLeft(n);
				NodeT *oldn = n->left;
				if(oldn->right == NULL && oldn->left == NULL){
					oldn->height = 1;
				}
				else if (oldn->right == NULL){
					oldn->height = oldn->left->height + 1;
				}
				else if (oldn->left == NULL){
					oldn->height = oldn->right->height + 1;
				}
				else{
					oldn->height = max(oldn->left->height, oldn->right->height) + 1;
				}
			}
		}
		n->height = n->right->height + 1;
	}
	cout << "assigned height " << n->w->word << ", " << n->height << endl;
	if(n->left != NULL){
		cout << n->left->w->word << " left" << endl;
	}
	if(n->right != NULL){
		cout << n->right->w->word << " right" << endl;
	}

	if(root == n){
		cout << "is root" << endl;
		size = root->height;
		n->parent = NULL;

	}
	else if(n->right != NULL && n->right->w->word == n->w->word){
		cout << n->w->word << ", " << n->right->w->word << endl;

	}
	else if (n->left != NULL && n->left->w->word == n->w->word){
		cout << n->w->word << ", " << n->left->w->word << endl;

	}
	else{
		cout << "testing parent" << endl;
		adjustHeights(n->parent);
	}
	cout << "finished" << endl;
}



void AVLTree::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is
// traversed in order
void AVLTree::printTreeIO(NodeT *n) {
	/*
	 * recursively finds the smallest value in the tree and traverses the tree in ascending order
	 */
	if (n->left != NULL){
		printTreeIO(n->left);
	}
	else{}
	n->printNode();
	if (n->right != NULL){
		printTreeIO(n->right);
	}
	else{}
}

void AVLTree::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void AVLTree::printTreePre(NodeT *n) {
	/*
	 * prints the data of the node then recursively traverses the tree to the left then right,
	 * each time printing the node n first. (i.e. the command printTreePre would yield
	 * root, root->left, root->left->left...(until all the values to the left of root have
	 * been printed), root->right, root->right->left ... (until all the values to the right
	 * of the root have been printed)
	 */
	n->printNode();
	if(n->left != NULL){
		printTreePre(n->left);
	}
	else{}
	if(n->right != NULL){
		printTreePre(n->right);
	}

}

void AVLTree::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void AVLTree::printTreePost(NodeT *n) {
	/*
	 * prints the tree from the bottom and moves up i.e. the first printed node will be the
	 * left most node at the leaf level and the last node printed will be the root
	 */
	if(n->left != NULL){
		printTreePost(n->left);
	}
	else{}
	if(n->right != NULL){
		printTreePost(n->right);
	}
	else{}
	n->printNode();
}


// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.
NodeT *AVLTree::find(string x) {
	//cout << "entered find" << endl;
	NodeT *tmp = root;
	int comp = 0;
	while(tmp != NULL){
		//cout << "entered while find" << endl;
		if(tmp->w->word == x){
			comp ++;
			return tmp;
		}
		else{
			if(x > tmp->w->word){
				tmp = tmp->right;
			}
			else{
				tmp = tmp->left;
			}
			comp += 2;
		}
	}
	return tmp;
}

int AVLTree::findBalance(NodeT *n){
	int lHeight;
	int rHeight;
	if (n->left == NULL){
		lHeight = 0;
	}
	else{
		lHeight = n->left->height;
	}
	if (n->right == NULL){
		rHeight = 0;
	}
	else{
		rHeight = n->right->height;
	}
	int balance = lHeight - rHeight;

	cout << n->w->word << " : node, " << balance << " : balance" << endl;
	return balance;
}


NodeT *AVLTree::rotateRight(NodeT *n){
	cout << "rotating right" << endl;
	n->printNode();
	NodeT *tmp = n->left;
	NodeT *tmp2 = tmp->right;
	tmp->parent = n->parent;
	n->parent = tmp;
	n->left = tmp2;
	if (tmp2 != NULL){
		tmp2->parent = n;
	}
	cout << "halfway through" << endl;
	tmp->right = n;
	if(tmp->parent == NULL){
		root = tmp;
	}
	else if(tmp->parent->right == n){
		tmp->parent->right = tmp;
	}
	else{
		tmp->parent->left = tmp;
	}
	cout << "done" << endl;
	return tmp;

}

NodeT *AVLTree::rotateLeft(NodeT *n){
	cout << "rotating left" << endl;
	n->printNode();
	NodeT *tmp = n->right;
	NodeT *tmp2 = tmp->left;
	tmp->parent = n->parent;
	n->parent = tmp;
	n->right = tmp2;
	if(tmp2 != NULL){
		tmp2->parent = n;
	}
	tmp->left = n;
	if(tmp->parent == NULL){
		root = tmp;
	}
	else if(tmp->parent->right == n){
		tmp->parent->right = tmp;
	}
	else{
		tmp->parent->left = tmp;
	}
	cout << "done" << endl;
	return tmp;
}



/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's
/* right child replaces the node.
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after
/* the replacing node is removed from its old location but before it is inserted into its
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes teh node, and returns
/* true if the removal was successful.
 */
bool AVLTree::remove(string s) {
	bool removed = false;
	NodeT *n = find(s);
	if (n->left  == NULL && n->right == NULL){
		remove1(n);
		cout << s << endl;
		removed = true;
	}
	else if (n->left == NULL || n->right == NULL){
		remove2(n);
		cout << s << endl;
		removed = true;
	}
	else{
		remove3(n);
		cout << s << endl;
		removed = true;

	}
	return removed;

}



/* remove1(): called when the node to be removed has no children. Takes as input the
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
 */
void AVLTree::remove1(NodeT *n) {
	if (n->parent->left == n){
		n->parent->left = NULL;
	}
	else if (n->parent->right == n){
		n->parent->right = NULL;
	}
	else{ //root case, n->parent  == NULL
	}
	adjustHeights(n->parent);
	delete n;

}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the
/* one child becomes the root.
 */
void AVLTree::remove2(NodeT *n) {
	if (n->parent->right == n){//checks n's relation to parent
		if (n->left == NULL){ //checks which of n's children is to be moved up;
			n->right->parent = n->parent;
			n->parent->right = n->right;
		}
		else{
			n->left->parent = n->parent;
			n->parent->right = n->left;
		}
	}
	else if (n->parent->left == n){
		if (n->left == NULL){ //checks which of n's children is to be moved up;
			n->right->parent = n->parent;
			n->parent->left = n->right;
		}
		else{
			n->left->parent = n->parent;
			n->parent->left = n->left;
		}
	}
	else{ // if n i the root, n->parent = NULL
		if (n->left == NULL){ //checks which of n's children is to be moved up;
			n->right->parent = NULL;
			root = n->right;
		}
		else{
			n->left->parent = NULL;
			root = n->left;
		}
	}
	adjustHeights(n->parent);
	delete n;
}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the
/* removed node's left child (and the child must point to the new node as a parent),
/* and the same for the right child.
/* Remember to take into account that the node being removed might be the root.
 */
void AVLTree::remove3(NodeT *n) {
	//cout << "enter rem3" << endl;
	NodeT *tmp = findMin(n);
	//cout << "found min" << endl;
	NodeT *tmp2 = new NodeT(tmp->w->word);

	if (tmp->right != NULL){
		//cout << "enter check remove min" << endl;
		remove2(tmp);
	}
	else{
		//cout << "enter check remove min" << endl;
		remove1(tmp);
	}

	if(n == root){
		//cout << "n is root" << endl;
		tmp2->parent = NULL;
		root = tmp2;
	}

	else{
		tmp2->parent = n->parent;
	}

	tmp2->left = n->left;
	//cout << "made tmp2's left" << endl;
	tmp2->right = n->right;
	//cout << "made tmp2's right" << endl;
	n->left->parent = tmp2;
	//cout << "made tmp2 a parent" << endl;
	n->right->parent = tmp2;
	//cout << "made tmp2 a parent" << endl;

	if (n->parent != NULL){
		if (n->parent->left == n){
			//cout << "enter last if" << endl;
			n->parent->left = tmp2;
		}
		else{
			//cout << "enter last else" << endl;
			n->parent->right = tmp2;
		}
	}


	//cout << "adjust heights" << endl;
	adjustHeights(tmp2);
	//cout << "heights adjusted" << endl;
	delete n;
}

/* findMin(): takes as input a node, and finds the left-most descendant of its
 *  right child.  The left-most descendant is returned.
 */
NodeT *AVLTree::findMin(NodeT *n) {
	NodeT *tmp = n->right;
	while (tmp->left != NULL){
		tmp = tmp->left;
	}
	return tmp;

}




/************************************************************************/

