#include "tree.h"
template <typename Q>
void BinaryTree<Q>::visit(TreeNode<Q>* current) {
	cout << current->data << " ";
}