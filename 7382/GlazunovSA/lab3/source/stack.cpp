#include <algorithm>// for exit
#include <iostream>
#include <cstring>//for memset
#define START_SIZE_OF_STACK 10
template <typename T>
class Mystack
{
public:
	Mystack(int); //these are public fields :)
	Mystack();
	~Mystack();
	bool is_empty();
	int size();
	T top();
	T pop();
	void push(T);

private:		//these are private
	T *array;
	int size_of_array,
		length;
	void resize();
};

template <typename T>
void Mystack<T>::resize(){										//this is stupid function in style C because we cant use vector!!!
																//this func increase array...					
	T* time_array = new T[size_of_array];						//in start we should copy memory from main array to time_array
	std::memcpy(time_array,array,( size_of_array )*sizeof(T));  //after we delete array and new array but buffer is bigger then last array
	delete []  array;											//and after we again copy memory but in another side
	array = new T[size_of_array + START_SIZE_OF_STACK ];		
	std::memcpy(array,time_array,( size_of_array )*sizeof(T));
	delete [] time_array;
	size_of_array += START_SIZE_OF_STACK;
}

template <typename T>
Mystack<T>::~Mystack()
{
	 delete [] array;    
}
template <typename T>
Mystack<T>::Mystack(int size)
{
    size_of_array = size > 0 ? size : START_SIZE_OF_STACK; //if size > 0 - it's,else size equal START_SIZE_OF_STACK
    array = new T[size_of_array]; 
    length = -1; 
}
template <typename T>
Mystack<T>::Mystack()
{
    size_of_array =  START_SIZE_OF_STACK; 
    array = new T[size_of_array]; 
    length = -1; 
}
template <typename T>
void Mystack<T>::push(T value)
{
	if(length==size_of_array-1)
	{
		resize();
	}
	array[++length]=value;//++ is prefix because in the beginning length == -1 and we cant use this like index of array
}
template <typename T>
bool Mystack<T>::is_empty()
{
	if(length<=-1)
		return true;
	return false;
}
template <typename T>
int Mystack<T>::size()
{
	return length;
}
template <typename T>
T Mystack<T>::top()
{
	if(!is_empty())
		return array[length];
	std::cout<<std::endl<<"ERROR!!!"<<std::endl;
	exit(0);
}
template <typename T>
T Mystack<T>::pop()
{
	T total=top();
	length--;
	return total;
}