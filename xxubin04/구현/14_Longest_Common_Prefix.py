class Solution(object):
    def longestCommonPrefix(self, strs):
        ans = ""
        sList = [list(i) for i in strs]
        sList.sort(key=len)
        for i in range(len(sList[0])):
            for j in sList[1:]:
                if sList[0][:i+1] != j[:i+1]:
                    return "".join(ans)
            ans = sList[0][:i+1]
        return "".join(ans)