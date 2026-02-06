/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		vector<int> prefixMin;
		vector<int> prefixFirstMax;
		prefixMin.reserve(prices.size());
		prefixFirstMax.reserve(prices.size());
		int ret=0;
		int prefixFirstMaxVal=-0x3f3f3f3f;
		int minVal=0x3f3f3f3f;
		for(int i=0;i<prices.size();i++){
			minVal=min(minVal,prices[i]);
			prefixMin.push_back(minVal);
			prefixFirstMaxVal=max(prefixFirstMaxVal,prices[i]-minVal);
			prefixFirstMax.push_back(prefixFirstMaxVal);
			ret=max(ret,prices[i]-minVal);
		    for(int j=i-1;j>1;j--){
                 int firstProfit=prices[i]-prices[j];
				 int totalProfit=firstProfit+prefixFirstMax[j-1];
				 ret=max(ret,totalProfit);
				 if(prices[i]-prefixMin[j]+prefixFirstMax[j]<ret) break;
			}
		}
		return ret;
	}
};	
// @lc code=end

int main(int argc, char const *argv[])
{
	freopen("./input.in","r",stdin);
	freopen("./output.out","w",stdout);
	Solution s;

	vector<int> prices{1,2,3,4,5};
	int ret = s.maxProfit(prices);
	int a=INT_MAX;
	cout<<a<<endl;
	return 0;
}
