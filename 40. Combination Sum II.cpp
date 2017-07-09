//Accepted date: 20170607
//Author: xaingdongzhao
#include"head.h"

//思路：同39	Combination Sum
//要加上去除重复的机制
class Solution {
public:
	static int comp(const void* a,const void* b){
		return *(int*)a-*(int*)b;
	}

	void dfs(vector<vector<int>>& result,vector<int>& candidates,vector<int>& path,int i,int target){
		if(target==0){
			result.push_back(path);
			return;
		}
		if(i==candidates.size()||candidates[i]>target)
			return;
		int last=-1;
		for(int j=i;j<candidates.size();j++){
			if(candidates[j]==last)
				continue;
			path.push_back(candidates[j]);
			dfs(result,candidates,path,j+1,target-candidates[j]);
			path.pop_back();
			last=candidates[j];
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		qsort(candidates.data(),candidates.size(),4,comp);
		if(candidates.empty()||candidates.front()>target)return result;

		vector<int> path;
		dfs(result,candidates,path,0,target);

		return result;
	}
};

//[10, 1, 2, 7, 6, 1, 5]
int main()
{
	Solution s;
	vector<int> candidates(7);
	candidates[0]=10;
	candidates[1]=1;
	candidates[2]=2;
	candidates[3]=7;
	candidates[4]=6;
	candidates[5]=1;
	candidates[6]=5;

	int target=8;
	s.combinationSum2(candidates,target);
}