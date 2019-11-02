#pragma once
#include <iostream>

#define null 0

using namespace std;

template<typename T>
class Tree;


template<typename T>
class TreeNode {
	friend  class Tree<T>;
private:
	T data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	friend ostream& operator<<(ostream& os, const TreeNode<T>& node) {
		os << "Data: " << node.data << endl;
		if (node.left != 0) {
			os << "Left: " << node.left << endl;
		}
		if (node.right != 0) {
			os << "Right: " << node.right << endl;
		}
		return os;
	}

};

template <typename T>
class BinaryTree {
private:
	TreeNode<T>* root;
public:
	BinaryTree(T data = 0)
	{
		root = new TreeNode<T>(data);
	}
	void insertNode(TreeNode<T>* node) {
		if (searchNode(root, node->data) == null) {
			TreeNode<T> *parent = null;
			TreeNode<T> *current = root;
			while (current != null) {
				parent = current;
				if (node->data >= current->data) {
					current = current->right;
				}
				else
					current = current->left;
			}
			if (node->data < parent->data) {
				parent->left = node;
			}
			else {
				parent->right = node;
			}
			cout << "Inserted " << node->data << endl;
		}
	}
	TreeNode<T>* getRoot() {
		return root;
	}
	void preorder(TreeNode<T>* node) {
		if (node != NULL)
		{
			visit(node);
			preorder(node->left);
			preorder(node->right);
		}
	}
	void prefixorder(TreeNode<T>* node) {
		if (node != NULL)
		{
			preorder(node->left);
			preorder(node->right);
			visit(node);
		}
	}
	
	TreeNode<T>* searchNode(TreeNode<T>* node, T data) {
		if (node == null) return null;
		if (data == node->data) return node;
		else if (data > node->data) {
			searchNode(node->right, data);
		}
		else
			searchNode(node->left, data);
	}
	void visit(TreeNode<T>* current);

};
