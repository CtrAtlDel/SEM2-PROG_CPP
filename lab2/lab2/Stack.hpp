#pragma once
#include"Header.h"
template<class T>
class Stack
{
private:
	Sequence<T>* items;
	int size = 0;
public:
	Stack() 
	{
		this->items = new ListSequence<T>();
	}
	Stack(const T* items, const int count) 
	{
		if (count < 0)
			throw std::exception("Size < 0");
		this->size = count;
		for (size_t i = 0; i < count; i++)
		{
			this->items->Prepend(*(items + i));
		}
	}
	Stack(Sequence<T>* items)//копирующий конструктор 
	{
		this->items = new ListSequence<T>();
		for (int i = 0; i < items->GetLength(); i++)
			this->items->Append(items->Get(i));//потому что стэк 
	}
	Stack(Stack<T>& other)
	{
		this->items = new ListSequence<T>(other->GetLength());
		for (int i = 0; i < items->GetLength(); i++)
			this->items->Append(other->Get(i));//потому что стэк 
	}
private:
	T Get(const int index)
	{
		return this->items->Get(index);
	}
public:
	int GetLength()
	{
		return this->items->GetLength();
	}
	Stack<T>* Concatination(Stack<T>* target)
	{	
		Stack<T>* stacktemp = new Stack<T>();
		//this->items->Concat(target->items);
		stacktemp->items = this->items->Concat(target->items);
		return stacktemp;
	}
	void Overfoo(T(*foo)(T))
	{	
		for (size_t i = 0; i < this->GetLenght(); i++)
		{
			this->items->Append(foo(this->items->Get(i)));
		}
	}
	T Top()
	{
		return this->items->GetFirst();
	}
	void Pop()
	{
		this->items->RemoveAt(0);
	}
	Stack<T>* Map(T (*foo)(T))
	{
		Stack<T>* stacktemp = new Stack<T>();
		int size = this->GetLength();
		for (size_t i = 0; i < size; i++)
		{
			stacktemp->items->Prepend(foo(this->items->Get(i)));
		}
		return stacktemp;
	}
	Stack<T>* GetSubsequence(const int start, const int end)
	{
		if (start < 0 || start >= this->size || end < 0 || end >= this->size)
			throw std::exception("Index out of range ");
		Stack<T>* stacktemp = new Stack<T>();
		stacktemp->items = this->items->GetSubsequence(start, end);
		stacktemp->size = start - end + 1;
		return stacktemp;
	}
	Stack<T>* Where(bool (*foo)(T)) 
	{	
		int size = this->GetLength();
		Stack<T>* whereitems;
		whereitems = new Stack<T>();
		for (size_t i = 0; i < size ; i++)
		{
			if (foo(this->Get(i)) == 1)
			{
				whereitems->items->Prepend(this->Get(i));
			}
		}
		return whereitems;
	}
	void Set(T item)
	{
		this->items->Append(item);
		this->size++;
	}
	int Search(Stack<T>* target) 
	{	
		if (target->GetLength() > this->GetLength())
			throw std::exception("Search");
		for (int i = 0; i < this->GetLength()- target->GetLength() + 1; i++)
		{	
			if (this->Get(i) == target->Get(0))
			{
				if (this->GetLength() - i + 1 < target->GetLength())
				{
					std::cout << "No subsec"<< std::endl;
					return -1;
				}
				else
				{	
					int temp = 0;
					for (int j = 0; j < target->GetLength(); j++)
					{
						if ((this->GetSubsequence(i, target->GetLength() + i - 1))->Get(j) == target->Get(j))
						{
							temp++;
						}
						if (temp == target->GetLength())
						{
							return i;
						}
					}
				}
			}
			//std::cout << this->GetLength() - target->GetLength() + 1 << std::endl;
			if (i == this->GetLength() - target->GetLength())
			{
				return -1;
			}
			
		}

		
	}
	~Stack()
	{	
		int i = 0;
		while (this->size)
		{
			this->Pop();
			this->size--;
		}
	}
};