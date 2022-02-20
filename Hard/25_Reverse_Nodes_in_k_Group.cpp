//https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
   It's a linked list problem.
   Solved this problem using reverse algorithm.
   Time complexity O(n)
   space complexity O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        int numofnodes = 0;
        ListNode* current = head;
        
        while(current!=NULL){
            numofnodes++;
            current = current->next;
        }
        
        current = head;
        ListNode* nex = NULL;
        ListNode* previous = dummy;
        
        while(numofnodes>=k){
            current = previous->next;
            nex = current->next;
            for(int i=1;i<k;i++){
                current->next = nex->next;
                nex->next = previous->next;
                previous->next = nex;
                nex = current->next;
            }
            previous = current;
            numofnodes-=k;
        }
        
        return dummy->next;
    }
};