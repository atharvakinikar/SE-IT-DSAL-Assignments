

#ifndef TREE_HEADER_H_
#define TREE_HEADER_H_

struct treenode
{
	char data;
	treenode *lchild;
	treenode *rchild;
};

class expTree
{
	treenode *root;
public:
	expTree(); //constructor initialize root node
	void createTree(string exp);
	bool isOpera(char);
	treenode*getTreeNode(char);
	treenode*getroot();
	//Recursive Traversals
	void RInorderTraversal(treenode*);
	void RPreorderTraversal(treenode*);
	void RPostorderTraversal(treenode*);
	//Non Recursive Traversals
	void NRInorderTraversal(treenode*);
	void NRPreorderTraversal(treenode*);
	void NRPostorderTraversal(treenode*);
};

#endif /* TREE_HEADER_H_ */
