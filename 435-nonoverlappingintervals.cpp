class Solution:
    def eraseOverlapIntervals(self, intervals):
        intervals.sort(key=lambda x: x[1])
        end = float('-inf')
        count = 0
        for start, finish in intervals:
            if start >= end:
                end = finish
            else:
                count += 1
        return count
