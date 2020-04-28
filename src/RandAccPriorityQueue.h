/*
 * PriorityQueue.h
 *
 *  Created on: Apr 25, 2020
 *      Author: vibhath
 */

#ifndef RANDACCPRIORITYQUEUE_H_
#define RANDACCPRIORITYQUEUE_H_

#include <vector>
#include "IndexOutOfBoundException.h"

template <class T, class CompClass>
class RandAccPriorityQueue
{
	public:
		typedef const T* iterator;


		/******************************************************************************************************
		* Func  : insert
		* Desc  : Inserts a new object into the queue. Position of the new object is decided according to the
		* 		  priority level.
		* Param : obj	- a reference to a new object to be inserted.
		* Ret   : None
		******************************************************************************************************/
		void insert(const T& obj);


		/******************************************************************************************************
		* Func  : get
		* Desc  : Returns a constant reference of the object in the specified index. Throws an
		* 		  IndexOutOfBoundException if the index doesn't exist.
		* Param : index	- index accessing
		* Ret   : A const reference of the object in the specified index.
		******************************************************************************************************/
		const T& get(unsigned int index);


		/******************************************************************************************************
		* Func  : operator[]
		* Desc  : Returns a reference of the object in the specified index. Throws an IndexOutOfBoundException
		* 		  if the index doesn't exist. Note that, position of object doesn't change, even the changes
		* 		  are made in the object.
		* Param : index	- index accessing
		* Ret   : A reference of the object in the specified index.
		******************************************************************************************************/
		T& operator[](unsigned int index);


		/******************************************************************************************************
		* Func  : size
		* Desc  : Returns the length of the queue.
		* Param : None
		* Ret   : size of the queue,
		******************************************************************************************************/
		size_t size();


		/******************************************************************************************************
		* Func  : indexOf
		* Desc  : Returns the index of the first occurrence of the specified object. 'equals' function is used
		* 		  to check the equality of the object with the objects in the queue.
		* Param : obj	- A reference of the object searching for.
		* Ret   : Index of the first occurrence of the specified object. Returns -1 if it doesn't exist.
		******************************************************************************************************/
		int indexOf(const T& obj);


		/******************************************************************************************************
		* Func  : erase
		* Desc  : Erases the specified object from the queue if exist. 'equals' function is used
		* 		  to check the equality of the object with the objects in the queue.
		* Param : obj	- A reference of the object searching for.
		* Ret   : Index of the deleted object. Returns -1 if it doesn't exist.
		******************************************************************************************************/
		int erase(const T& obj);


		/******************************************************************************************************
		* Func  : update
		* Desc  : Update the specified old object with the new object if exist. 'equals' function is used
		* 		  to check the equality of the old object with the objects in the queue.
		* Param : old_obj	- A reference of the old object
		* 		  new_obj	- A reference of the new object
		* Ret   : Index of the old object. Returns -1 if it doesn't exist and no update occurred.
		******************************************************************************************************/
		int update(const T& old_obj, const T& new_obj);


		/******************************************************************************************************
		* Func  : clear
		* Desc  : Clear all the elements in the queue.
		* Param : None
		* Ret   : None
		******************************************************************************************************/
		void clear();


		/******************************************************************************************************
		* Func  : front
		* Desc  : Returns a reference to the first element of the queue. Throws an IndexOutOfBoundException
		* 		  if the queue is empty.
		* Param : None
		* Ret   : const reference to the front element.
		******************************************************************************************************/
		const T& front();


		/******************************************************************************************************
		* Func  : back
		* Desc  : Returns a reference to the last element of the queue. Throws an IndexOutOfBoundException
		* 		  if the queue is empty.
		* Param : None
		* Ret   : const reference to the last element.
		******************************************************************************************************/
		const T& back();


		/******************************************************************************************************
		* Func  : pop_front
		* Desc  : Returns a copy of the first element of the queue while removing it. Throws an
		* 		  IndexOutOfBoundException if the queue is empty.
		* Param : None
		* Ret   : a copy the front element.
		******************************************************************************************************/
		const T pop_front();


		/******************************************************************************************************
		* Func  : pop_back
		* Desc  : Returns a copy of the last element of the queue while removing it. Throws an
		* 		  IndexOutOfBoundException if the queue is empty.
		* Param : None
		* Ret   : a copy the last element.
		******************************************************************************************************/
		const T pop_back();


		/******************************************************************************************************
		* Func  : begin
		* Desc  : Returns an iterator pointing to the beginning of the queue.
		* Param : None
		* Ret   : An iterator pointing to the beginning of the queue.
		******************************************************************************************************/
		iterator begin() const {return &vec[0];}


		/******************************************************************************************************
		* Func  : end
		* Desc  : Returns an iterator pointing to the end of the queue.
		* Param : None
		* Ret   : An iterator pointing to the end of the queue.
		******************************************************************************************************/
		iterator end() const {return &vec[vec.size()];}


	private:
		std::vector<T> vec;								//A vector to store objects.
		CompClass c;
		bool compare(const T& ob1, const T& ob2){return this->c.compare(ob1, ob2);}
		bool equals(const T& ob1, const T& ob2){return this->c.equals(ob1, ob2);}

		/******************************************************************************************************
		* Func  : getPriorityIndex
		* Desc  : Returns the index which the specified object should insert into the queue.
		* Param : obj	- a const reference of the object.
		* Ret   : The index which the specified object should insert into the queue
		******************************************************************************************************/
		int getPriorityIndex(const T& obj);
};


//--------------------------------------------Function Definitions---------------------------------------------------

template <class T, class CompClass>
void RandAccPriorityQueue<T, CompClass>::insert(const T& obj)
{
	int priority_index = this->getPriorityIndex(obj);
	typename std::vector<T>::iterator it = vec.begin();
	vec.insert(it+priority_index, obj);
}

template <class T, class CompClass>
const T& RandAccPriorityQueue<T, CompClass>::get(unsigned int index)
{
	return this->operator [](index);
}

template <class T, class CompClass>
T& RandAccPriorityQueue<T, CompClass>::operator[](unsigned int index)
{
	if(index < vec.size())
		return vec[index];
	else
	{
		IndexOutOfBoundException ex(index, vec.size());
		throw ex;
	}
}

template <class T, class CompClass>
size_t RandAccPriorityQueue<T, CompClass>::size()
{
	return vec.size();
}

template <class T, class CompClass>
int RandAccPriorityQueue<T, CompClass>::getPriorityIndex(const T& obj)
{
	if(vec.size() == 0)
	{
		return 0;
	}
	else if(vec.size() == 1)
	{
		if(this->compare(obj, vec[0]))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		int vec_size = vec.size();
		int start_ind = 0;
		int end_ind = vec_size-1;
		int ind;
		while(true)
		{
			ind = (start_ind + end_ind)/2;
			if(this->compare(obj, vec[ind]))
			{
				if(ind == 0 || this->compare(vec[ind-1], obj))
					return ind;
				else
				{
					end_ind = ind-1;
				}
			}
			else
			{
				if(ind == vec_size-1 || this->compare(obj, vec[ind+1]))
					return ind+1;
				else
				{
					start_ind = ind+1;
				}
			}
		}

	}
}

template <class T, class CompClass>
int RandAccPriorityQueue<T, CompClass>::indexOf(const T& obj)
{
	int vec_size = vec.size();
	for(int i = 0; i < vec_size; i++)
	{
		if(equals(obj, vec[i]))
		{
			return i;
		}
	}

	return -1;
}

template <class T, class CompClass>
int RandAccPriorityQueue<T, CompClass>::erase(const T& obj)
{
	int ind = this->indexOf(obj);
	if(ind > -1)
	{
		typename std::vector<T>::iterator it = vec.begin();
		vec.erase(it + ind);
	}
	return ind;
}

template <class T, class CompClass>
int RandAccPriorityQueue<T, CompClass>::update(const T& old_obj, const T& new_obj)
{
	int ind = this->erase(old_obj);
	if(ind > -1)
	{
		this->insert(new_obj);
	}
	return ind;
}

template <class T, class CompClass>
void RandAccPriorityQueue<T, CompClass>::clear()
{
	vec.clear();
}

template <class T, class CompClass>
const T& RandAccPriorityQueue<T, CompClass>::front()
{
	if(vec.empty())
	{
		IndexOutOfBoundException ex(0, 0);
		throw ex;
	}
	return vec.front();
}

template <class T, class CompClass>
const T& RandAccPriorityQueue<T, CompClass>::back()
{
	if(vec.empty())
	{
		IndexOutOfBoundException ex(0, 0);
		throw ex;
	}
	return vec.back();
}

template <class T, class CompClass>
const T RandAccPriorityQueue<T, CompClass>::pop_front()
{

	if(vec.empty())
	{
		IndexOutOfBoundException ex(0, 0);
		throw ex;
	}
	T ref = vec.front();
	this->erase(ref);
	return ref;
}

template <class T, class CompClass>
const T RandAccPriorityQueue<T, CompClass>::pop_back()
{
	if(vec.empty())
	{
		IndexOutOfBoundException ex(0, 0);
		throw ex;
	}
	T ref = vec.back();
	vec.pop_back();
	return ref;
}

#endif /* RANDACCPRIORITYQUEUE_H_ */
