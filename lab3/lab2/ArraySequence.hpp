#pragma once
#include"DynamicArray.hpp"
#include"Sequence.hpp"

template <class T>
class ArraySequence: public Sequence<T>
{
private:
	DynamicArray<T>* items;
	int count;
public:
	ArraySequence(int count = 0)
	{
		int actualCount;
		if (count > 0)
			actualCount = count;
		else
			actualCount = 1;
		this->items = new DynamicArray<T>(actualCount);
		for (size_t i = 0; i < actualCount; i++)
		{
			this->items->Set(i, {0});
		}
		this->count = count;
	}
	ArraySequence(DynamicArray<T>* items, int count)
	{
		this->count = count;
		this->items = new DynamicArray<T>(count);
		for (size_t i = 0; i < count; i++)
		{
			this->items->Set(items->Get(i));
		}

	};
	ArraySequence(const ArraySequence<T>& other) 
	{
		this->count = other->count;
		this->items = new DynamicArray<T>(other->items);
	};

public:
	virtual int GetLength() const override       
	{
		return this->items->GetSize();
	}
	virtual T GetFirst() const override
	{
		return this->items->Get(0);
	}
	virtual T GetLast() const override
	{	
		return this->items->Get(this->items->GetSize() - 1);
	}
	virtual T Get(const int index) const override
	{
		if (index < 0 || index >= this->count)
			throw std::exception("Index out of range ");
		return this->items->Get(index);
	} 
	virtual Sequence<T>* GetSubsequence(const int start, const int end)  override
	{	
		if (start < 0 || start >= this->count || end < 0 || end >= this->count)
			throw std::exception("Index out of range");
		ArraySequence<T>* SubItems;
		SubItems = new ArraySequence<T>(end - start + 1);
		size_t j = 0;
		for (size_t i = start; i <= end; i++)
		{
			SubItems->items->Set(j, this->items->Get(i));
			++j;
		}
		return SubItems;
	}
public:
	virtual void Append(T const value)  override
	{
		this->count++;
		DynamicArray<T>* itemstemp;
		itemstemp = new DynamicArray<T>(this->count);
		itemstemp->Set(0, value);
		for (size_t i = 1; i < this->count; i++)
		{
			itemstemp->Set(i, this->items->Get(i - 1));
		}
		delete this->items;
		this->items = itemstemp;
	}
	virtual void Prepend(T const value)  override
	{	
		this->count++;
		this->items->resize(GetLength() + 1);
		this->items->Set(this->count - 1, value);
	}
	virtual void InsertAt(const int index, T const value) override
	{	
		if (index < 0 || index >= this->count)
			throw std::exception("Index out of range ");
		DynamicArray<T>* itemstemp;
		itemstemp = new DynamicArray<T>(this->count);
		for (size_t i = 0; i < index ; i++)
		{
			itemstemp->Set(i,this->items->Get(i));
		}
		itemstemp->Set(index, value);
		for (size_t i = index; i < this->count - 1; i++)
		{
			itemstemp->Set(i,this->items->Get(i));
		}
		delete items;
		this->items = itemstemp;
		this->count++;
	}
	//////////////////////////////////////////////////////
	virtual void RemoveAt(int index)  override
	{
		if (index < 0 || index >= this->count)
			throw std::exception("Index out of range ");
		DynamicArray<T>* itemstemp;
		itemstemp = new DynamicArray<T>(this->count - 1);
		for (size_t i = 0; i < index ; i++)
		{
			itemstemp->Set(i, this->items->Get(i));
		}
		for (size_t i = index; i < count; i++)
		{
			itemstemp->Set(i, this->items->Get(i));
		}
		delete items;
		this->count--;
		this->items = itemstemp;
	}
	virtual void Remove(T value)  override
	{	
		int index;
		for (int i = 0; i < this->count; i++)
		{
			if (this->items->Get(i) == value)
			{
			    index = i;
				break;
			}
		}
		RemoveAt(index);
	}
	virtual void RemoveAll(T value)  override
	{
		int size = this->count;
		size_t j = 0;
		while (j < this->count)
		{
			if (this->items->Get(j) == value)
			{
				RemoveAt(j);
				j--;
			}
			j++;
		}
	}
	////////////////////////////////////////////////
	virtual Sequence<T>* Concat(Sequence<T>* other) override
	{
	    ArraySequence<T>* itemsconcat;
		itemsconcat = new ArraySequence<T>(this->count + other->GetLength());
		for (size_t i = 0; i < this->count; i++)
		{	
			itemsconcat->items->Set(i, this->items->Get(i));
		}
		for (size_t i = 0; i < other->GetLength(); i++)
		{
			itemsconcat->items->Set(this->count + i,other->Get(i));
		}
		return itemsconcat;
	}
	virtual Sequence<T>* Copy()  override
	{
		ArraySequence<T>* copyitems;
		copyitems = new ArraySequence<T>(this->count);
		for (size_t i = 0; i < this->count; i++)
		{
			copyitems->items->Set(i,this->items->Get(i));
		}
		return copyitems;
	}
	virtual Sequence<T>* CopyTo(Sequence<T>* target, int startIndex)  override
	{
		if (startIndex < 0 || startIndex > this->count)
			throw std::exception("Index out of range ");
		ArraySequence<T>* copyitems;
		copyitems = new ArraySequence<T>(target->GetLength() - startIndex + 1);
		int j = 0;
		for (size_t i = startIndex; i < target->GetLength() ; i++)
		{
			copyitems->items->Set(j, target->Get(i));
			j++;
		} 
		return copyitems;
		
	}
	~ArraySequence()
	{
		delete items;
	}
};
