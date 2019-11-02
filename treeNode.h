#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class TreeNode {
	friend  class Tree<T>;
private:
	T data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(T, TreeNode*, TreeNode*);
	friend ostream& operator<<(ostream&, const TreeNode<T>&);

};
