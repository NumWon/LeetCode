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
    int numComponents(ListNode* head, vector<int>& nums) {
        int components = 1;

        if(nums.size() == 1) return 1;
        while(find(nums.begin(), nums.end(), head->val) == nums.end()) head = head->next;
        
        while(head && nums.size() > 0) {
            auto it = find(nums.begin(), nums.end(), head->val);
            if(it != nums.end()){
                iter_swap(it, nums.rbegin());
                nums.pop_back();
                head = head->next;
            } else {
                while (find(nums.begin(), nums.end(), head->val) == nums.end()) {
                    head = head->next;
                }
                if(head) components++;
            }
        }
        return components;
    }
};