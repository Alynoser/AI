class oldmoves(object):

    def __init__(self):
        self.movelist = []

    def check_list(self, board, queue):
        for i in self.movelist:
            if self.movelist[i] == board:
                return
        queue.put(board)

    def add_to_list(self, board):
        self.movelist.append(board)
