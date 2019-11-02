#include "test.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	BinaryTree<int> tree(8);
	tree.insertNode(new TreeNode<int>(4));
	tree.insertNode(new TreeNode<int>(5));
	tree.insertNode(new TreeNode<int>(6));
	tree.insertNode(new TreeNode<int>(2));
	cout << "Preorder >> ";
	tree.preorder(tree.getRoot());
	cout << "\nPrefix >> ";
	tree.prefixorder(tree.getRoot());
}