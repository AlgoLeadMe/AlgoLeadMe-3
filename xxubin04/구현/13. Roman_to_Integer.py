class Solution(object):
    def romanToInt(self, s):
        total = 0
        dic1 = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        dic2 = {'IV':4, 'IX':9, 'XL':40, 'XC':90, 'CD':400, 'CM':900}
        check = [0 for _ in range(len(s))]
        for i in range(len(s)):
            if check[i] != 0:
                continue
            if s[i:i+2] in dic2:
                total += dic2[s[i:i+2]]
                check[i] = 1; check[i+1] = 1
            elif s[i] in dic1:
                total += dic1[s[i]]
                check[i] = 1
        return total