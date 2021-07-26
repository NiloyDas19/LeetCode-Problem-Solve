//https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

/*
 It's a hard problem.
 First I tried to find a pattern to solve this problem.
 The pattern was like fibonacci number.
 TC -> O(logn)
*/


class Solution {
public:
    int findIntegers(int n) {
        vector<int>binary;
        while(n!=0){
            binary.push_back(n%2);
            n/=2;
        }
        int fib[31];fib[0] = 1,fib[1] = 2;
        for(int i=2;i<31;i++) fib[i] = fib[i-1]+fib[i-2];
        
        int ans = 0;
        for(int i=binary.size()-1;i>=0;i--) {
            if(binary[i]) ans+=fib[i];
            if(i!=0&&binary[i]&&binary[i-1]) return (ans+fib[i-1]);
        }
        return ans+1;
    }
};