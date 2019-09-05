import sys
import copy
# user_start
#  is the start point given by the user
# user_end
#  is the end point given by the user


# TODO: Create queue somewhere.

# node: Object to be Queued
# curr_queue: Current Queue
# Input: Takes in a node and the list of currently queued items.
# Output: Returns the new list
def queue(node, curr_queue):
    if not curr_queue.full():
        curr_queue.put(node)
    else:
        print("Queue is full. Cannot accept more items.")
    return curr_queue


# curr_queue: Current Queue
# Input: Takes in a list and de-queues the last item (if it exists).
# Output: item from Queue and new list
def dequeue(curr_queue):
    item = -1
    if not curr_queue.empty():
        item = curr_queue.get()
    else:
        print("Queue is empty. Nothing to pull.")
    return item, curr_queue


# goal_node: Grid to match
# curr_node: first item in list
# Checks to make sure an end case has not been reached
def compare(goal_node, curr_node):
    if goal_node == curr_node:
        print("Solution found!")


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
