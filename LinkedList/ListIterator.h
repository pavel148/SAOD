#pragma once
#include "LinkedListNode.h"
template <typename T>
class ListIterator
{
public:
	LinkedListNode<T>* node;
	ListIterator(LinkedListNode<T> *node) {
		this->node = node;
	}
    //~ListIterator() {
    //    delete node;
    //}
	ListIterator operator++(int) {
        node = node->next;
        //node = *node.next;
        return *this;
		//ListIterator tmp(node->next);
		//return tmp;
	}
	ListIterator& operator++() {
		node = node->next;
       // node = *node.next;
		return *this;
	}

    //ListIterator operator--(int) {
    //    ListIterator tmp();
    //    return tmp;
    //}

    //ListIterator& operator--() {
    //    //код
    //        return *this;
    //}

    bool operator==(const ListIterator& it) const {
        return node->data == it.node->data;
       // return node.data == it.node.data;
        //return node == it.node;

    }
    bool operator!=(const ListIterator& it) const {
        return !(*this == it);
    }
    T& operator*() {
        return node->data;
        //return node.data;
    }
    const T& operator*() const {
        return node->data;
        //return node.data;
    }
};

