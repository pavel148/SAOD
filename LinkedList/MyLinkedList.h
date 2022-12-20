#pragma once
#include "LinkedListNode.h"
#include "ListIterator.h"
template <typename T>
class MyLinkedList
{
public:
	MyLinkedList() {
		count = 0;
		root = nullptr;
		sluj = new LinkedListNode<T>();
	}
	MyLinkedList(T value){
		root = new LinkedListNode<T>(value);
		sluj = new LinkedListNode<T>();
		root->next = sluj;
		count = 1;
	}
	void push_back(T value) {
		if (!root) {
			root = new LinkedListNode<T>(value);
			root->next = sluj;
		}
		else {
			LinkedListNode<T> *temp = new LinkedListNode<T>(value);
			LinkedListNode<T> *cur = root;
			while (cur->next->next) {
				cur = cur->next;
			}
			cur->next = temp;
			temp->next = sluj;
			//delete temp;
		}
		count++;
	}
	void push_front(T value) {
		if (count) {
			LinkedListNode<T> *temp = new LinkedListNode<T>(value);
			temp->next = root;
			root = temp;
		}
		else {
			root = new LinkedListNode<T>(value);
			root->next = sluj;
		}
		count++;
	}
	void insert(size_t index, T value) {
		if (index == 0) {
			if (!root) {
				root = new LinkedListNode<T>(value);
				root->next = sluj;
			}
			else {
				LinkedListNode<T>* elem = new LinkedListNode<T>(value);
				elem->next = root;
				root = elem;
			}
		}
		else if  (index < count && index >=0 && root) {
			LinkedListNode<T>* cur = root;
			LinkedListNode<T>* elem = new LinkedListNode<T>(value);
			for (int i = 0; i < index - 1; i++)
				cur = cur->next;
			elem->next = cur->next;
			cur->next = elem;
		}
		++count;
	}

	void pop_back() {
		if (count == 1) {
			delete root;
			root = nullptr;
			--count;
		}
		else if  (root) {
			LinkedListNode<T> *tmp = root;
			for (int i = 0; i < count - 2; i++) {
				tmp = tmp->next;
			}
			LinkedListNode<T>* nxt = tmp->next->next;
			delete tmp->next;
			tmp->next = nxt;
			--count;
		}
	}

	void pop_front() {
		if (count == 1) {
			delete root;
			root = nullptr;
			--count;
		}
		else if (count) {
			LinkedListNode<T>* tmp = root->next;
			delete root;
			root = tmp;
			--count;
		}
	}
	void remove_at(size_t index) {
		if (index == 0) {
			pop_front();
		}
		else if (index == count - 1) {
			pop_back();
		}
		else if (index > 0 && index < count && count) {
			LinkedListNode<T>* tmp = root;
			for (int i = 0; i < index - 1; i++) {
				tmp = tmp->next;
			}
			LinkedListNode<T>* nxt = tmp->next->next;
			delete tmp->next;
			tmp->next = nxt;
			--count;
		}
	}

	T& operator [] (const size_t index){
		if (count > index && index >= 0) {
			size_t iter = 0;
			LinkedListNode<T>* cur = root;
			while (iter < index) {
				cur = cur->next;
				iter++;
			}
			return cur->data;
		}
	}
	T const& operator[] (const size_t index) const {
		if (count > index && index >= 0) {
			size_t iter = 0;
			LinkedListNode<T>* cur = root;
			while (iter < index) {
				cur = cur->next;
				iter++;
			}
			return cur->data;
		}
	}
	size_t size() const {
		return count;
	}
	bool empty() const {
		return count == 0;
	}

	void clear() {
		if (count) {
			LinkedListNode<T> *cur = root;
			LinkedListNode<T>* nxt;
			while (cur->next != nullptr) {
				nxt = cur->next;
				delete cur;
				cur = nxt;
			}
			root = nullptr;
			count = 0;
		}
	}

	T front() const {
		if (root) return root->data;
		else return NULL;
	};
	T back() const {
		LinkedListNode<T> *cur = root;
		for (int i = 0; i < count -1; i++) {
			cur = cur->next;
		}
		return cur->data;
	};
	void PrintList() {
		if (root) {
			LinkedListNode<T>* cur = root;
			while (cur->next->next) {
				std::cout << cur->data << " -> ";
				cur = cur->next;
			}
			std::cout << cur->data << std::endl;
		}
	}

	//LinkedListNode<T>* begin() {
	ListIterator<T> begin(){
		if (root)
			return  ListIterator<T>(root);
			//return root;
	}

	//LinkedListNode<T>* end() {
	ListIterator<T> end(){
		if (root) {
			if (count == 1)
				//return root;
				return  ListIterator<T>(root);
			else {
				LinkedListNode<T> *tmp = root;
				for (int i = 0; i < count ; i++) {
					tmp = tmp->next;
				}
				//return tmp;
				return  ListIterator<T>(tmp);
			}
		}
	}

	~MyLinkedList() {
		clear();
		//delete root;
		delete sluj;
		std::cout << "I'm list destrusctor" << std::endl;
		sluj = nullptr;
	}
private:
	size_t count;
	LinkedListNode<T>* root;
	LinkedListNode<T>* sluj;
};

