//Accepted date: 20170607
//Author: xaingdongzhao
#include"head.h"

//Ë¼Â·£º²Î¿¼http://blog.csdn.net/u012501459/article/details/46779021
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
		if(candidates[i]>target)
			return;
		for(int j=i;j<candidates.size();j++){
			path.push_back(candidates[j]);
			dfs(result,candidates,path,j,target-candidates[j]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		qsort(candidates.data(),candidates.size(),4,comp);
		if(candidates.empty()||candidates.front()>target)return result;

		vector<int> path;
		dfs(result,candidates,path,0,target);

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> candidates(4);
	candidates[0]=2;
	candidates[1]=3;
	candidates[2]=6;
	candidates[3]=7;
	int target=7;
	s.combinationSum(candidates,target);
}