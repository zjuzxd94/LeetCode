//Accepted date: 20170601
//˼· �ο�http://blog.csdn.net/u012501459/article/details/46820823�ⷨ��
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