#include <iostream>
#include <vector>
class A{
public:
	A(){
		static int ref =0;
		std::cout<<"ref:"<<ref++<<std::endl;
	}
	static A* get(){
		static A* pa=new A;
		return pa;
	} 
};

int main()
{
	std::vector<A*> as;
	for(int i=0;i<3;++i){
		as.push_back(A::get());
	}

	A** pa=&(as[0]);
	for(int i=0;i<3;++i){
		delete *pa;
	}
}