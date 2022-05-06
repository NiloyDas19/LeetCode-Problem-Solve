//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

/*
 Stack based problem.
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                auto  it = st.top();
                if(it.first==s[i]){
                    st.pop();
                    st.push({it.first,it.second+1});
                }
                else{
                    st.push({s[i],1});
                }
            }
            
            auto it = st.top();
            if(it.second == k){
                st.pop();
            }
        }
        
        string ans;
        while(!st.empty()){
            while(st.top().second--){
              ans.push_back(st.top().first);
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};