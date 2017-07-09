//Accepted date: 20170611
//Author: xaingdongzhao
#include "head.h"

class Solution {
public:
	int dist(pair<int, int> a, pair<int, int> b){
		int diffx=a.first-b.first;
		int diffy=a.second-b.second;
		return diffx*diffx+diffy*diffy;
	}
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int result=0;
		for(int i=0;i<points.size();i++){
			map<int,int> m;
			for(int j=0;j<points.size();j++){
				if(i==j)continue;
				int temp=dist(points[i],points[j]);
				m[temp]++;
			}
			for(map<int,int>::iterator it=m.begin();it!=m.end();it++)  
				result+=(it->second-1)*it->second;
		}
		return result;
	}
};

int main()
{

	//[[0,0],[1,0],[2,0]]
	vector<pair<int, int>> points;
	points.push_back(pair<int, int>(0,0));
	points.push_back(pair<int, int>(1,0));
	points.push_back(pair<int, int>(2,0));

	Solution s;
	s.numberOfBoomerangs(points);
}