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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* response = new ListNode(head->val);
        int storage =  head->val;
        while(head != nullptr){
            if(storage != head->val){
                storage = head->val;
                ListNode* newListNode = new ListNode(head->val);
                ListNode* current = response;
                while(current->next){
                    current = current->next;
                }
                current->next = newListNode;

            }
            head = head->next;
        }
        
        return response;
    };
};

// BEST SOLUTION
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head;
        while (curr&&curr->next)
        {
            if (curr->next->val==curr->val)
            {
                curr->next=curr->next->next;
                continue;
            }
            curr=curr->next;
        }
        return head;
        
    }
};
