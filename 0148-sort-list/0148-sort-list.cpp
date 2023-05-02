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
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(!left)
          return right;

        if(!right)
          return left;

       ListNode* ans=new ListNode();
       ListNode* temp=ans;

       while(left and right)  {
           if(left->val < right->val){
               ans->next=new ListNode(left->val);
               left=left->next;
           }
           else{
               ans->next=new ListNode(right->val);
               right=right->next;
           }
           ans=ans->next;
       } 
       while(left){
           ans->next=new ListNode(left->val);
           left=left->next;
           ans=ans->next;
       }
       while(right){
           ans->next=new ListNode(right->val);
           right=right->next;
           ans=ans->next;
       }
       return temp->next;
    }

    ListNode* sortList(ListNode* head) {
       if(head==NULL or head->next==NULL)
       return head;

       ListNode* mid=findMid(head);
       ListNode* right=head;
       ListNode* left=mid->next;
       mid->next=NULL;

       left=sortList(left);
       right=sortList(right);

       ListNode* ans=merge(left,right);
       return ans;
    }
};