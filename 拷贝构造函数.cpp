#include "head.h"
class CExample   
{  
private:  
	int a;  

public:  
	//���캯��  
	CExample(int b)  
	{   
		a = b;  
		cout<<"creat: "<<a<<endl;  
	}  

	//��������  
	CExample(const CExample& C)  
	{  
		a = C.a;  
		cout<<"copy"<<endl;  
	}  

	//��������  
	~CExample()  
	{  
		cout<< "delete: "<<a<<endl;  
	}  

	void Show ()  
	{  
		cout<<a<<endl;  
	}  
};  

//�������캯���ĵ������һ��������ֵ���ݵķ�ʽ���뺯������ 
void fun1(CExample C)  
{  
	cout<<"fun1"<<endl;
}  

//�������캯���ĵ����������������ֵ���ݵķ�ʽ�Ӻ�������
CExample fun2()  
{  
	cout<<"fun2"<<endl;
	CExample A(1);
	return A;
}

int main()  
{  
	CExample A(1); 
	fun1(A);
	cout<<endl;
	CExample D=fun2();
	cout<<endl;
	//�������캯���ĵ����������������Ҫͨ������һ��������г�ʼ��
	CExample B=A;
	cout<<endl;
	CExample C(A);

	return 0;  
} 