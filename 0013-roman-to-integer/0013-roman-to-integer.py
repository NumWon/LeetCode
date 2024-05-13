class Solution:
    def romanToInt(self, s: str) -> int:
        numerals = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        value = numerals[s[0]]
        temp_value = numerals[s[0]]
        
        for i in range(1, len(s)):
            if numerals[s[i-1]] > numerals[s[i]]:
                value += numerals[s[i]]
                temp_value = numerals[s[i]]
            elif numerals[s[i-1]] == numerals[s[i]]:
                value += numerals[s[i]]
                temp_value = numerals[s[i]]
            else:
                value = value - temp_value * 2 + numerals[s[i]]
                temp_value = 0
                
        return value