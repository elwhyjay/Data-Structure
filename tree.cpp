#include "tree.h"

template <typename T>
Tree::Tree(T data =0)
{
	root = new TreeNode<T>(data);
}
template <typename T>
void Tree::insertNode(TreeNode<T>* node) {
	if (searchNode(node, node->data) == NULL) {
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
		cout << "Inserted" << node->data << endl;
	}
}
template <typename T>
TreeNode<T> Tree::getRoot() {
	return root;
}
template <typename T>
void Tree::preorder(TreeNode<T>* node) {
	if (node != NULL)
	{
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}
template <typename T>
void Tree::visit(TreeNode<T>* current) {
	cout << current->data <<  endl;
}
template <typename T>
TreeNode<T> Tree::searchNode(TreeNode<T>* node, T data) {
	if (node == NULL) return NULL;
	if (data == node->data) return node;
	else if (data > node->data) {
		search(node->right, data);
	}
	else
		search(node->left, data);
}

template <typename T>
TreeNode::TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null) {
	this->data = data;
	this->left = left;
	this->right = right;
}
template <typename T>
friend TreeNode::ostream& operator<<(ostream& os, const TreeNode<T>& node) {
	os << "Data: " << node.data << endl;
	if (node.left != 0) {
		os << "Left: " << node.left << endl;
	}
	if (node.right != 0) {
		os << "Right: " << node.right << endl;
	}
	return os;
}
