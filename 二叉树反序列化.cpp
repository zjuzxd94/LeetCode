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
//先序序列化
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
//先序反序列化
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
//中序序列化
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
//中序反序列化
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
	string s1="12##3##";//先序
	string s2="#2#1#3#";//中序 中序遍历序列反序列化结果不唯一
	string s3="##2##31";//后序
	struct node* root=NULL;
	int i=0;
	root=fun1(s1,root,i);
	string str1;
	fun11(str1,root);
	string str2;
	fun22(str2,root);
	return 0;
}

