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
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        // vector<int>v;
        // while(temp!=NULL)
        // {
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        stack<int>st;
      //  st.push(head->val);
        while(temp!=NULL)
        {
            // if(st.empty())
            // {
                
            // }
            if(st.empty() || st.top()>=temp->val)
            {
                st.push(temp->val);
                temp = temp->next;
                continue;
            }
            while(!st.empty() && st.top()<temp->val)
            {
                st.pop();
            }
            st.push(temp->val);
            temp = temp->next;
        }
        stack<int>bt;
        ListNode* node = new ListNode(5);
        ListNode* dummy = node;

        while(!st.empty())
        {
            bt.push(st.top());
            st.pop();
        }
        while(!bt.empty())
        {
            dummy->next = new ListNode(bt.top());
            dummy = dummy->next;
            bt.pop();
        }
        return node->next;

    }
};