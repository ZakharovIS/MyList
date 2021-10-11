#pragma once
template <typename T> class MyList {

	template <typename T> class Node {
	
		friend class MyList<T>;
		Node<T>* prev_, * next_;
		T* data_;
		Node() : prev_(nullptr), next_(nullptr), data_(nullptr) {};
		explicit Node(const T& t) : prev_(nullptr), next_(nullptr) { data_ = new T(t); };
		//~Node();
	};

		Node<T> head_, tail_;
		size_t size_;
		
public:
	MyList();
	void push_front(const T&);
	void push_back(const T&);


	
};

template <typename T> MyList<T>::MyList() : size_( 0 ) {

	head_.next_ = &tail_;
	tail_.prev_ = &head_;

};

template <typename T> void MyList<T>::push_back(const T& t) {
	
	Node<T>* node{ new Node<T>(t) };
	this->tail_.prev_->next_ = node;
	node->prev_ = this->tail_.prev_;
	node->next_ = &this->tail_;
	this->tail_.prev_ = node;
	++size_;
}

template <typename T> void MyList<T>::push_front(const T& t) {

	Node<T>* node{ new Node<T>(t) };
	this->head_.next_->prev_ = node;
	node->next_ = this->head_.next_;
	node->prev_ = &this->head_;
	this->head_.next_ = node;
	++size_;
}