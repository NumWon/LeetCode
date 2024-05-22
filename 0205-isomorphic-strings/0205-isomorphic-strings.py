class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        
        my_dict = {}
        
        for i in range(len(s)):
            if s[i] not in my_dict:
                if t[i] not in my_dict.values():
                    my_dict[s[i]] = t[i]
                else:
                    return False
            elif my_dict[s[i]] != t[i]:
                return False
        return True