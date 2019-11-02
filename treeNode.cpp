#include "treeNode.h"

template <typename T>
TreeNode::TreeNode(T data =0, TreeNode* left =null, TreeNode* right = null){
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