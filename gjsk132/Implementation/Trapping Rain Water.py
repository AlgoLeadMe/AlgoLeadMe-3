class Solution:

    def trap(self, height: List[int]) -> int:

        rain = 0

        tmp = 0
        max_h = 0
        max_pos = 0

        for p, h in enumerate(height):
            if max_h <= h:
                max_h = h
                rain += tmp
                tmp = 0
                max_pos = p
            else:
                tmp += max_h-h
        
        tmp = 0
        max_h = 0
        print(rain)
        for h in height[-1:max_pos:-1]:
            if max_h <= h:
                max_h = h
                rain += tmp
                tmp = 0
            else:
                tmp += max_h-h

        if height[max_pos] >= h:
            rain += tmp
            
        return rain