class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_counter = Counter(ransomNote)
        magazine_counter = Counter(magazine)
        
        for ch, count in ransom_counter.items():
            if magazine_counter[ch] < ransom_counter[ch]:
                return False
        return True