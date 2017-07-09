class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            //if(hash.find(nums[i])==hash.end())
            if(hash.find(target-nums[i])==hash.end())
            {
                //hash[target-nums[i]]=i;
                hash[nums[i]]=i;
            }
            else
            {
                //result.push_back(hash[nums[i]]);
                result.push_back(hash[target-nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};