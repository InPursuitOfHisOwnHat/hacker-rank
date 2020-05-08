# Ugh - Didn't read the question properly...Hex needs to be capitalised!
def print_formatted(number):
   for i in range(1, number+1):
        output_str = '{0:>{length}} {0:>{length}o} {0:>{length}X} {0:>{length}b}'.format(i, length=len('{0:b}'.format(n)))
        print(output_str)

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)