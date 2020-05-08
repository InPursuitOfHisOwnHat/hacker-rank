#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter


if __name__ == '__main__':
    s = input()

    
# Problem is we need to sort left hand of the tuple by Descending then the right hand of the tuple by Ascending so can't use use some sort parameter. 
# Instead, negate the count in the key so that the higher counts appear at the top and we can sort the right hand normally. This method was found 
# after some googling, admittedly - annoying that the solution was so simple, as always.
c = Counter(s)
counter_sorted = sorted(c.items(), key=lambda x: (-x[1], x[0]))


for i in counter_sorted[:3]:
    print('{0} {1}'.format(i[0], i[1]))


