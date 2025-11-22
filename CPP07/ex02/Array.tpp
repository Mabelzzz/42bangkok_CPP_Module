template <typename T>
Array<T>::Array() :_array(NULL), _size(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
	std::cout << GREEN << "Parameterized constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0){
	if (other._size > 0) {
		this->_size = other._size;
		this->_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			this->_array[i] = other._array[i];
		}
	}
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		if (this->_array)
			delete[] this->_array;
		if (other._size > 0) {
			this->_size = other._size;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = other._array[i];
			}
		} else {
			this->_array = NULL;
			this->_size = 0;
		}
	}
	std::cout << YELLOW << "Assignment operator called" << RESET << std::endl;
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (this->_array)
		delete[] this->_array;
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw IndexOutOfBoundsException();
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw IndexOutOfBoundsException();
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}
