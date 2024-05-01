class Solution(object):
    def plusOne(self, digits):
        global n
        n = ""
        for i in digits:
            n += str(i)
        n = int(n) + 1
        return list(map(int, list(str(n))))