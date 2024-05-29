class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rotated;
        int x = nums.size() - (k % nums.size());
        
        for(int i = 0; i < nums.size(); i++) {
            rotated.push_back(nums[(x+i)%nums.size()]);
        }
        nums = rotated;
    }
};