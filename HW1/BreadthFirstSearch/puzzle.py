import puzzleQueue
import oldmoves


class Board(object):

    def __init__(self, board=None, depth=0, previous=0):
        if board is None:
            self.board = [1, 2, 3, 4, 5, 6, 7, 8, 0]
        else:
            self.board = board
        self.previous = previous
        self.depth = depth

    def set_board(self, board, depth, previous):
        self.board = board
        self.depth = depth
        self.previous = previous

    def search_func(self, user_start, user_end, alg_num):
        pqueue = puzzleQueue.PuzzleQueue()
        nodecount =0
        self.set_board(user_start, user_end, 0)
        while True:
            if __eq__(user_start):
                return #junk
            else:

    def move_blank(self, where):
        blank = self.find_blank()
        if where == 'left':
            if blank % 3 != 0:
                t_col = (blank % 3) - 1
                t_row = int(blank / 3)
                self.exchange(blank, t_row * 3 + t_col)
        if where == 'right':
            if blank % 3 != 2:
                t_col = (blank % 3) + 1
                t_row = int(blank / 3)
                self.exchange(blank, t_row * 3 + t_col)
        if where == 'up':
            if int(blank / 3) != 0:
                t_col = (blank % 3)
                t_row = int(blank / 3) - 1
                self.exchange(blank, t_row * 3 + t_col)
        if where == 'down':
            if int(blank / 3) != 2:
                t_col = (blank % 3)
                t_row = int(blank / 3) + 1
                self.exchange(blank, t_row * 3 + t_col)

    def find_blank(self):
        blank = None
        for i in range(0, 9):
            if self.board[i] == 0:
                blank = i
                break
        return blank

    def clone(self):
        return Board(self.board.copy(), self.depth + 1, self.previous)

    def exchange(self, source, target):
        self.board[source], self.board[target] = self.board[target], self.board[source]

    def branch(self):
        blank_index = self.find_blank()
        branch = []
        if blank_index % 3 != 0:
            new_board = self.clone()
            new_board.move_blank('left')
            branch.append(new_board)
        if blank_index % 3 != 2:
            new_board = self.clone()
            new_board.move_blank('right')
            branch.append(new_board)
        if int(blank_index / 3) != 0:
            new_board = self.clone()
            new_board.move_blank('up')
            branch.append(new_board)
        if int(blank_index / 3) != 2:
            new_board = self.clone()
            new_board.move_blank('down')
            branch.append(new_board)
        return branch

    def __eq__(self, board):
        return self.board == board

    # Calculates the H value for misplaced tiles
    def misplacedtiles(self, curr, goal):
        h = 0
        for i in range (0,8):
            if curr[i] != goal[i]:
                h = h+1
        return h

    # Calculates the H value misplaced tiles
    def manhattan(self, curr, goal):
        h = 0
        for i in range(0, 8):
            n = curr[i]
            for j in range(0, 8):
                if goal[j] == n:
                    curr_row = i/3
                    curr_column = i % 3
                    goal_row = j/3
                    goal_column = j % 3
                    h = h + (abs(curr_row-goal_row)+abs(curr_column-goal_column))
        return h
