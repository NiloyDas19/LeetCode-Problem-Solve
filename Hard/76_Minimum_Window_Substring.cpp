//https://leetcode.com/problems/minimum-window-substring/

/*
   Solved this problem using two pointer approach.
*/


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> fort,fors;
        for(auto it:t) fort[it]++;
        
        
        int left=0,right=0,ans=INT_MAX,check = fort.size(),cnt=0,l=0;
        for(int i=0;i<s.size();i++){
            fors[s[i]]++;
            if(fort[s[i]] && fors[s[i]]==fort[s[i]]) cnt++;
            while(cnt==check && l<=i){
                if(ans>i+1-l){
                    ans = i+1-l;
                    left = l;
                    right = i+1;
                }
                fors[s[l]]--;
                if(fort[s[l]] && fors[s[l]] < fort[s[l]]) cnt--;
                l++;
            }
        }
        
        return s.substr(left,right-left);
        
    }
};