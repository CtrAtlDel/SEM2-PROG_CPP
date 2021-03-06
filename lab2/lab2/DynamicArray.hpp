#pragma once 
template <class T>
class DynamicArray
{
private:
	T* arr;
	int size;
public:
	DynamicArray(T* items, const int size)
	{
		if (size < 0)
			throw std::exception("Size < 0");
		this->arr = new T[size];
		this->size = size;
		for (size_t i = 0; i < size; i++)
		{
			this->arr[i] = *(items + i);
		}
		
	}
	DynamicArray(const int size) 
	{
		if (size < 0)
			throw std::exception("Size < 0");
		this->arr = new T[size]; 
		this->size = size;
		for (size_t i = 0; i < size; i++)
		{
			this->arr[i] = { 0 };
		}

	}
	DynamicArray(const DynamicArray<T>& array) 
	{	
		this->size = array->GetSize();
		this->arr = new T[this->size];
		for (size_t i = 0; i < array->GetSize(); i++)
		{
			this->Set(array->Get(i));
		}
	}; //копирующий конструктор 
public:
	int GetSize() 
	{
		return this->size;
	}

	T Get(const int index)
	{
		if (index < 0 || index >= this->size)
			throw std::exception("Index out of range ");
		return this->arr[index];
	}

	void Set(int index, T value)
	{
		if (index < 0 || index >= this->size)
			throw std::exception("Index out of range ");
		this->arr[index] = value;
	}

	void resize(int newsize)
	{
		if (newsize < 0)
			throw std::exception("Size < 0");
		T* arrtemp = new T[newsize];
		if (newsize <= this->size)
		{
			for (size_t i = 0; i < newsize; i++)
			{
				arrtemp[i] = this->arr[i];
			}
			this->size = newsize;
			delete[] this->arr;
			this->arr = arrtemp;
		}
		else 
		{
			for (size_t i = 0; i < this->size; i++)
			{
				arrtemp[i] = this->arr[i];
			}
			for (size_t i = size; i < newsize; i++)
			{
				arrtemp[i] = {0};
			}

			this->size = newsize;
			delete[] this->arr;
			this->arr = arrtemp;
		}
		
	}

	~DynamicArray()
	{
		delete[] arr;
	}
};
