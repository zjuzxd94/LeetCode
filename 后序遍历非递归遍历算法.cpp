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
	stack<struct node*> Q;

	//ʹ������stack����1
	//while(T||!S.empty())
	//{
	//	while (T)
	//	{
	//		S.push(T);
	//		Q.push(T);
	//		T = T->right;
	//	}
	//	if(!S.empty())
	//	{
	//		T = S.top();S.pop();
	//		T = T->left;
	//	}
	//	
	//}
	//while(!Q.empty())
	//{
	//	T = Q.top();Q.pop();
	//	cout<<T->data<<' ';
	//}
	
	
	//ʹ������stack����2
	//if(T)S.push(T);
	//while(!S.empty()){
	//	struct node* temp=S.top();
	//	S.pop();
	//	Q.push(temp);

	//	if(temp->left)S.push(temp->left);
	//	if(temp->right)S.push(temp->right);
	//}

	//while(!Q.empty())
	//{
	//	struct node* temp = Q.top();Q.pop();
	//	cout<<temp->data<<' ';
	//}


	//ʹ��һ��stack
	if(T)S.push(T);
	struct node* h=T;//���һ�ε�������ӡ�Ľڵ�
	struct node* c=NULL;//ջ��Ԫ��
	while(!S.empty()){
		c=S.top();
		if(c->left&&h!=c->left&&h!=c->right)
			S.push(c->left);
		else if(c->right&&h!=c->right)
			S.push(c->right);
		else{
			cout<<c->data<<' ';
			S.pop();
			h=c;
		}
	}

	
	return 0;
}