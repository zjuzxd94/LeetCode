//Accepted date: 20170605
//Author: xaingdongzhao
#include "head.h"

//˼·�����������ҵ���һ������index1��¼��С�����±꣬index2��¼�ϴ������±�
//��index2��ʼ�����Ҵ���nums[index1]������ӽ�nums[index1]����������index2
//����nums[index1]��nums[index2]��Ȼ���index1���������С��������
class Solution {
public:
	static int comp(const void* a, const void* b){
		return *(int*)a-*(int*)b;
	}
	void nextPermutation(vector<int>& nums) {
		if(nums.size()<2)return;
		int n=nums.size();

		int index1=-1,index2=-1;
		for(int i=n-1;i>0;i--){//���������ҵ�һ������
			if(nums[i-1]<nums[i]){
				index1=i-1;
				index2=i;
				break;
			}
		}
		for(int i=index1+1;i<n;i++){//��index2�����Ҵ���nums[index1]������ӽ�nums[index1]����
			if(nums[i]>nums[index1]&&nums[i]<nums[index2])
				index2=i;
		}
		if(index1!=-1&&index2!=-1){

			//----
			swap(nums[index1],nums[index2]);
			qsort(nums.data()+index1+1,n-index1-1,sizeof(nums[0]),comp);
			//----
		}
		else{
			int l=0,r=n-1;
			while(l<r)
				swap(nums[l++],nums[r--]);
		}

	}
};

int main()
{
	Solution s;
	vector<int> nums(7);
	nums[0]=4;nums[1]=2;nums[2]=0;
	nums[3]=2;nums[4]=3;nums[5]=2;nums[6]=0;
	s.nextPermutation(nums);
	return 0;
}