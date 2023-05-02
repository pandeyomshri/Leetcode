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

    ListNode* sortList(ListNode* head) {
        
        map<int, int> mp;
        ListNode* temp=head;

        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* ans=new ListNode();
         ListNode* ans2=ans;
        for(auto it:mp){
            while(it.second--){
                ans->next=new ListNode(it.first);
                ans=ans->next;
                cout<<it.first<<" ";
            }
        }
        return ans2->next;
        
    }
};