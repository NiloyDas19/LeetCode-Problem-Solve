//https://leetcode.com/problems/reverse-linked-list-ii/

/*
   Explanation : I just separate those part which will be reversed and then reverse those part.
                 Then join those part with the orginal one in required position.
                 
                orginal one               ---> 1 2 3 4 5   left-->2  right-->4
                separate one              ---> 2 3 4
                reverse one               ---> 4 3 2
                Add the required position ---> 1 4 3 2 5 

   Time Complexity: O(n)   here n--> node number.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* h_c1 = new ListNode();
        ListNode* h_c2 = new ListNode();
        
        h_c1 = h_c2 = head;
        
        vector<int> value;
        for(int i=1;i<=right;i++){
            if(i>=left&&i<=right) value.push_back(h_c1->val);
            h_c1 = h_c1->next;
        }
        
        int sz = value.size();
        for(int i=1;i<=right;i++){
            if(i>=left&&i<=right) h_c2->val = value[--sz];
            h_c2 = h_c2->next;
        }
        
        return head;
    }
};