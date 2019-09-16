import sys
import copy
# user_start
#  is the start point given by the user
# user_end
#  is the end point given by the user

# check_parity
# purpose: finds the parity of the start and end
#    goal and compaires to see if they have a solution
# Input: The user start position: user_start
#        The user end position: user_end
# Output:

def check_parity(user_start, user_end):
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
        exit()

#This asks the user for input, takes that input, and then turns it into a list of ints
def start_menu():
    user_start1 = input("Please enter first line of the start sequence\n")
    user_start2 = input("Enter second line\n")
    user_start3 = input("Enter third line\n")
    user_start = user_start1 + user_start2 + user_start3

    user_end1 = input("Please enter the first line of the desired end set\n")
    user_end2 = input("Enter second line\n")
    user_end3 = input("Enter third line\n")
    user_end = user_end1 + user_end2 + user_end3

    user_start = list(map(int, user_start))
    user_end = list(map(int, user_end))
    check_parity(user_start, user_end)

    while True:
        print("1. Breadth First Search apples\n"
              "2. Misplaced Tiles\n"
              "3. Manhattan Distance\n"
              "4. Gaschnig\n"
              "5. Close program")
        user_alg = int(input("Please choose an algorithm\n"))
        if 5 > user_alg < 1:
            print("You didnt not choose a valid algorithm")
        elif user_alg == 1:
            bredth_first_search(user_start, user_end)
        elif user_alg == 2:
            print("need to write")
        elif user_alg == 3:
            print("need to write")
        elif user_alg == 4:
            print("need to write")
        elif user_alg == 5:
            print("Thank you for being with us today")
            exit()


start_menu()
