// https://leetcode.com/problems/russian-doll-envelopes/


/*
    Topic : DP + Binary Search + Sorting.
    TC : O(nlogn).
*/


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),[&](vector<int> &a,vector<int>&b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        for(int i=0;i<v.size();i++){
           int index = lower_bound(dp.begin(),dp.end(),v[i][1])-dp.begin();
           if(index==dp.size()) dp.push_back(v[i][1]);
           dp[index] = v[i][1];
        }
        return dp.size();
    }
};