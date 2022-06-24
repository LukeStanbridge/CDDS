/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode(a_nValue);
	TreeNode* parentNode;

	if (IsEmpty()) 
	{	
		m_pRoot = newNode;
		return;
	}

	TreeNode* pCurrent = m_pRoot;
	parentNode = m_pRoot;

	while (pCurrent != NULL)
	{
		if (newNode->GetData() < pCurrent->GetData())
		{
			parentNode = pCurrent;
			pCurrent = pCurrent->GetLeft();
		}
		else if (newNode->GetData() > pCurrent->GetData())
		{
			parentNode = pCurrent;
			pCurrent = pCurrent->GetRight();
		}
		else if (newNode->GetData() == pCurrent->GetData())
		{
			return;
		}
	}

	if (newNode->GetData() < parentNode->GetData())
	{
		parentNode->SetLeft(newNode);
	}
	else if (newNode->GetData() > parentNode->GetData())
	{
		parentNode->SetRight(newNode);
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = nullptr;
	TreeNode* search = new TreeNode(a_nSearchValue);

	while (currentNode != NULL)
	{
		if (search == currentNode)
		{
			return currentNode && parentNode;
		}
		else if (search < currentNode)
		{
			parentNode = currentNode;
			currentNode = currentNode->GetLeft();
		}
		else
		{
			parentNode = currentNode;
			currentNode = currentNode->GetRight();
		}
	}

	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	/*if (m_pRoot == nullptr)
		return NULL;

	if (!m_pRoot->GetLeft() && !m_pRoot->GetRight())
	{
		if (m_pRoot->GetData() == a_nValue)
		{
			delete m_pRoot;
			m_pRoot = nullptr;
			return m_pRoot;
		}
		return m_pRoot;
	}

	queue<TreeNode*> Q;
	Q.push(m_pRoot);

	TreeNode* valNode = nullptr;
	TreeNode* current = nullptr;
	TreeNode* pl = nullptr;
	TreeNode* pr = nullptr;


	while (!Q.empty())
	{
		current = Q.front();
		Q.pop();

		if (current->GetData() == a_nValue)
		{
			valNode = current;
		}
		if (current->GetLeft())
		{
			Q.push(current->GetLeft());
			pl = current;
			pr = nullptr;
		}
		if (current->GetRight())
		{
			Q.push(current->GetRight());
			pr = current;
			pl = nullptr;
		}
	}

	if (valNode)
	{
		valNode->SetData(current->GetData());
		if (pl)
		{
			pl->SetLeft(nullptr);
		}
		if (pr)
		{
			pr->SetRight(nullptr);
		}
	}
	return m_pRoot;*/
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}