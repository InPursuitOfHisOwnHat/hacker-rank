import re
import sys

# txt = "The rain in Spain"
# x = re.search("^The.*Spain$", txt)

num_test_cases = int(sys.stdin.readline().rstrip())

for i in range(0, num_test_cases):
    pattern = sys.stdin.readline().rstrip()
    try:
        re.compile(pattern)
        print("True")
    except:
        print("False")
