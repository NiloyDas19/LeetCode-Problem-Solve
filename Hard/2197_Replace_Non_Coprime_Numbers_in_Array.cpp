//https://leetcode.com/problems/replace-non-coprime-numbers-in-array/


class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(auto &it:nums){
            int curr = it;
            while(!st.empty() && __gcd(curr,st.back()) > 1){
                long long lc = (curr*st.back()*1LL)/__gcd(curr,st.back());
                curr = lc;
                st.pop_back();
            }
            st.push_back((int)curr);
        }
        return st;
    }
};