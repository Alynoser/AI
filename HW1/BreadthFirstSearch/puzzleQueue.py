import queue


class PuzzleQueue:

    # Initialization of the queue
    def __init__(self):
        self.queue = queue.PriorityQueue()

    # queue()
    # Purpose: Enter an item into the queue with a priority level
    # Input: board - a list of numbers that are acting as a puzzle board
    #            f - priority level
    def queue(self, board, f):
        if not self.queue.full():
            self.queue.put(f, board)
        else:
            print("Queue is full. Cannot accept more items.")

    # dequeue()
    # Purpose: Remove an item from the queue
    # Input: N/A
    # Output: Returns the item that has been removed from the queue
    def dequeue(self):
        item = -1
        if not self.queue.empty():
            item = self.queue.get()
        else:
            print("Queue is empty. Nothing to pull.")
        return item
