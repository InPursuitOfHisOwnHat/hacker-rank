import sys

num_test_cases = int(sys.stdin.readline().rstrip())

for i in range(0, num_test_cases):
    a,b = sys.stdin.readline().split()
    try:
        c = int(a)//int(b)
        print(c)
    except ZeroDivisionError as e:
        print("Error Code: {0}".format(e))
    except ValueError as e:
        print("Error Code: {0}".format(e))
