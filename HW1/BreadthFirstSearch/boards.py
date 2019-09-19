# Chris Borg, Elysha Menefee, Ryan Richter
# cjborg@alaska.edu, emmenefee@alaska.edu, rdrichter@alaska.edu


class Board(object):

    def __init__(self, board=None, depth=0, branch_num=0):
        self.board = board
        self.depth = depth
        self.branch_num = branch_num

    def set_board_def(self, board, depth, branch_num):
        self.board = board
        self.depth = depth
        self.branch_num = branch_num

    def set_board(self, board):
        self.board = board

    def set_depth(self, depth):
        self.depth = depth

    def set_branch_num(self, branch_num):
        self.branch_num = branch_num

    def get_board(self):
        return self.board

    def get_depth(self):
        return self.depth

    def get_branch_num(self):
        return self.branch_num
