//Accepted date: 20170605
//Author: xaingdongzhao
#include "head.h"

//˼·���������WAP online coding�ĵ�һ�⣬Ҳ���ҵ����һ�⡣����
//Ѱ��ÿ��house���Ҿ��������heater��Ȼ�������house�������
//online coding��ʱ�򣬶�houses��heaters�ֱ����ɳ���Ϊ���һ��house��heater��bool���飬��¼ÿ��λ���Ƿ���house��heater
//�������ַ�����leetcode��LTE
//���µĴ��룬����ʱ�䳬��100%���ύ�������Ƽ�¼��
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