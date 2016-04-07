#include <cstdio>


struct TreeNode
{
	int value;

	TreeNode *left;
	TreeNode *right;

	TreeNode(int value): value(value), left(NULL), right(NULL){}
};

void insert(TreeNode *&tree, int value){
	if(tree == NULL){
		tree = new TreeNode(value);
		return;
	}
	else if(value < tree->value){
		insert(tree->left, value);
	}
	else{
		insert(tree->right, value);
	}
}

void preOrder(TreeNode *tree){
	if(tree != NULL){
		printf("%d ", tree->value);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(TreeNode *tree){
	if(tree != NULL){
		preOrder(tree->left);
		printf("%d ", tree->value);
		preOrder(tree->right);
	}
}

bool binarySearch(TreeNode *tree, int value){
	if(tree == NULL){
		return false;
	}

	if(tree->value == value){
		return true;
	}

	if(tree->value > value){
		return binarySearch(tree->left, value);
	}

	if(tree->value < value){
		return binarySearch(tree->right, value);
	}
}

int main()
{
	TreeNode *binaryTree = NULL;
	int a[7] = {4, 2, 7, 1, 3, 6, 9};

	for(int i = 0; i < 7; i ++){
		insert(binaryTree, a[i]);
	}

	preOrder(binaryTree);
	printf("\n");
	inOrder(binaryTree);
	printf("\n");

	for(int i = 0; i < 7; i ++){
		printf("%d\n", binarySearch(binaryTree, a[i]));
	}

	return 0;
}