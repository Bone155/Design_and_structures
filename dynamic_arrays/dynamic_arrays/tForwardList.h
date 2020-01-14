#pragma once

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;
		Node * next;
	};

	Node * head;
	Node * tail;

public:
	tForwardList() {
		head = nullptr;
	}
	~tForwardList() {
		delete head;
		delete tail;
	}

	void push_front(const T& val) {
		Node* n;
		n.data = val;
		n.next = head;
		if (tail == nullptr)
			tail = n;
		head = n;
	}
	void pop_front() {
		Node* n;
		if (head != nullptr)
			n = head;
		head = head.next;

		delete n;
	}

	T& front() {
		return head;
	}
	const T& front() const {
		return head;
	}

	void remove(const T& val) {
		Node* n;
		if (head != nullptr) {
			
		}
		head = head.next;

		delete n;
	}

	tForwardList(const tForwardList& other) {

	}

	tForwardList& operator=(const tForwardList &rhs) {

	}

	bool empty() const {

	}

	void clear() {

	}

	void resize(size_t newSize) {

	}
};