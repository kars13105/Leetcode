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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int>c;
        int cnt = 1;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(temp->next!= NULL && temp->next->next != NULL)
            {
                if((temp->next->val > temp->next->next->val && temp->next->val > temp->val) || (temp->next->val < temp->next->next->val && temp->next->val < temp->val)) 
                {
                    c.push_back(cnt);
                }
                cnt++;
                
            }
            temp = temp->next;
        }
        int n = c.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i =0;i<n-1;i++)
        {
            mini = min(mini, c[i+1]-c[i]);
            
        }
        if(n < 2)
            return {-1, -1};

        vector<int> ans(2);
        ans[0] = mini;
        ans[1] = c[n-1] - c[0];

        return ans;



    }
};