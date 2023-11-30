//default constructor
template<typename T>
Stack<T>::Stack()
{
	this->m_size = 0;
	this->m_capacity = 0;
	this->m_ptr = nullptr;
}

//parameterized contructor
template <typename T>
Stack<T>::Stack(size_t count, T value)
{
	this->m_size = count;
	this->m_capacity = count + 2;
	this->m_ptr = new T[count + 2];
	
	for (size_t i = 0; i < count; ++i) {
		this->m_ptr[i] = value;
	}
}

//Initializer_list constructor
template <typename T>
Stack<T>::Stack(std::initializer_list<T> list)
{
	this->m_size = list.size();
	this->m_capacity = list.size();
	this->m_ptr = new T[m_capacity];
	
	for (size_t i = 0; i < this->m_size; ++i) {
		this->m_ptr[i] = list.begin()[i];
	}
}

//copy contructor
template <typename T>
Stack<T>::Stack(const Stack<T>& obj)
{
	if (this->m_ptr != &obj) {
		this->m_size = obj.m_size;
		this->m_capacity = obj.m_capacity;
		this->m_ptr = new T[obj.m_capacity];
	
		for (size_t i = 0; i < obj.m_size; ++i) {
			this->m_ptr[i] = obj.m_ptr[i];
		}
	}
}

//move contructor
template <typename T>
Stack<T>::Stack(Stack<T>&& obj)
{
	if (this->m_ptr != &obj) {
		this->m_size = obj.m_size;
		this->m_capacity = obj.m_capacity;
		this->m_ptr = obj.m_ptr;

		delete[] obj.m_ptr;
		obj.m_ptr = nullptr;
	}
}

//destructor
template<typename T>
Stack<T>::~Stack()
{
	if (!this->m_ptr) {
		delete[] m_ptr;
		m_ptr = nullptr;
	}

	this->m_size = 0;
	this->m_capacity = 0;
}

template<typename T>
void Stack<T>::allocator(size_t new_capacity)
{
	if (!this->m_capacity) {
		this->m_capacity = new_capacity;
		this->m_ptr = new T[this->m_capacity];
	}
}

template<typename T>
void Stack<T>::reallocator(size_t new_capacity)
{
	if (!new_capacity) {
		this->m_capacity *= 1.5;
	} else {
		this->m_capacity += new_capacity;	
	}

	T* tmp_ptr = new T[this->m_capacity];

	for (size_t i = 0; i < this->m_size; ++i) {
		tmp_ptr[i] = this->m_ptr[i];
	}

	delete[] this->m_ptr;
	this->m_ptr = tmp_ptr;
	tmp_ptr = nullptr;
}

//functions wich return size and capacity
template<typename T>
size_t Stack<T>::size()
{
	return this->m_size;
}

template<typename T>
size_t Stack<T>::capacity()
{
	if (!this->m_ptr) {
		std::cout << "Out of range." << std::endl;
		exit(0);
	}
	return this->m_capacity;
	
}

//empty function return true if Stack is empty and false if if not
template<typename T>
bool Stack<T>::empty()
{
	return this->m_size;
}

//returns reference to last inputed element 
template<typename T>
T& Stack<T>::top()
{
	if (!this->m_ptr || !this->m_size) {
		std::cout << "Out of range." << std::endl;
		exit(0);
	}

	return this->m_ptr[this->m_size - 1];
}

//function that adds element at the end
template<typename T>
void Stack<T>::push(T value)
{
	if (!this->m_ptr) {
		this->allocator();
	} else if (this->m_size + 1 > this->m_capacity) {
		this->reallocator();
	}

	this->m_ptr[this->m_size++] = value;
}

//function that removes last element
template<typename T>
void Stack<T>::pop()
{
	if (!this->m_size) {
		std::cout << "Out of range." << std::endl;
		exit(0);	
	}

	--this->m_size;
}

//function that swaps 2 objects
template<typename T> 
void Stack<T>::swap(my::Stack<T>& obj)
{
	std::swap(this->m_size, obj.m_size);
	std::swap(this->m_capacity, obj.m_capacity);
	std::swap(this->m_ptr, obj.m_ptr);
}

//operator overloading
//
//assignment operator
template<typename T>
void Stack<T>::operator=(const my::Stack<T>& obj)
{
	if (this->m_ptr != &obj) {
		this->m_size = obj.m_size;
		this->m_capacity = obj.m_capacity;
		this->m_ptr = new T[obj.m_capacity];
	
		for (size_t i = 0; i < obj.m_size; ++i) {
			this->m_ptr[i] = obj.m_ptr[i];
		}
	}
}

template<typename T>
void Stack<T>::operator=(my::Stack<T>&& obj)
{
	if (this->m_ptr != &obj) {
		this->m_size = obj.m_size;
		this->m_capacity = obj.m_capacity;
		this->m_ptr = obj.m_ptr;
	
	}

	delete[] obj.m_ptr;
	obj.m_ptr = nullptr;
}


//operator << for printing stack
template<typename T> 
std::ostream& operator<<(std::ostream& obj, my::Stack<T>& stack_obj)
{
	return stack_obj.operator<<(obj);
}
