//Accepted date: 20170529
//Author: xaingdongzhao
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//思路：参考http://www.tuicool.com/articles/6vYfmmj
class Solution1 {
private:
	vector<vector<string>> res;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> cur(n,string(n,'.'));
		recursion(cur,0);
		return res;
	}
	void recursion(vector<string>& cur, int row){
		if(row==cur.size()){
			res.push_back(cur);
			return;
		}
		for(int col=0;col<cur.size();col++){
			if(isValid(cur,row,col)){
				cur[row][col]='Q';
				recursion(cur,row+1);
				cur[row][col]='.';
			}
		}
	}
	bool isValid(vector<string>& cur, int row, int col)
	{
		for(int i=0;i<cur.size();i++)
			if(cur[i][col]=='Q')
				return false;
		for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
			if(cur[i][j]=='Q')
				return false;
		for(int i=row-1,j=col+1;i>=0&&j<cur.size();i--,j++)
			if(cur[i][j]=='Q')
				return false;
		return true;
	}
};

//Solution2 简化了isValid的实现方法
class Solution2 {
private:
	vector<vector<string>> res;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> state(n,-1);
		recursion(state,0);
		return res;
	}
	void recursion(vector<int>& state, int row){
		int n=state.size();
		if(row==n){
			vector<string> temp(n,string(n,'.'));
			for(int i=0;i<n;i++)
				temp[i][state[i]]='Q';
			res.push_back(temp);
			return;
		}
		for(int col=0;col<n;col++){
			if(isValid(state,row,col)){
				state[row]=col;
				recursion(state,row+1);
				state[row]=-1;
			}
		}
	}
	bool isValid(vector<int>& state, int row, int col){
		for(int i=0;i<row;i++){
			if(state[i]==col||abs(row-i)==abs(col-state[i]))
				return false;
		}
		return true;
	}
};

//Solution3 Solution2的非递归实现
class Solution3 {
private:
	vector<vector<string> > res;
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> state(n, -1);
		for(int row = 0, col; ;)
		{
			for(col = state[row] + 1; col < n; col++)//从上一次放置的位置后面开始放置
			{
				if(isValid(state, row, col))
				{
					state[row] = col;
					if(row == n-1)//找到了一个解,继续试探下一列
					{
						vector<string>tmpres(n, string(n,'.'));
						for(int i = 0; i < n; i++)
							tmpres[i][state[i]] = 'Q';
						res.push_back(tmpres);
					}
					else {row++; break;}//当前状态合法，去放置下一行的皇后
				}
			}
			if(col == n)//当前行的所有位置都尝试过，回溯到上一行
			{
				if(row == 0)break;//所有状态尝试完毕，退出
				state[row] = -1;//回溯前清除当前行的状态
				row--;
			}
		}
		return res;
	}

	//判断在row行col列位置放一个皇后，是否是合法的状态
	//已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
	bool isValid(vector<int> &state, int row, int col)
	{
		for(int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
			if(state[i] == col || abs(row - i) == abs(col - state[i]))
				return false;
		return true;
	}
};

//Solution4 最高效的解法
class Solution4 {
public:
	vector<vector<string>> solveNQueens(int n) {

	}
};
int main()
{

}