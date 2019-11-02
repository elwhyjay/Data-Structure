#pragma once
#include <inttypes.h>
#include <iostream>
using namespace std;
template <typename T>
class DoubleLinkedList;

template <typename T>
class Node {
	friend class DoubleLinkedList<T>;
private:
	T data;
	Node* ptr;
public:
	Node(T data = 0, Node* ptr = NULL) {
		this->data = data;
		this->ptr = NULL;
	}
	Node* Xor(Node* a, Node* b) {
		return (Node*)(((uintptr_t)a) ^ ((uintptr_t)b));
	}
	friend ostream& operator<< (ostream& os, const Node<T>& node) {
		os << node.data << endl;
		return os;
	}
};

template <typename T>
class DoubleLinkedList {
private:
	Node<T>* root;
public:
	DoubleLinkedList(T data =0) {
		root = new Node<T>(data);
	}
	void insertNode(T data) {

	}
	bool searchNode(T data) {

	}
	void deleteNode(T data) {

	}
	void deleteLastNode() {

	}
	void deleteFirstNode() {

	}

};

