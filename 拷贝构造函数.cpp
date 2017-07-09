#include "head.h"
class CExample   
{  
private:  
	int a;  

public:  
	//构造函数  
	CExample(int b)  
	{   
		a = b;  
		cout<<"creat: "<<a<<endl;  
	}  

	//拷贝构造  
	CExample(const CExample& C)  
	{  
		a = C.a;  
		cout<<"copy"<<endl;  
	}  

	//析构函数  
	~CExample()  
	{  
		cout<< "delete: "<<a<<endl;  
	}  

	void Show ()  
	{  
		cout<<a<<endl;  
	}  
};  

//拷贝构造函数的调用情况一：对象以值传递的方式传入函数参数 
void fun1(CExample C)  
{  
	cout<<"fun1"<<endl;
}  

//拷贝构造函数的调用情况二：对象以值传递的方式从函数返回
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
	//拷贝构造函数的调用情况三：对象需要通过另外一个对象进行初始化
	CExample B=A;
	cout<<endl;
	CExample C(A);

	return 0;  
} 