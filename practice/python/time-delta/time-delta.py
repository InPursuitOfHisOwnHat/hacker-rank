#!/bin/python3

import math
import os
import random
import re
import sys
from datetime import datetime


# Complete the time_delta function below.
def time_delta(t1, t2):
    fmt = '%a %d %b %Y %H:%M:%S %z'
    t1date = datetime.strptime(t1, fmt)
    t2date = datetime.strptime(t2, fmt)
    return '{0:.0f}'.format(abs((t1date-t2date).total_seconds()))


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()
        t2 = input()

        delta = time_delta(t1, t2)

        fptr.write(delta + '\n')

    fptr.close()
