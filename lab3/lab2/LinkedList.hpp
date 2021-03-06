#pragma once 
template <class T>
class LinkedList
{
private:
	template <class T>
	class Node   //???? ???????? 
	{
	public:
		T data;
		Node* pnext;
		Node(T data = T(), Node* pnext = nullptr)
		{
			this->data = data;
			this->pnext = pnext;
		}
	};
	int size;
	Node<T>* head;
public:
	LinkedList()
	{
		this->size = 0;
		head = nullptr;
	}
	LinkedList(T* items, int count)
	{	
		if (count < 0)
			throw std::exception("Size < 0");
		this->size = count;
		this->head = nullptr;
		T* ptemp;

		for (size_t i = 0; i < count; i++)
		{
			ptemp = &items[i];

			if (head == nullptr)
			{
				head = new Node<T>(*ptemp);
			}
			else
			{
				Node<T>* temp = head;
				while (temp->pnext != nullptr)
				{
					temp = temp->pnext;
				}
				temp->pnext = new Node<T>(*ptemp);
			}
		}
	}
	LinkedList(LinkedList<T>& other)
	{	
		this->head = nullptr;
		this->size = other->Getsize();
		for (size_t i = 0; i < other->Getsize(); i++)
		{
			this->Prepend(other->Get(i));
		}
	}
public:
	T& operator[](const int index)
	{
		if (index < 0 || index >= this->size)
			throw std::exception("index out of range ");
		int count = 0;
		Node<T>* temp = this->head;
		while (temp != nullptr)
		{
			if (count == index)
			{
				return temp->data;
			}
			temp = temp->pnext;
			count++;
		}
	}
	T Get(const int index)
	{
		//std ::cout << "it is index " << index <<std::endl;
		if (index < 0 || index >= this->size)
			throw std::exception("index out of range ");
		int count = 0;
		Node<T>* temp = this->head;
		while (temp != nullptr)
		{
			if (count == index)
			{
				return temp->data;
			}
			temp = temp->pnext;
			count++;
		}
	}
	T GetFirst()
	{
		return Get(0);
	}
	T GetLast()
	{
		return Get(this->size - 1);
	}
	int Getsize()
	{
		return this->size;
	}
	void Prepend(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* temp = head;
			while (temp->pnext != nullptr)
			{
				temp = temp->pnext;
			}
			temp->pnext = new Node<T>(data);
		}
		this->size++;
	}
	void Apend(T data)
	{
		this->head = new Node<T>(data, head);
		this->size++;
	}
	void InsertAt(T data, const int index)
	{	
		if (index < 0 || index >= this->size)
			throw std::exception("index out of range ");
		if (index == 0)
		{
			Apend(data);
		}
		else
		{
			Node<T>* previous = this->head;

			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->pnext;
			}
			Node<T>* newNode = new  Node<T>(data, previous->pnext);
			previous->pnext = newNode;
		}
		this->size++;
	}
	void PopFront()
	{

		Node<T>* temp =this->head;
		this->head =this->head->pnext;

		delete temp;

		this->size--;
		

	}
	void Remove(const int index)
	{
		if (index < 0 || index >= this->size)
			throw std::exception("Index out of range ");
		if (index == 0) 
		{
			PopFront();
		}
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1 ; i++)
			{
				previous = previous->pnext;
			}
			Node<T>* ToDelete = previous->pnext;
			previous->pnext = ToDelete->pnext;

			delete ToDelete;
			this->size--;
		}
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		if (startIndex < 0 || startIndex >= this->size || endIndex < 0 || endIndex >= this->size)
			throw std::exception("Index out of range ");
		T* arrtemp = new T[endIndex - startIndex + 1];
		LinkedList<T>* Sublist;
		Sublist = new LinkedList<T>();
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			arrtemp[i] = this->Get(startIndex + i);
		}
		for (int i = 0; i < endIndex - startIndex + 1; i++)
		{
			Sublist->Prepend(arrtemp[i]);
		}
		return Sublist;
	}

	~LinkedList() 
	{
		while (this->size)
		{
			PopFront();
		}
	}
};