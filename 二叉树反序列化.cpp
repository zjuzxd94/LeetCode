#include <iostream>
#include <string>
#include <stack>
using namespace  std;
struct node{
	char c;
	struct node* left;
	struct node* right;
	node(int _c):c(_c),left(NULL),right(NULL){}
};
//�������л�
void fun11(string& s, struct node* root){
	s+=root->c;
	if(root->left==NULL)
		s+="#";
	else
		fun11(s,root->left);
	if(root->right==NULL)
		s+="#";
	else
		fun11(s,root->right);
}
//�������л�
struct node* fun1(string& s, struct node* root, int& i)
{
	if(s[i]!='#'){
		root=new struct node(s[i]);
		root->left=fun1(s,root->left,++i);
		root->right=fun1(s,root->right,++i);
		return root;
	}
	else
		return NULL;
}
//�������л�
void fun22(string& s, struct node* root){
	if(root->left==NULL)
		s+="#";
	else
		fun22(s,root->left);
	s+=root->c;
	if(root->right==NULL)
		s+="#";
	else
		fun22(s,root->right);
}
//�������л�
struct node* fun2(string& s, struct node* root, int& i)
{
	stack<char> sta1, sta2;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='#')
			sta1.push(s[i]);
		else{
			if(sta1.top()=='#'){

			}
		}
	}
}

int  main()
{
	string s1="12##3##";//����
	string s2="#2#1#3#";//���� ����������з����л������Ψһ
	string s3="##2##31";//����
	struct node* root=NULL;
	int i=0;
	root=fun1(s1,root,i);
	string str1;
	fun11(str1,root);
	string str2;
	fun22(str2,root);
	return 0;
}

