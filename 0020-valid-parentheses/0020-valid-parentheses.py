class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                stack.append(ch)
            if ch == ')': 
                if len(stack) <= 0 or stack.pop() != '(':
                    return False
            elif ch == ']':
                if len(stack) <= 0 or stack.pop() != '[':
                    return False
            elif ch == '}':
                if len(stack) <= 0 or stack.pop() != '{':
                    return False
        if len(stack) == 0:
            return True
        return False
                
                