import sys


def checkparity(user_start):
    temp_start = user_start
    if 0 in temp_start:
        temp_start.remove(0)
        return temp_start


def makelist(user_start, user_end):
    new_start = []
    new_end = []
    for i in range(user_start):
        new_start[i] = int(user_start[i])
    for i in range(user_end):
        new_end[i] = int(user_end[i])
    return new_start, new_end


user_start = input("Please enter a starting set\n")
user_end = input("Please enter desired end set\n")

user_start = list(user_start)
print(user_start)
# user_start, user_end = makelist(user_start, user_end)


#user_start = checkparity(user_start)

