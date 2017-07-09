//Accepted date: 20170607
//Author: xaingdongzhao
#include "head.h"
//思路：记录每个点左边和右边最大的数
class Solution {
public:
	int trap(vector<int>& height) {
		int n=height.size();
		if(n<3)
			return 0;

		int result=0;
		vector<int> left(n);
		vector<int> right(n);

		left[0]=0;
		int maxleft=height[0];
		for(int i=1;i<n;i++){
			if(height[i]<maxleft)
				left[i]=maxleft;
			else{
				left[i]=0;
				maxleft=height[i];
			}
		}

		right[n-1]=0;
		int maxright=height[n-1];
		for(int i=n-2;i>=0;i--){
			if(height[i]<maxright)
				right[i]=maxright;
			else{
				right[i]=0;
				maxright=height[i];
			}
		}

		for(int i=0;i<n;i++){
			int temp=min(left[i],right[i]);
			result+=temp==0?0:(temp-height[i]);
		}

		return result;
	}
};
int main()
{
	vector<int> height;
	//[0,1,0,2,1,0,1,3,2,1,2,1]
	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);

	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);
	Solution s;
	s.trap(height);
}