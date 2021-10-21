#pragma once
#include <iostream>

template <typename T> class MyList {

	class Node {
	
		friend class MyList<T>;
		Node* prev_;
		Node* next_;
		T* data_;
		
		Node() : prev_(nullptr), next_(nullptr), data_(nullptr) {};
		explicit Node(const T& t);
		~Node() { delete data_; };

		
	public:
		template <typename T> friend std::ostream& operator<<(std::ostream& os, const typename MyList<T>::Node& n);

	};

	class Iterator {
		
	public:
		Iterator(Node* node) : current_(node) {}
		Iterator& operator++() { current_ = current_->next_; return *this; }
		Iterator operator++(int) { Iterator tmp(current_); ++(*this); return tmp; }
		bool operator!=(const Iterator& rhs) const { return current_ != rhs.current_; }
		T& operator*() { return *current_->data_; }
		T* operator->() { return &(current_->data_); }
	private:
		Node* current_;

	};

		Node head_, tail_;
		size_t size_;
		
public:
	MyList();
	MyList(std::initializer_list<T>);

	MyList<T>::Iterator begin();
	MyList<T>::Iterator end();


	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();

	//template <typename T> friend std::ostream& operator<<(std::ostream& os, const typename MyList<T>::Node& n);
	
};

//Intellisense doesn't work propertly with templates
//Instantinate template class with T = int


template <typename T> 
MyList<T>::Node::Node(const T& t) : prev_(nullptr), next_(nullptr) {

	data_ = new T(t); 

};






template <typename T> MyList<T>::MyList() : size_( 0 ) {

	head_.next_ = &tail_;
	tail_.prev_ = &head_;

};

template <typename T> MyList<T>::MyList(std::initializer_list<T> l): size_(0) {
	
	head_.next_ = &tail_;
	tail_.prev_ = &head_;

	for (auto& i : l)
	{
		this->push_back(i);
	}
}



template <typename T> void MyList<T>::push_back(const T& t) {
	
		Node* node{ new Node(t) };
		this->tail_.prev_->next_ = node;
		node->prev_ = this->tail_.prev_;
		node->next_ = &this->tail_;
		this->tail_.prev_ = node;
		++size_;
		
}

template <typename T> void MyList<T>::push_front(const T& t) {

	Node* node{ new Node(t) };
	this->head_.next_->prev_ = node;
	node->next_ = this->head_.next_;
	node->prev_ = &this->head_;
	this->head_.next_ = node;
	++size_;
}

template <typename T> void MyList<T>::pop_front() {

	if (this->head_.next_ != &this->tail_)
	{
		Node* tmp = this->head_.next_;
		this->head_.next_ = this->head_.next_->next_;
		this->head_.next_->prev_ = &this->head_;
		delete tmp;
		--size_;
	}
		
}

template <typename T> void MyList<T>::pop_back() {

	if (this->head_.next_ != &this->tail_)
	{
		Node* tmp = this->tail_.prev_;
		this->tail_.prev_ = this->tail_.prev_->prev_;
		this->tail_.prev_->next_ = &this->tail_;
		delete tmp;
		--size_;
	}
}

template <typename T> typename MyList<T>::Iterator MyList<T>::begin() {
	return MyList<T>::Iterator(this->head_.next_);
}

template <typename T> typename MyList<T>::Iterator MyList<T>::end() {
	return MyList<T>::Iterator(&this->tail_);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyList<float>::Node& n) {

	os << "11 ";
	return os;
}