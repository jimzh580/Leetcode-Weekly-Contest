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
        vector<int> nums;
        auto* p=head;
        while(p!=NULL){
            nums.push_back(p->val);
            p=p->next;
        }
        
        stack<int> ss;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            while(!ss.empty()&&nums[ss.top()]<nums[i]){
                int t=ss.top();
                ss.pop();
                ans[t]=nums[i];
            }
            ss.push(i);
        }
        return ans;
    }
};