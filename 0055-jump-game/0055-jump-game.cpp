class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dest = nums.size()-1;
        int pos = dest-1;
        
        while(pos >= 0) {
            if(pos + nums[pos] < dest) {
                pos--;
            } else {
                dest = pos;
                pos--;
            }
        }
        
        if(dest <= 0) {
            return true;
        }
        return false;
    }
};