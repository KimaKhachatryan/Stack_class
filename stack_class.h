namespace my {
	template<typename T> 
	class Stack {
	private:
		T* m_ptr;
		size_t m_size;
		size_t m_capacity;

	public:
//constructors
		Stack();		//line 1
		Stack(size_t count, T value);		//line 10
		Stack(std::initializer_list<T> list);		//line 23
		Stack(const Stack<T>& obj);		//line 36
		Stack(Stack<T>&& obj);		//line 51

//
//destructor
		~Stack();		//line 65

//functions that allocates and reallocates space
		void allocator(size_t new_capacity = 2);		//line 78
		void reallocator(size_t new_capacity = 0);		//line 87

//some methods for my Stack
		size_t size();		//line 107
		size_t capacity();		//line 114
		bool empty();		//line 125
		T& top();		//line 132
		void push(T value);		//line144
		void pop();		//line157
		void swap(my::Stack<T>& obj);		//line 169

//some operator overloading functions
		void operator=(const my::Stack<T>& obj);		//line 180
		void operator=(my::Stack<T>&& obj);		//line 195
		std::ostream& operator<<(std::ostream& obj)
		{
			for (size_t i = 0; i < this->m_size; ++i) {
				obj << this->m_ptr[i] << " ";
			}

			return obj;
		}
	};

#include "Stack.hpp"
}

