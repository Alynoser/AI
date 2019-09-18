import boards

class oldmoves(object):

    def __init__(self):
        self.movelist = []

    def check_list(self, board):
        for i in self.movelist:
            if i == board:
                return False
        return True

    def add_to_list(self, board):
        self.movelist.append(board)
