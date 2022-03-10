//https://leetcode.com/problems/add-two-numbers/

/*

  It's a LinkedList Problem.
  SC : O(n)
  TC : O(n)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result,*cpy;
        int d1 = l1->val,d2=l2->val,hand=0,ans=0;
        ans  = (d1+d2+hand)%10;
        hand = (d1+d2+hand)/10;
        result = new ListNode(ans);
        cpy  = result;
        l1 = l1->next;
        l2 = l2->next;
        while(l1!=NULL && l2!=NULL){
            d1 = l1->val;
            d2 = l2->val;
            ans  = (d1+d2+hand)%10;
            hand = (d1+d2+hand)/10;
            cpy->next = new ListNode(ans);
            l1 = l1->next;
            l2 = l2->next;
            cpy = cpy->next;
        }
        while(l1!=NULL){
            ans  = (l1->val+hand)%10;
            hand = (l1->val+hand)/10;
            cpy->next = new ListNode(ans);
            l1 = l1->next;
            cpy = cpy->next;
        }
        while(l2!=NULL){
            ans  = (l2->val+hand)%10;
            hand = (l2->val+hand)/10;
            cpy->next = new ListNode(ans);
            l2 = l2->next;
            cpy = cpy->next;
        }
        if(hand>0){
            cpy->next = new ListNode(hand);
        }
        return result;
    }
};