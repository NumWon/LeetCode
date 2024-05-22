class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_t = {}
        t_s = {}
        
        for ch_s, ch_t in zip(s, t):
            if ch_s in s_t:
                if s_t[ch_s] != ch_t:
                    return False
            else:
                s_t[ch_s] = ch_t
            if ch_t in t_s:
                if t_s[ch_t] != ch_s:
                    return False
            else:
                t_s[ch_t] = ch_s
        return True