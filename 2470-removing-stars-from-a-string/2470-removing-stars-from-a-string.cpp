class Solution {
public:
    string removeStars(string s) {
        stack<int> stack;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] != '*') stack.push(s[i]);
            else stack.pop();
        }
        int size = stack.size();

        while(!stack.empty()) {
            s[stack.size()-1] = stack.top();
            stack.pop();
        }
        return s.substr(0, size);
    }
};