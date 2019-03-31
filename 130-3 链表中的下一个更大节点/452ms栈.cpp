/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        int len=0;
        for(ListNode *i=head;i;i=i->next,len++);
        res.resize(len);
        stack<pair<int,int>> s;
        int k=0;
        ListNode *p=head;
        while(p){
            while(!s.empty()&&p->val>s.top().first){
                res[s.top().second]=p->val;
                s.pop();
            }
            s.push(make_pair(p->val,k));
            k++;
            p=p->next;
        }
        return res;
    }
};