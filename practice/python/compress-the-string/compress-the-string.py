import sys
from itertools import groupby

input = list(sys.stdin.readline().rstrip())

#Key will be the item itself

groups = []
for k, g in groupby(input):
    #print(k, list(g))
    print('({0}, {1})'.format(len(list(g)), k), end=' ')
