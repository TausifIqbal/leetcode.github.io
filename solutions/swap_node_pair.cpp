// https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        if(!head){
            return head;
        }
        ListNode* first = head;
        if(!head->next){
            return head;
        }
        ListNode* second = head->next;
        ListNode* prev=dummy;
        while(first && second){
            prev->next = second;
            ListNode* tmp = second->next;
            second->next=first;
            first->next = tmp;
            prev = first;
            first = tmp;

            if(!first){
                break;
            }
            second = first->next;
        }
        return dummy->next;

    }
};
