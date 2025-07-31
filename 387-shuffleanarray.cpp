class Solution:
    def __init__(self, nums):
        self.nums = nums
        self.original = nums[:]

    def reset(self):
        return self.original

    def shuffle(self):
        import random
        arr = self.nums[:]
        for i in range(len(arr)):
            j = random.randint(i, len(arr) - 1)
            arr[i], arr[j] = arr[j], arr[i]
        return arr
