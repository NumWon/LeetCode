class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if t == s or not s:
            return True
        
        s_idx = 0
        for ch in t:
            if ch == s[s_idx]:
                s_idx += 1
                if s_idx >= len(s):
                    return True
        return False