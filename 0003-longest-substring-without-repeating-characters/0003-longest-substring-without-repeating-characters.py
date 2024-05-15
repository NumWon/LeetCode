class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        substr = ""
        max_len = 0
        
        for i in range(0, len(s)):
            if s[i] in substr:
                if len(substr) > max_len:
                    max_len = len(substr)
                substr += s[i]
                substr = substr[substr.index(s[i])+1:]
            else:
                substr += s[i]
                if len(substr) > max_len:
                    max_len = len(substr)
                    
        return max_len