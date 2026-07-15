class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* temp = head;
        vector<int> v, k;

        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int l = 0;
        int r = v.size() - 1;

        while(l < r)
        {
            k.push_back(v[l]);
            k.push_back(v[r]);
            l++;
            r--;
        }

        if(l == r)
            k.push_back(v[l]);

        temp = head;

        for(int i = 0; i < k.size(); i++)
        {
            temp->val = k[i];
            temp = temp->next;
        }
    }
};