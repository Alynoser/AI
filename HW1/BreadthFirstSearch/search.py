import boards
import board_funcs
import oldmoves
import puzzleQueue


def search(search_num, user_start, user_end):
    oldmoveslist = oldmoves.oldmoves()
    pqueue = puzzleQueue.PuzzleQueue()
    board = boards.Board(user_start)
    end_board = boards.Board(user_end)
    if board_funcs.__eq__(board.get_board(), end_board.get_board()):
        return board.get_branch_num(), board.get_depth()
    else:
        oldmoveslist.add_to_list(board)
        while board_funcs.__eq__(board.get_board(), end_board.get_board()):
            new_branches = board_funcs.branch(board)
            for i in new_branches:
                if oldmoveslist.check_list(new_branches[i]):
                    if search_num == 1:
                        # ("Breadth first search")
                        pqueue.queue(new_branches[i], new_branches[i].get_branch_num())
                    if search_num == 2:
                        print("Misplaced tiles")
                    if search_num == 3:
                        print("Manhatten")
                    if search_num == 4:
                        print("Gausten")
                    else:
                        print("What you think u doin?")
                        exit()
            if oldmoveslist.check_list(board):
                oldmoveslist.add_to_list(board)
            board = pqueue.dequeue()
        board_funcs.clear_branch_num()
        return board.get_branch_num(), board.get_depth()
