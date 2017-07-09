//Accepted date: 20170605
//Author: xaingdongzhao
#include "head.h"

//思路：从右向左找到第一个降序，index1记录较小数的下标，index2记录较大数的下标
//从index2开始往右找大于nums[index1]并且最接近nums[index1]的数，更新index2
//交换nums[index1]和nums[index2]，然后对index1后面的数从小到大排序
class Solution {
public:
	static int comp(const void* a, const void* b){
		return *(int*)a-*(int*)b;
	}
	void nextPermutation(vector<int>& nums) {
		if(nums.size()<2)return;
		int n=nums.size();

		int index1=-1,index2=-1;
		for(int i=n-1;i>0;i--){//从右往左找第一个降序
			if(nums[i-1]<nums[i]){
				index1=i-1;
				index2=i;
				break;
			}
		}
		for(int i=index1+1;i<n;i++){//从index2往右找大于nums[index1]并且最接近nums[index1]的数
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