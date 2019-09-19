import boards
import board_funcs
import oldmoves
import puzzleQueue
import copy


def search(search_num, user_start, user_end):
    # file = open("log.txt", 'a')
    oldmoveslist = oldmoves.oldmoves()
    pqueue = puzzleQueue.PuzzleQueue()
    board = boards.Board(user_start)
    end_board = boards.Board(user_end)
    if board_funcs.__eq__(board.get_board(), end_board.get_board()):
        return board.get_branch_num(), board.get_depth()
    else:
        oldboard = copy.copy(board.get_board())
        oldmoveslist.add_to_list(oldboard)
        while not board_funcs.__eq__(board.get_board(), end_board.get_board()):
            new_branches = board_funcs.branch(board)
            for i in new_branches:
                if oldmoveslist.check_list(i.get_board()):
                    # file.write(str(i.get_board()))
                    if search_num == 1:
                        # Breadth First Search
                        pqueue.queueit(i, i.get_branch_num())
                    elif search_num == 2:
                        h = board_funcs.misplaced_tiles(i.get_board(), end_board.get_board())
                        g = i.get_depth()
                        f = h + g
                        pqueue.queueit(i, f)
                    elif search_num == 3:
                        h = board_funcs.manhattan(i.get_board(), end_board.get_board())
                        g = i.get_depth()
                        f = h + g
                        pqueue.queueit(i, f)
                    elif search_num == 4:
                        print("Gausten")
                    else:
                        exit()
            if oldmoveslist.check_list(board.get_board()):
                oldmoveslist.add_to_list(board.get_board())
            board = pqueue.dequeue()
        board_funcs.clear_branch_num()
        return board.get_branch_num(), board.get_depth()