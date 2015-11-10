#ifndef _Array
#define _Array
#include <assert.h>
#include <algorithm>
template <class T>
class Array 
{
public:
	Array();
	Array(int n);
	~Array();
	
	T & getArray() const { return _array; }
	int length() const { return _length; }
	int size() const { return _size; }
	
	T & operator[](int index);
	const T & operator[](int index) const;
	Array<T> & operator=(Array<T> &other);
	
	const T & pop();
	const Array<T> & push(const T element);
	
	const T & shift();
	const Array<T> & unshift(const T element);
	
	const Array<T> & slice(int startIndex, int endIndex);
	const Array<T> & splice(int startIndex, unsigned int deleteCount);
	
	const Array<T> & reverse();
	
	void resize(int n);
	void clear();
	
	bool isEmpty() const;
private:
	static const int DEFAULT_SIZE;
	
	T *_array;
	int _length;
	int _size;
};
template <class T>
const int Array<T>::DEFAULT_SIZE = 10;
template <class T>
Array<T>::Array() 
{
	_array = new T[0];
	_length = 0;
	_size = 0;
}
template <class T>
Array<T>::Array(int n) 
{
	_array = new T[n];
	_length = 0;
	_size = n;
}
template <class T>
Array<T>::~Array() 
{
	delete[] _array;
	_array = NULL;
}
template <class T>
T & Array<T>::operator[](int index) 
{
	if (index >= _size) 
		resize(index + DEFAULT_SIZE);
	if (index > _length) 
		_length = index + 1;
	return *(_array + index);
}
template <class T>
const T & Array<T>::operator[](int index) const 
{
	assert(index > 0 && "Array<T>::operator[](int index) invalid index, must be >= 0");
	assert(index < _length && "Array<T>::operator[](int index) invalid index, must be < _length");
	return *(_array + index);
}
template <class T>
Array<T> & Array<T>::operator=(Array<T> &other) 
{
	if (this == &other)
		return *this;
	_length = other.length();
	_size = other.size();
	T *newArray = new T[_size];
	for (int i = 0; i < _length; i++) 
		newArray[i] = other[i];
	
	delete[] _array;
	_array = newArray;
	
	return *this;
}
template <class T>
const T & Array<T>::pop() 
{
	T *element = _array[_length - 1];
	splice(_length - 1, 1);
	return element;
}
template <class T>
const Array<T> & Array<T>::push(const T element) 
{
	if (_length >= _size) 
		resize(_length + DEFAULT_SIZE);
	_array[_length] = element;
	_length++;
	return *this;
}
template <class T>
const T & Array<T>::shift() 
{
	T *element = _array[0];
	splice(0, 1);
	return element;
}
template <class T>
const Array<T> & Array<T>::unshift(const T element) 
{
	if (_length >= _size) 
		resize(_length + DEFAULT_SIZE);
	T *newArray = new T[_size];
	newArray[0] = element;
	_length++;
	for (int i = 1; i < _length; i++)
		newArray[i] = _array[i - 1];
	delete[] _array;
	_array = newArray;
	return *this;
}
template <class T>
const Array<T> & Array<T>::slice(int startIndex = 0, int endIndex = 16777215) 
{
	if (startIndex < 0)
		startIndex = 0;
	if (endIndex > _length)
		endIndex = _length;
	Array<T> slice = new Array<T>(endIndex - startIndex);
	
	for (int i = 0; i < slice.size(); i++) 
		slice[i] = _array[startIndex + i];
	return slice;
}
template <class T>
const Array<T> & Array<T>::splice(int startIndex, unsigned int deleteCount) 
{
	if (startIndex < 0)
		startIndex = 0;
	if (deleteCount > _length - startIndex)
		deleteCount = _length - startIndex;
	T *newArray = new T[_size];
	for (int i = 0; i < startIndex; i++)
		newArray[i] = _array[i];
	for (int j = startIndex; j < _length - deleteCount; j++)
		newArray[j] = _array[j + deleteCount];
	delete[] _array;
	_array = newArray;
	_length -= deleteCount;
	return *this;
}
template <class T>
const Array<T> & Array<T>::reverse() 
{
	T *newArray = new T[_size];
	for (int = 0; i < _length; i++)
		newArray[i] = _array[_length - 1 - i];
	delete[] _array;
	_array = newArray;
	return *this;
}
template <class T>
void Array<T>::resize(int n) 
{
	if (_length > n)
		n = _length;
	T *newArray = new T[n];
	_size = n;
	for (int i = 0; i < _length; i++)
		newArray[i] = _array[i];
	//for (int j = _length; j < _size; j++)
		//newArray[j] = (*T)0;
	delete[] _array;
	_array = newArray;
}
template <class T>
void Array<T>::clear() 
{
	delete[] _array;
	_array = new T[_size];
	_length = 0;
}
template <class T>
bool Array<T>::isEmpty() const { return _length <= 0; }
#endif _Array