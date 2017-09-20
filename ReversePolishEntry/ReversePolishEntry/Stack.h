#pragma once

template <class T>
class Stack
{
	T *arr;
	const int size;
	int count;
public:
	Stack(int size) : size(size)
	{
		this->arr = new T[size];
		this->count = 0;
	}

	Stack(const Stack<T> &obj) : size(obj.size)
	{
		this->arr = obj.arr;
		this->count = obj.count;
	}

	~Stack()
	{
		delete[] this->arr;
	}

	//void push(T data); // Add last element
	//T pop(); // Remove last element
	//T peek(); // Select last element
	//bool isOverflow();
	//bool isEmpty();
	//int getCount();
	//int getSize();


	void  push(T data)
	{
		this->arr[this->count] = data;
		this->count++;
	}


	T  pop()
	{
		this->count--;
		return this->arr[count];
	}


	T  peek()
	{
		return this->arr[count - 1];
	}


	bool  isOverflow()
	{
		this->count == this->size ? return true : return false;
	}


	bool  isEmpty()
	{
		if (this->count == 0)
			return true;
		else
			return false;
	}


	int  getCount()
	{
		return this->count;
	}


	int  getSize()
	{
		return this->size;
	}

};