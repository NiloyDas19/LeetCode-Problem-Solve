//https://leetcode.com/problems/count-sorted-vowel-strings/


/*
   It's a simple dp problem.
   TC: O(n).
*/



class Solution {
public:
    int countVowelStrings(int n) {
        vector<char>ch = {'a','e','i','o','u'};
        unordered_map<char,int>v;
        int ans = 5;
        n--;
        v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
        while(n--){
            int demo = 0;
            for(auto &it:ch){
                demo+=ans;
                int newval = ans;
                ans-=v[it];
                v[it] = newval;
                
            }
            ans = demo;
        }
        return ans;
    }
};