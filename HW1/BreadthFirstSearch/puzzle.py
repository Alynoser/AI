class Board(object):

    def __init__(self, board=None, moves=0, previous=None):

        if board is None:
            self.board = [1, 2, 3, 4, 5, 6, 7, 8, 0]
        else:
            self.board = board
        self.previous = previous
        self.moves = moves

    def set_board(self, board):
        self.board = board

    def is_goal(self):
        for i in range(0, 9):
            if i != 8:
                if self.board[i] != i + 1:
                    return False
        return True

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
        return Board(self.board.copy(), self.moves + 1, self)

    def exchange(self, source, target):
        self.board[source], self.board[target] = self.board[target], self.board[source]

    def neighbours(self):
        blank_index = self.find_blank()
        neighbours = []
        if blank_index % 3 != 0:
            new_board = self.clone()
            new_board.move_blank('left')
            neighbours.append(new_board)
        if blank_index % 3 != 2:
            new_board = self.clone()
            new_board.move_blank('right')
            neighbours.append(new_board)
        if int(blank_index / 3) != 0:
            new_board = self.clone()
            new_board.move_blank('up')
            neighbours.append(new_board)
        if int(blank_index / 3) != 2:
            new_board = self.clone()
            new_board.move_blank('down')
            neighbours.append(new_board)
        return neighbours

    def __eq__(self, other):
        if other is None:
            return False
        else:
            return self.board == other.board
