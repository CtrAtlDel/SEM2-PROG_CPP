#pragma once
#include"Header.h"
using namespace std;
template<class T>
class BinaryTree
{
public:
	template<class T>
	class TreeNode
	{
	public:
		T data;
		TreeNode* left;
		TreeNode* right;
	public:
		TreeNode(T value)
		{
			this->data = value;
			this->left = nullptr;
			this->right = nullptr;
		}
	public:
		T Getdata()
		{
			return this->data;
		}
		void Printdata()
		{
			std::cout << "Data -> " << this->data << std::endl;
		}
	};
	TreeNode<T>* root;//корешок
public:
	static Sequence<TreeNode<T>*>* Thread(TreeNode<T>* Node, std::string other)// Прошивка 
	{
		Sequence<TreeNode<T>*>* list = nullptr;
		TreeNode<T>** array;
		for (size_t i = 0; i < other.length(); i++)
		{
			switch (other[i])
			{

			case 'N':
				if (list == nullptr) 
				{
					list = new ListSequence<TreeNode<T>*>();
					list->Prepend(Node);
				}
				else 
				{
					Sequence<TreeNode<T>*>* list1 = nullptr;
					list1 = new ListSequence<TreeNode<T>*>();
					list1->Prepend(Node);
					
					list = list->Concat(list1);
				}
				//cout << "Size " << list->GetLength() << endl;
				break;

			case 'R':
				if (Node->right != nullptr)
				{
					if (list == nullptr)
					{
						list = Thread(Node->right, other);
					}
					else
					{
						list = list->Concat(Thread(Node->right, other));
						cout << list->GetLength() << endl;
					}
					//cout << "Size " << list->GetLength() << endl;
				}

				break;

			case 'L':
				if (Node->left != nullptr)
				{
					if (list == nullptr)
					{
						list = Thread(Node->left, other);
					}
					else
					{
						 list = list->Concat(Thread(Node->left, other));
						 cout << list->GetLength() << endl;
					}
					//cout << "Size " << list->GetLength() << endl;
				}

				break;

			}
		}
		//cout << "Size of Thread " << list->GetLength() << endl;
		return list;
	}

public:
	BinaryTree()
	{
		this->root = nullptr;
	}

	BinaryTree(TreeNode<T>* root)
	{
		this->root = root;
	}

	TreeNode<T>* GetRoot()
	{
		return this->root;
	}

	void SwapRight(TreeNode<T>* Node)
	{
		TreeNode<T>* temp;
		temp = Node->right;
		Node->right = Node->left;
		Node->left = temp;
	}

	void SwapLeft(TreeNode<T>* Node)
	{
		TreeNode<T>* temp;
		temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}

	TreeNode<T>* FindNode(TreeNode<T>* Node, T value) // Поиск
	{
		if (this->root == nullptr)
			throw std::exception("Tree is empty");
		if (Node->data == value)
		{
			return Node;
		}
		else
		{
			if (value < Node->data)
			{
				return FindNode(Node->left, value);
			}
			else
			{
				return FindNode(Node->right, value);
			}
		}
	}

	TreeNode<T>* FindNode(T value) 
	{
		return FindNode(this->root, value);
	}

	void Insert(T val) // Вставка
	{
		if (this->ToPeek(val)) {
		}
		TreeNode<T>* newnode = new TreeNode<T>(val);
		TreeNode<T>* ptr = this->root;
		TreeNode<T>* ptr1 = nullptr;

		while (ptr != nullptr) {
			ptr1 = ptr;
			if (val < ptr->Getdata()) {
				ptr = ptr->left;
			}
			else {
				ptr = ptr->right;
			}
		}

		if (ptr1 == nullptr) {
			this->root = newnode;
		}
		else {
			if (val < ptr1->Getdata()) {
				ptr1->left = newnode;
			}
			else {
				ptr1->right = newnode;
			}
		}	
	}

	bool RemoveNode(T value)
	{
		return RemoveNode(this->root,value);
	}

	bool RemoveNode(TreeNode<T>* Node, T value) //Удаление узла 1 удаление произошло, 0 нет
	{

		if (Node == nullptr)
		{
			return false;
		}
			
		bool where;
		TreeNode<T>* temp = Node;
		TreeNode<T>* temp1 = nullptr;

		if (temp->left == nullptr && temp->right == nullptr)
		{
			if (temp->data == value)
			{
				delete temp;
				return true;
			}
			else 
			{
				return false;
			}
		}
		while (temp != nullptr && temp->data != value)
		{
			if (value < temp->data)
			{
				where = false;
				temp1 = temp;
				temp = temp->left;
			}
			else
			{
				if (value > temp->data)
				{
					where = true;
					temp1 = temp;
					temp = temp->right;
				}
			}
		}
		if (temp == nullptr)
		{
			std::cout << "Your tree is empty" << std::endl;
			return false;
		}
		else
		{
			if (temp->right == nullptr && temp->left == nullptr) 
			{
				if (!where)
				{
					temp1->left = nullptr;
				}
				else
				{
					temp1->right = nullptr;
				}
				delete temp;
				return true;
			}
			else
			{
				if (temp->right != nullptr && temp->left == nullptr) 
				{
					if (temp1->left == temp) 
					{
						temp1->left = temp->right;
					}
					else 
					{
						temp1->right = temp->right;
					}
					delete temp;
					return true;
				}
				else
				{
					if (temp->left != nullptr && temp->right == nullptr)
					{
						if (temp1->left == temp)
						{
							temp1->left = temp->left;
						}
						else
						{
							temp1->right = temp->left;
						}
						delete temp;
						return true;
					}
					else
					{
						if (temp->left != nullptr && temp->right != nullptr)
						{
							TreeNode<T>* temp2 = nullptr;
							temp1 = temp;
							temp2 = temp;
							where = true;
							temp = temp->right;
							while (temp->left != nullptr)
							{
								temp2 = temp;
								where = false;
								temp = temp->left;
							}
							temp1->data = temp->data;

							if (temp->right != nullptr)
							{
								if (where)
								{
									temp2->right = temp->right;
								}
								else
								{
									temp2->left = temp->right;
								}

								delete temp;
								return true;
							}
							else
							{
								if (where)
								{
									temp2->right = nullptr;
								}
								else
								{
									temp2->left = nullptr;
								}

								delete temp;
								return true;
							}
						}
					}
				}
			}
		}
	}



	void Map(T (*foo)(T), TreeNode<T>* Node)
	{
		Node->data = foo(Node->data);
		if (Node->left != nullptr)
		{
			Map(foo, Node->left);
		}
		else
			if (Node->right != nullptr)
			{
				Map(foo, Node->right);
			}
	}

	void Map(T (*foo)(T))
	{	
		if (this->root == nullptr)
		{
			cout << "This tree is empty" << endl;
		}
		else 
		{
			this->Map(foo, this->root);
		}

	}

	T Reduce(T (*foo)(T, T), T start, std::string other) {
		if (this->root == nullptr)
			throw std::exception("Tree is empty");
		
		Sequence<TreeNode<T>*>* ThreadTree = this->Thread(other);
		T result;

		for (int i = 0; i < ThreadTree->GetLength(); i++) 
		{
			if (i == 0) 
			{
				result = foo(ThreadTree->Get(i)->Getdata(), start);
			}
			else 
			{
				result = foo(ThreadTree->Get(i)->Getdata(), result);
			}
		}

		return result;
	}

	static int height(TreeNode<T>* node) //Вес
	{
		int L;
		int R;
		if (node->left == nullptr && node->right == nullptr) 
		{
			return 0;
		}
		else 
		{
			if (node->left != nullptr) 
			{
				L = height(node->left) + 1;
			}
			else 
			{
				L = 0;
			}
			if (node->right != nullptr) 
			{
				R = height(node->right) + 1;
			}
			else 
			{
				R = 0;
			}
		}
		if (L > R) 
		{
			return L;
		}
		else 
		{
			return R;
		}
	}

	int height() 
	{
		return height(this->root);
	}

	BinaryTree<T>* ExtractSubtree(T value) //Поддерево
	{
		TreeNode<T>* tempnode = this->FindNode(value);
		BinaryTree<T>* newTree = new BinaryTree<T>(tempnode);

		return newTree;
	}

	bool ToPeek(T value) //Подсмотреть 
	{
		TreeNode<T>* temp = this->root;

		while (temp != nullptr)
		{
			if (value < temp->Getdata())
			{
				temp = temp->left;
			}
			else 
			{
				if (value > temp->Getdata()) 
				{
					temp = temp->right;
				}
				else 
				{
					return true;
				}
			}
		}

		if (temp == nullptr) 
		{
			return false;
		}
	}

	bool ToPeekSubtree(BinaryTree<T>* subtree) //Поиск поддерева
	{	
		if (subtree->GetRoot() == nullptr && this->GetRoot() != nullptr) 
		{
			return false;
		}
		if (subtree->GetRoot() == this->GetRoot())
		{
			return 1;
		}
		if (this->ToPeek(subtree->GetRoot()->data))
		{
			BinaryTree<T>* checkingTree = this->ExtractSubtree(subtree->GetRoot()->data);
			return checkingTree->IsEqual(subtree); 
		}
		else
		{
			return false;
		}
	}

	bool IsEqual(BinaryTree<T>* tree) //Проверка на равенства исходного дерева и принятого
	{
		if ((this->root != nullptr && tree->GetRoot() == nullptr) || (this->root == nullptr && tree->GetRoot() != nullptr))
		{
			return false;
		}
		if (this->root == nullptr && tree->GetRoot() == nullptr) 
		{
			return true;
		}
		bool res = true;
		TreeNode<T>* ThisRight = this->root->right;
		TreeNode<T>* ThisLeft = this->root->left;
		TreeNode<T>* TreeRight = tree->GetRoot()->right;
		TreeNode<T>* TreeLeft = tree->GetRoot()->left;

		if (ThisLeft != nullptr && ThisRight != nullptr) 
		{
			res = res && this->ExtractSubtree(ThisLeft->data)->IsEqual(tree->ExtractSubtree(TreeLeft->data));
		}
		else if (TreeLeft == nullptr && TreeRight == nullptr) {}
		else 
		{
			return false;
		}

		if (ThisRight != nullptr && TreeLeft != nullptr) 
		{
			res = res && this->ExtractSubtree(ThisRight->data)->IsEqual(tree->ExtractSubtree(TreeRight->data));
		}
		else if (ThisLeft == nullptr && ThisRight == nullptr) {}
		else 
		{
			return false;
		}

		return res;
	}

	std::string toString(std::string order) //Сохранение в строку
	{
		std::string result;

		Sequence<TreeNode<T>*>* threadtree = this->Thread(order);
		if (this->root == nullptr)
		{
			std::cout << "Tree is empty" << std::endl;
			throw std::exception("empty");
		}

		for (int i = 0; i < threadtree->GetLength(); i++) 
		{
			if (i == 0) 
			{
				result += std::to_string(threadtree->Get(i)->data) + " ";
			}
			else 
			{
				result += "-> " + std::to_string(threadtree->Get(i)->data) + " ";
			}
		}

		return result;
	}

	Sequence<TreeNode<T>*>* Thread(std::string other) 
	{
		return Thread(this->root, other);
	}

};