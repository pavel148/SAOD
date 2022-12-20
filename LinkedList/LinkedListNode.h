#pragma once
template <typename T>
class LinkedListNode
{
public:
	T data;
	LinkedListNode<T>* next;
	LinkedListNode() {
		next = nullptr;
	}
	LinkedListNode(T& data) {
		this->data = data;
	}
	//~LinkedListNode() {

	//}

	//bool operator !=(const LinkedListNode<T>& ln) {
	//	return data == ln.data;
	//}
	LinkedListNode<T> operator +=(const T& t) {
		data += t;
		return *this;
	}
//private:
};

