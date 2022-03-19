//https://leetcode.com/problems/maximum-frequency-stack/


/*
   Solved this problem using stack and map.
   TC : O(nlogn).
*/




class FreqStack {
public:
    map<int,stack<int>> st;
    unordered_map<int,int> mp;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        st[-mp[val]].push(val);
    }
    
    int pop() {
        auto it = st.begin();
        int ans = it->second.top();
        mp[ans]--;
        it->second.pop();
        if(it->second.size()==0){
            st.erase(it);
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */