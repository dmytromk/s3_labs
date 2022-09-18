#pragma once

#include <iostream>

const int GLOBAL_CONST_ARR_SIZE = 100;

namespace array
{

	template <class T>
	struct List
	{
		T* array;
		int capacity;
		int head_idx;
		int tail_idx;
		List()
		{
			this->capacity = GLOBAL_CONST_ARR_SIZE;
			this->head_idx = 0;
			this->tail_idx = 0;
			this->array = new T;
		}
		~List()
		{
			delete[] array;
		}
		void changeCapacity(int var)
		{
			this->capacity = var;
		}
		bool empty()
		{
			return (this->tail_idx == 0);
		}
		void print()
		{
			for (int i = 0; i < this->capacity; i++)
				std::cout << this->array[i] << " ";
			std::cout << "\n\n";
		}
		bool overflow()
		{
			return (this->tail_idx == this->capacity - 1);
		}
		void pushFront(T add)
		{
			if (this->overflow())
				std::cout << "OVERFLOWING\n\n";
			else
			{
				this->tail_idx++;
				this->array[tail_idx] = add;
			}
		}
	};

	template <class T>
	struct Stack :
		virtual List<T>
	{
		using List<T>::List;
		T top()
		{
			if (!this->empty()) return this->array[this->tail_idx];
			else
			{
				std::cout << "This structure is empty.\n\n";
				return NULL;
			}
		}
		T popFront()
		{
			if (this->empty())
			{
				std::cout << "This struct is empty\n\n";
				return NULL;
			}

			else
			{
				T result = this->array[this->tail_idx];
				this->tail_idx--;
				return result;
			}
		}
	};

	template <class T>
	struct Queue :
		virtual List<T>
	{
		using List<T>::List;
		T back()
		{
			if (!this->empty()) return this->array[0];
			else
			{
				std::cout << "This structure is empty.\n\n";
				return nullptr;
			}
		}
		T popBack()
		{
			if (this->empty())
			{
				std::cout << "This struct is empty\n\n";
				return nullptr;
			}

			T result = this->array[0];
			for (int i = 0; i < this->tail_idx; i++)
				this->array[i] = this->array[i + 1];
			this->tail_idx--;
			return result;
		}
	};

	template <class T>
	struct Deque :
		Stack<T>, Queue<T>
	{
		void pushBack(T add)
		{
			if (this->overflow())
				std::cout << "OVERFLOWING\n\n";

			for (int i = this->tail_idx + 1; i > 0; i--)
				this->array[i] = this->array[i - 1];
			this->array[0] = add;
			this->tail_idx++;
		}
	};
}