//Accepted date: 20170623
//Author: xaingdongzhao

#include "head.h"

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


//思路：先对Intervals数组排序，排序规则为按start从小到大。再依次遍历Intervals数组
class Solution {
public:
    static int comp(const void* a, const void* b){
        return ((Interval*)a)->start-((Interval*)b)->start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())
            return result;
        qsort(intervals.data(),intervals.size(),8,comp);
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>result.back().end)
                result.push_back(intervals[i]);
            else if(intervals[i].end>result.back().end)
                result.back().end=intervals[i].end;
        }
        return result;
    }
};