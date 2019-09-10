# TODO: Create queue somewhere.
class Queue:

    # Board: Grid to be Queued
    # curr_queue: Current Queue
    # Input: Takes in a board and the list of currently queued items.
    # Output: Returns the new list
    def queue(self, board, curr_queue):
        if not curr_queue.full():
            curr_queue.put(board)
        else:
            print("Queue is full. Cannot accept more items.")
        return curr_queue

    # curr_queue: Current Queue
    # Input: Takes in a list and de-queues the last item (if it exists).
    # Output: item from Queue and new list
    def dequeue(self, curr_queue):
        item = -1
        if not curr_queue.empty():
            item = curr_queue.get()
        else:
            print("Queue is empty. Nothing to pull.")
        return item, curr_queue

    # goal_board: Grid to match
    # curr_board: first item in list
    # Checks to make sure an end case has not been reached
    def compare(self, goal_board, curr_board):
        if goal_board == curr_board:
            print("Solution found!")