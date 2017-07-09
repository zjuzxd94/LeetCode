//Accepted date: 20170601
//思路 参考http://blog.csdn.net/u012501459/article/details/46820823解法四
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count=0;
		int result=nums[0];
		for(int i=0;i<nums.size();i++){
			if(count==0||result==nums[i]){
				count++;
				result=nums[i];
			}
			else
				count--;
		}
		return result;
	}
};