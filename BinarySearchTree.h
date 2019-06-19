// Binary Search Tree ADT
// Created by A. Student
// Modified by: <=============================== BENNY TANDIO KUSUMA

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"
#include "Armors.h"

class BinarySearchTree : public BinaryTree
{
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode * _insert(BinaryNode* nodePtr, BinaryNode* newNode);
	BinaryNode* _insertSec(BinaryNode* nodePtr, BinaryNode* newNode);

	// internal remove node: locate and delete target node under nodePtr subtree
	BinaryNode* _remove(BinaryNode* nodePtr, Armors* target, bool& success);

	// delete target node from tree, called by internal remove node
	BinaryNode* deleteNode(BinaryNode* targetNodePtr);

	// remove the leftmost node in the left subtree of nodePtr
	BinaryNode* removeLeftmostNode(BinaryNode* nodePtr, Armors* successor);

	// search for target node
	BinaryNode* findNode(BinaryNode* treePtr, Armors* target) const;
	BinaryNode* findNodeSec(BinaryNode* treePtr, Armors* target, void visit(Armors*)) const;


public:
	// insert a node at the correct location
	bool insert(Armors* newEntry);
	bool insertSec(Armors* newEntry);
	// remove a node if found
	bool remove(Armors* anEntry);
	// find a target node
	bool getEntry(Armors* target, Armors*& returnedItem) const;
	bool getEntrySec(Armors* target, void visit(Armors*)) const;

};


///////////////////////// public function definitions ///////////////////////////
//Inserting items within a tree
bool BinarySearchTree::insert(Armors* newentry)
{
	//cout << "in insert func, Armors newentry:" << newentry->getCodename() << endl;
	BinaryNode* newnodeptr = new BinaryNode(newentry);
	//cout << "Now Im calling _insert \n";

	this->rootPtr = _insert(this->rootPtr, newnodeptr);
	//cout << "***********Inserted\n";
	return true;
}

//Inserting items within a tree
bool BinarySearchTree::insertSec(Armors* newentry)
{
	//cout << "in insert func, Armors newentry:" << newentry->getCodename() << endl;
	BinaryNode* newnodeptr = new BinaryNode(newentry);
	//cout << "Now Im calling _insert \n";

	this->rootPtr = _insertSec(this->rootPtr, newnodeptr);
	//cout << "***********Inserted\n";
	return true;
}

//Removing items within a tree
bool BinarySearchTree::remove(Armors* target)
{
	bool isSuccessful = false;
	this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
	return isSuccessful;
}


//Finding entries within a tree
bool BinarySearchTree::getEntry(Armors* anEntry, Armors*& returnedItem) const
{
	BinaryNode* newNodePtr = findNode(this->rootPtr, anEntry);

	//cout << "A2 : " << anEntry->getCodename() << endl;
	//cout << "A1 : " << returnedItem->getCodename() << endl;

	if (newNodePtr != NULL)
	{
		returnedItem = newNodePtr->getItem();
		return true;
	}
	return false;
}

//Finding entries within a tree
bool BinarySearchTree::getEntrySec(Armors* anEntry, void visit(Armors*)) const
{
	BinaryNode* newNodePtr = findNodeSec(this->rootPtr, anEntry, visit);

	//cout << "A2 : " << anEntry->getCodename() << endl;
	//cout << "A1 : " << returnedItem->getCodename() << endl;

	if (newNodePtr != NULL)
	{
		//returnedItem = newNodePtr->getItem();
		return true;
	}
	return false;
}


//////////////////////////// private functions ////////////////////////////////////////////
//Implementation of the insert operation
BinaryNode* BinarySearchTree::_insert(BinaryNode* nodePtr,
	BinaryNode* newNodePtr)
{
	//cout << "I am in _insert func \n";
	//cout << "nodePtr : " << nodePtr->getItem()->getCodename() << endl;

	if (nodePtr == NULL) {
		//cout << "There is no node in tree \n";
		nodePtr = newNodePtr;
	}
	else {
		Armors* newItem = newNodePtr->getItem();
		Armors* rootItem = nodePtr->getItem();

		//cout << "newItem : " << newItem->getCodename() << endl;
		//cout << "rooItem : " <<rootItem->getCodename() << endl;
		if (newItem->getCodename() < rootItem->getCodename()) {
			//cout << newItem->getCodename() << " going to the leftnode\n";
			nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr));
		}
		else {
			//cout << newItem->getCodename() << " going to the rightnode\n";
			nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr));
		}
	}
	//cout << "I am returning to insert\n";
	return nodePtr;
}

//Implementation of the insert operation
BinaryNode* BinarySearchTree::_insertSec(BinaryNode* nodePtr,
	BinaryNode* newNodePtr)
{
	cout << "I am in _insertSec func \n";
	//cout << "nodePtr : " << nodePtr->getItem()->getCodename() << endl;

	if (nodePtr == NULL) {
		cout << "There is no node in tree so I'll add \n";// <<nodePtr->getItem()->getArmorType()<<endl;
		nodePtr = newNodePtr;
	}
	else {
		Armors* newItem = newNodePtr->getItem();
		Armors* rootItem = nodePtr->getItem();

		cout << "newItem : " << newItem->getCodename() << endl;
		cout << "rooItem : " <<rootItem->getCodename() << endl;
		if (newItem->getArmorType() < rootItem->getArmorType()) {
			cout << newItem->getArmorType() << " going to the leftnode\n";
			nodePtr->setLeftPtr(_insertSec(nodePtr->getLeftPtr(), newNodePtr));
		}
		else if (newItem->getArmorType() > rootItem->getArmorType()) {
			cout << newItem->getArmorType() << " going to the rightnode\n";
			nodePtr->setRightPtr(_insertSec(nodePtr->getRightPtr(), newNodePtr));
		}
		else if(newItem->getArmorType() == rootItem->getArmorType()){
			cout << newItem->getArmorType() << " going to the rightnode cuz duplicate\n";
			nodePtr->setRightPtr(_insertSec(nodePtr->getRightPtr(), newNodePtr));
		}
	}
	//cout << "I am returning to insert\n";
	return nodePtr;
}

//Implementation of the remove operation
BinaryNode* BinarySearchTree::_remove(BinaryNode* nodePtr,
	Armors* target,
	bool& success)

{
	Armors* rootItem = nodePtr->getItem();
	cout << endl;
	if (nodePtr == 0)
	{
		success = false;
		return 0;
	}
	if (rootItem->getCodename() > target->getCodename())
	{
		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));

	}
	else if (rootItem->getCodename() < target->getCodename())
	{
		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
	}
	else
	{

		nodePtr = deleteNode(nodePtr);

		success = true;
	}
	return nodePtr;
}

//Implementation of the delete operation
BinaryNode* BinarySearchTree::deleteNode(BinaryNode* nodePtr)
{
	if (nodePtr->isLeaf())
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)
	{
		BinaryNode* nodeToConnectPtr = nodePtr->getRightPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0)
	{
		BinaryNode* nodeToConnectPtr = nodePtr->getLeftPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else
	{
		Armors* newNodeValue;
		newNodeValue = new Armors;
		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}
}


//Implementation to remove the left leaf
BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* nodePtr,
	Armors* successor)
{
	if (nodePtr->getLeftPtr() == 0)
	{
		successor = nodePtr->getItem();
		return deleteNode(nodePtr);
	}
	else
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}
}


//Implementation for the search operation
BinaryNode* BinarySearchTree::findNode(BinaryNode* nodePtr,
	Armors* target) const
{
	Armors* rootItem = nodePtr->getItem();
	//cout << "rooitem : " << rootItem->getCodename() << endl;
	//cout<<endl;
	while (nodePtr != NULL)
	{
		if (target->getCodename() < rootItem->getCodename())
		{
			
			nodePtr = nodePtr->getLeftPtr();
			if (nodePtr == 0) { break; }
			rootItem = nodePtr->getItem();

			//cout << "1.1rooitem : " << rootItem->getCodename() << endl;
			//cout<<endl;
		}
		else {
			if (target->getCodename() > rootItem->getCodename())
			{
				//cout << "2target : " << target->getCodename() << endl;
				//cout << "2rooitem : " << rootItem->getCodename() << endl;
				nodePtr = nodePtr->getRightPtr();
				if (nodePtr == 0) { break; }
				rootItem = nodePtr->getItem();
				//cout << "2.2rooitem : " << rootItem->getCodename() << endl;
				//cout<<endl;
			}
			else {
				//cout << "3rooitem : " << rootItem->getCodename() << endl;

				return nodePtr;
			}
		}
	}
	return 0;
}


//Implementation for the search operation
BinaryNode* BinarySearchTree::findNodeSec(BinaryNode* nodePtr,
	Armors* target, void visit(Armors*)) const
{
	BinaryNode* found = nullptr;
	BinaryNode* pWalk;
	pWalk = nodePtr;

	while (pWalk != NULL && pWalk!=found)
	{
		if (target->getArmorType() < pWalk->getItem()->getArmorType())
		{

			pWalk = pWalk->getLeftPtr();
			
		}
		else {
			if (target->getArmorType() > pWalk->getItem()->getArmorType())
			{
				pWalk = pWalk->getRightPtr();
			}
			else {
				cout << "Found it\n";
				found = pWalk;
				visit(found->getItem());
				if (found != NULL)
					findNodeSec(pWalk->getRightPtr(), target, visit);

			}
			return found;

		}
	}
}

/*

BinaryNode<itemtype>* BinarySearchTree<itemtype>::findNode(BinaryNode<itemtype>* nodeptr,
const itemtype & target)  const
{
BinaryNode<itemtype>* found = nullptr;
BinaryNode<itemtype>* pWalk;
pWalk = nodeptr;
while (pWalk != NULL && pWalk!=found) {
if (pWalk->getItem()<target)
pWalk=pWalk->getRightPtr();
else
if (pWalk->getItem() >target)
pWalk=pWalk->getLeftPtr();
else {
found = pWalk;
visit(found);
findNode(found, target);
}
}
return found;
}

*/
//}



#endif