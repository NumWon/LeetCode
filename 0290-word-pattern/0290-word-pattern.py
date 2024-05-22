class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        strings = s.split()
        
        if len(pattern) != len(strings):
            return False
        
        p_to_s = {}
        s_to_p = {}
        
        for ch_p, word_s in zip(pattern, strings):
            if ch_p in p_to_s:
                if p_to_s[ch_p] != word_s:
                    return False
            else:
                p_to_s[ch_p] = word_s
            if word_s in s_to_p:
                if s_to_p[word_s] != ch_p:
                    return False
            else:
                s_to_p[word_s] = ch_p
        return True