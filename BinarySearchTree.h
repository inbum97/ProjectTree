// Binary Search Tree ADT
// Created by A. Student
// Modified by: <=============================== ADD YOUR NAME HERE

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE
#include "BinaryNode.h"
#include "BinaryTree.h"
#include "Armors.h"
using namespace std;
class BinarySearchTree : public BinaryTree
{
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode * _insert(BinaryNode* nodePtr, BinaryNode* newNode);

	// internal remove node: locate and delete target node under nodePtr subtree
	BinaryNode* _remove(BinaryNode* nodePtr, const Armors* target, bool & success);

	// delete target node from tree, called by internal remove node
	BinaryNode* deleteNode(BinaryNode* targetNodePtr);

	// remove the leftmost node in the left subtree of nodePtr
	BinaryNode* removeLeftmostNode(BinaryNode* nodePtr, Armors * successor);

	// search for target node
	BinaryNode* findNode(BinaryNode* treePtr, const Armors * target) const;



public:
	// insert a node at the correct location
	bool insert( Armors * newEntry);
	// remove a node if found
	//bool remove(const Armors * anEntry);
	// find a target node
	//bool getEntry(const Armors * target, Armors *& returnedItem)const;
	// destroy tree
	void destroyTree(BinaryNode *nptr);
	//Destructor
//	~BinarySearchTree();

};


///////////////////////// public function definitions ///////////////////////////
//Inserting items within a tree
bool BinarySearchTree::insert( Armors * newentry)
{
	BinaryNode* newnodeptr = new BinaryNode(newentry);;
	//cout << "Now Im calling _insert \n";

	this->rootPtr = _insert(this->rootPtr, newnodeptr);
	//cout << "***********Inserted\n";
	return true;
}

////Removing items within a tree
//bool BinarySearchTree::remove(const Armors * target)
//{
//	bool isSuccessful = false;
//	this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
//	return isSuccessful;
//}

//Finding entries within a tree
//bool BinarySearchTree::getEntry(const Armors *anEntry, Armors *& returnedItem) const
//{
//	bool isFound = false;
//	BinaryNode* item;
//	item = findNode(this->rootPtr, anEntry);
//	if (item != nullptr) {
//		isFound = true;
//		returnedItem = item->getItem();
//	}
//	return isFound;
//}



//////////////////////////// private functions ////////////////////////////////////////////
//Implementation of the insert operation
BinaryNode* BinarySearchTree::_insert(BinaryNode* nodePtr,
	BinaryNode* newNodePtr)
{
	//cout << "I am in _insert func \n";
	if (nodePtr == NULL) {
		//cout << "There is no node in tree \n";
		nodePtr = newNodePtr;
	}
	else {
		Armors* newItem = newNodePtr->getItem();
		Armors* rootItem = nodePtr->getItem();
		//cout << rootItem.getName() << endl;
		if (newItem->getCodeName() < rootItem->getCodeName()) {
			//cout << "I am going to the leftnode\n";
			nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr));
		}
		else {
			//cout << "I am going to the rightNode\n";
			nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr));
		}
	}
	//cout << "I am returning to insert\n";
	return nodePtr;
}

//Implementation of the remove operation
//BinaryNode* BinarySearchTree::_remove(BinaryNode* nodePtr,
//	const Armors * target,
//	bool & success)
//
//{
//	if (nodePtr == 0)
//	{
//		success = false;
//		return 0;
//	}
//	if (nodePtr->getItem() > target)
//		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
//	else if (nodePtr->getItem() < target)
//		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
//	else
//	{
//		nodePtr = deleteNode(nodePtr);
//		success = true;
//	}
//	return nodePtr;
//}
//Implementation of the delete operation
//BinaryNode* BinarySearchTree::deleteNode(BinaryNode* nodePtr)
//{
//	if (nodePtr->isLeaf())
//	{
//		delete nodePtr;
//		nodePtr = 0;
//		return nodePtr;
//	}
//	else if (nodePtr->getLeftPtr() == 0)
//	{
//		BinaryNode* nodeToConnectPtr = nodePtr->getRightPtr();
//		delete nodePtr;
//		nodePtr = 0;
//		return nodeToConnectPtr;
//	}
//	else if (nodePtr->getRightPtr() == 0)
//	{
//		BinaryNode* nodeToConnectPtr = nodePtr->getLeftPtr();
//		delete nodePtr;
//		nodePtr = 0;
//		return nodeToConnectPtr;
//	}
//	else
//	{
//		ItemType newNodeValue;
//		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
//		nodePtr->setItem(newNodeValue);
//		return nodePtr;
//	}
//}
//Implementation to remove the left leaf
//BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* nodePtr,
//	Armors * successor)
//{
//	if (nodePtr->getLeftPtr() == 0)
//	{
//		successor = nodePtr->getItem();
//		return deleteNode(nodePtr);
//	}
//	else
//	{
//		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
//		return nodePtr;
//	}
//}

//implementation for the search operation
//BinaryNode* BinarySearchTree::findNode(BinaryNode* nodeptr,
//	const itemtype * target)  const
//{
//	BinaryNode* found = nullptr;
//	BinaryNode* pWalk;
//	pWalk = nodeptr;
//	while (pWalk != NULL && pWalk != found) {
//		if (pWalk->getItem()<target)
//			pWalk = pWalk->getRightPtr();
//		else
//			if (pWalk->getItem() >target)
//				pWalk = pWalk->getLeftPtr();
//			else
//				found = pWalk;
//	}
//	return found;
//}

//Implementation of destroying tree
//void BinarySearchTree::destroyTree(BinaryNode* nodePtr) {
//	if (remove(nodePtr->getItem())) {
//		cout << "Destroying a node \n";
//		nodePtr = this->rootPtr;
//		if (nodePtr != nullptr)
//			destroyTree(nodePtr);
//	}
//}

//Destructor
//BinarySearchTree::~BinarySearchTree() {
//	destroyTree(this->rootPtr);
//}
#endif
#pragma once
