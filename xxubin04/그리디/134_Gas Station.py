class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1
        for i in range(len(gas)):
            tank = 0
            for g, c in zip(gas[i:] + gas[:i], cost[i:] + cost[:i]):
                tank = tank + g - c
                if tank < 0: break
            if tank >= 0: return i
        return -1