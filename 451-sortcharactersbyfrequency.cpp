class Solution:
    def frequencySort(self, s):
        from collections import Counter
        count = Counter(s)
        return ''.join([char * freq for char, freq in count.most_common()])
