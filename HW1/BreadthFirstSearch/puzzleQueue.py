import queue
import boards
import heapq
from dataclasses import dataclass, field
from typing import Any


@dataclass(order=True)
class PrioritizedItem:
    priority: int
    item: Any = field(compare=False)


class PuzzleQueue:

    # def __init__(self):
    #     self._queue = []
    #     self._index = 0
    #
    # def queueit(self, item, priority):
    #     heapq.heappush(self._queue, (-priority, self._index, item))
    #     self._index += 1
    #
    # def dequeue(self):
    #     return heapq.heappop(self._queue)[-1]
    #

    # Initialization of the queue
    def __init__(self):
        self.pqueue = queue.PriorityQueue()

    # queue()
    # Purpose: Enter an item into the queue with a priority level
    # Input: board - a list of numbers that are acting as a puzzle board
    #            f - priority level
    def queueit(self, board, f):
        if not self.pqueue.full():
            self.pqueue.put(PrioritizedItem(f, board))
        else:
            print("Queue is full. Cannot accept more items.")

    # dequeue()
    # Purpose: Remove an item from the queue
    # Input: N/A
    # Output: Returns the item that has been removed from the queue
    def dequeue(self):
        item = -1
        if not self.pqueue.empty():
            item = self.pqueue.get().item
        else:
            print("Queue is empty. Nothing to pull.")
        return item
