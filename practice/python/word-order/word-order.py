import sys
from collections import Counter

# Thought this would be a groupby thing, but actually Counter is better!

num_words = int(sys.stdin.readline().rstrip())
words =[]
for i in range(num_words):
    words.append(sys.stdin.readline().rstrip())

counts = Counter(words)
print('{0}'.format(len(counts)))
for s in Counter(words):
    print('{0}'.format(counts[s]), end=' ')
