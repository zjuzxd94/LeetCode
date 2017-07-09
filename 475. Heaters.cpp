//Accepted date: 20170605
//Author: xaingdongzhao
#include "head.h"

//思路：这道题是WAP online coding的第一题，也是我的最后一题。。。
//寻找每个house左右距离最近的heater，然后对所有house，求最大
//online coding的时候，对houses和heaters分别生成长度为最后一个house和heater的bool数组，记录每个位置是否有house或heater
//上面这种方法在leetcode上LTE
//如下的代码，运行时间超过100%的提交！！！破纪录啦
class Solution {
public:
	static int comp(const void* a,const void* b){
		return *(int*)a-*(int*)b;
	}
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		qsort(houses.data(),houses.size(),sizeof(houses[0]),comp);
		qsort(heaters.data(),heaters.size(),sizeof(heaters[0]),comp);
		int m=houses.size();
		int n=heaters.size();

		int minRadius=0;
		int i=0;
		for(int k=0;k<houses.size();k++){
			int left,right;
			while(i<n&&houses[k]>=heaters[i])i++;
			if(i==0){
				left=INT_MAX;
				right=heaters[0]-houses[k];
			}
			else if(i==n){
				left=houses[k]-heaters.back();
				right=INT_MAX;
			}
			else{
				i--;
				if(houses[k]==heaters[i]){
					left=houses[k]-heaters[i];
					right=heaters[i]-houses[k];
				}
				else{
					left=houses[k]-heaters[i];
					right=heaters[i+1]-houses[k];
				}
			}
			int tempRadius=min(left,right);
			if(tempRadius>minRadius)
				minRadius=tempRadius;
		}

		return minRadius;
	}
};

int main()
{
	vector<int> houses(3);
	houses[0]=1;
	houses[1]=2;
	houses[2]=3;
	vector<int> heaters(1);
	heaters[0]=2;

	Solution s;
	s.findRadius(houses,heaters);
}