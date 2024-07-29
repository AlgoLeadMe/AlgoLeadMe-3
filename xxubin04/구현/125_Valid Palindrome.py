from collections import deque

class Solution(object):
    def isPalindrome(self, s):
        ans = deque()
        s_list = list(s)
        for i in s_list:
            if i.isalnum():
                ans.append(i.lower())
        if ''.join(ans) ==  ''.join(reversed(ans)):
            return True
        return False