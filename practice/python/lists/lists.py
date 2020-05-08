if __name__ == '__main__':
    N = int(input())
# Consider a list (list = []). You can perform the following commands:

# insert i e: Insert integer  at position .
# print: Print the list.
# remove e: Delete the first occurrence of integer .
# append e: Insert integer  at the end of the list.
# sort: Sort the list.
# pop: Pop the last element from the list.
# reverse: Reverse the list.
# Initialize your list and read in the value of  followed by  lines of commands where each command will be of the  types listed above. Iterate through each command in order and perform the corresponding operation on your list.

# Input Format

# The first line contains an integer, , denoting the number of commands.
# Each line  of the  subsequent lines contains one of the commands described above.

# Constraints

# The elements added to the list must be integers.
# Output Format

# For each command of type print, print the list on a new line.

# Sample Input 0

import sys


elems = []

commands = []
#Test setup - read from file
# command_file = 'commands.txt'
# f = open(command_file,'r')
# num_commands = int(f.readline().rstrip())

# for i in range(0, num_commands):
#     commands.append(f.readline().rstrip())
#     print('Loading Command: {0}'.format(commands[i]))

# Actual run
num_commands = N
for i in range(0, num_commands):
    commands.append(sys.stdin.readline().rstrip())

command = []
for i in range(0, num_commands):
    command = commands[i].split(' ')
    #print(command)
    if command[0] == 'insert':
        elems.insert(int(command[1]), int(command[2]))
    elif command[0] == 'print':
        print(elems)
    elif command[0] == 'remove':
        elems.remove(int(command[1]))
    elif command[0] == 'append':
        elems.append(int(command[1]))
    elif command[0] == 'sort':
        elems.sort()
    elif command[0] == 'pop':
        elems.pop()
    elif command[0] == 'reverse':
        elems.reverse()

