// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int i=0;
        ListNode* leftStart=dummy;
        for(int i=1;i<left;i++){
            leftStart = leftStart->next;
        }
        ListNode* cur=leftStart->next;
        ListNode* prev=nullptr;
        for(int i=left;i<=right;i++){
            ListNode* tmp1 = cur->next;
            cur->next=prev;
            prev = cur;
            cur = tmp1;
        }
        //swap 
        ListNode* tmp = leftStart->next;
        leftStart->next=prev;
        tmp->next = cur;

        return dummy->next;

    }
};
