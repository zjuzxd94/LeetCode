#include "iostream"
#include "stack"

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

//   1
// 2   3
//4 5 6 7
int main()
{
	struct node* T = new struct node;
	T->data = 1;

	T->left = new struct node;
	T->right = new struct node;
	T->left->data = 2;
	T->right->data = 3;

	T->left->left = new struct node;
	T->left->right = new struct node;
	T->left->left->data = 4;
	T->left->left->left = T->left->left->right = NULL;
	T->left->right->data = 5;
	T->left->right->left = T->left->right->right = NULL;

	T->right->left = new struct node;
	T->right->right = new struct node;
	T->right->left->data = 6;
	T->right->left->left = T->right->left->right = NULL;
	T->right->right->data = 7;
	T->right->right->left = T->right->right->right = NULL;

	stack<struct node*> S;
	while(T||!S.empty())
	{
		while (T)
		{
			S.push(T);
			T = T->left;
		}
		if(!S.empty())
		{
			T = S.top();S.pop();
			cout<<T->data<<' ';
			T = T->right;
		}
	}
}