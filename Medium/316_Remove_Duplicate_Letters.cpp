//https://leetcode.com/problems/remove-duplicate-letters/

/*
 It's a cool problem on Stack based.
 [Best explanation : ](https://leetcode.com/problems/remove-duplicate-letters/discuss/1859410/JavaC%2B%2B-DETAILED-%2B-VISUALLY-EXPLAINED-!!)
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> visit(26,false);
        vector<int> fre(26,0);
        for(int i=0;i<s.size();i++){
            fre[s[i]-'a']++;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            fre[s[i]-'a']--;
            while(!st.empty() && visit[s[i]-'a']==false && s[i] < st.top() && fre[st.top()-'a']>0){
                visit[st.top()-'a'] = false;
                st.pop();
            }
            if(visit[s[i]-'a'] == false) st.push(s[i]),visit[s[i]-'a'] = true;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};