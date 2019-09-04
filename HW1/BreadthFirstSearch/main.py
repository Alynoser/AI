import sys


def checkparity(user_start):
    temp_start = user_start
    if 0 in temp_start:
        temp_start.remove(0)
        return temp_start





user_start = input("Please enter a starting set\n")
user_end = input("Please enter desired end set\n")
user_start = list(map(int, user_start))
user_start = list(user_start)


# user_start, user_end = makelist(user_start, user_end)


#user_start = checkparity(user_start)

