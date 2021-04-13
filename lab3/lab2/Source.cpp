#include<iostream>
#include"Header.h"
#include"BinaryTreeNode.hpp"
using namespace std;
#define SIZE 6

int incr(int x)
{
	return x + 1;
}

int sum(int x, int y)
{
	return x + y;
}

bool Pos(int x) 
{
	if (x > 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main()
{	
	string string;

	BinaryTree<int>* tree;
	tree = new BinaryTree<int>();
	for (size_t i = SIZE; i > 0; i--)
	{
		tree->Insert(i);
	}

	BinaryTree<int>* trees;
	trees = new BinaryTree<int>();

	//cout << "This is find item 2 -> " << tree->FindNode(2) << endl; // it is work
	//cout << "This is root adress -> " << tree->GetRoot() << endl;
	//tree->Map(incr);
	//cout << "Example of empty tree" << endl;
	//trees->Map(incr);
	//trees = tree->ExtractSubtree(1);
	//cout << "0 is absent " << endl;
	//for (size_t i = 0; i < SIZE; i++)
	//{
	//	cout  << trees->ToPeek(i) << endl;
	//}
	//cout << "This is PeekSubTree (1 yes, 0 no) -> " << tree->ToPeekSubtree(trees) << endl;
	//cout << "This is remove -> " << tree->RemoveNode(3) << endl;
	//cout << "This is isEqual -> " << tree->IsEqual(trees)<< endl;
	//cout << "This is extract subtree(adress of the first item) -> " << tree->ExtractSubtree(2);
	
	//cout << "This is save to string -> " << tree->Thread("NLR");
	//cout << tree->Reduce(sum, 1, "NLR");
	cout << "This is toString" << tree->toString("NLR") << endl;

	return 0;
}