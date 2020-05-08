import sys
from itertools import combinations

list_len = int(sys.stdin.readline().rstrip())
list_elem = sys.stdin.readline().rstrip().split(' ')
no_indices = int(sys.stdin.readline().rstrip())

list_combinations = list(combinations(sorted(list_elem), no_indices))
a_is_index_count=0
for t in list_combinations:
    if ( t[0] == 'a'):
        a_is_index_count += 1

print('{0:3f}'.format(a_is_index_count / len(list_combinations)))
