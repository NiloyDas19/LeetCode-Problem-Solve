//https://leetcode.com/problems/evaluate-division/


/*
 Problem based on DFS.
*/



class Solution {
    map<string,vector<pair<string,double>>> m;
    map<string,bool> visit;
    int cnt = 0;
    double ans = -1.0;
public:
    void dfs(string &source,string &destination,double &a){
        if(source==destination){
            cnt++;
            ans = a;
            return;
        }
        
        if(cnt>=2) return;
        visit[source] = true;
        if(m[source].size()>0){
            for(auto &it:m[source]){
                double a1 = a*it.second;
                if(visit[it.first]==false) dfs(it.first,destination,a1);
                if(cnt>=2) return;
            }
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
    
        for(int i=0;i<n;i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],(1.0/values[i])});
            visit[equations[i][0]] = false;
            visit[equations[0][1]] = false;
        }
        
        vector<double>re;
        for(int i=0;i<queries.size();i++){
            if(m[queries[i][0]].size()==0 || m[queries[i][1]].size()==0){
                re.push_back(-1);
                continue;
            }
            for(auto &it:visit){
                it.second = false;
            }
            cnt = 0;
            double a = 1.0;
            dfs(queries[i][0],queries[i][1],a);
            (cnt) ? re.push_back(ans) : re.push_back(-1);
           
        }
        
        return re;
        
    }
};