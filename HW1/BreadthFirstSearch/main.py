import sys
import copy

def checkparity(user_start, user_end):
    temp_start = copy.copy(user_start)
    temp_end = copy.copy(user_end)
    if 0 in temp_start:
        temp_start.remove(0)
    if 0 in temp_end:
        temp_end.remove(0)
    start_count = 0
    end_count = 0
    for i in range(len(temp_start)):
        if temp_start[i] != i+1 and temp_start[i] > i+1:
            start_count += (temp_start[i] - (i+1))
    for i in range(len(temp_end)):
        if temp_end[i] != i+1 and temp_end[i] > i+1:
            end_count += (temp_end[i] - (i+1))
    print(start_count)
    print(end_count)
    start_count = start_count % 2
    end_count = end_count % 2
    if start_count == end_count:
        print("YAY")
    else:
        print("YOU SUCK!!!")



user_start = input("Please enter a starting set\n")
user_end = input("Please enter desired end set\n")
user_start = list(map(int, user_start))
user_end = list(map(int, user_end))
checkparity(user_start, user_end)

