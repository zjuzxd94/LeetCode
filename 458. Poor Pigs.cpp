//Accepted date: 20170619
//Author: xaingdongzhao

//思路：信息论。参考https://zhihu.com/question/60227816/answer/175681677
class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		if(buckets<=1)
			return 0;
		double allInfo=buckets;
		double pigInfo=minutesToTest/minutesToDie+1;
		double info=pigInfo;
		int result=1;
		while(info<allInfo){
			info*=pigInfo;
			result++;
		}
		return result;
	}
};