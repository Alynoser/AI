import boards
import copy
branch_num = 0


def increment_branch_num():
    global branch_num
    branch_num += 1


def clear_branch_num():
    global branch_num
    branch_num = 0


def exchange(source, target, new_board):
    new_board[source], new_board[target] = new_board[target], new_board[source]
    return new_board


def move_blank(direction, new_board):
    blank = find_blank(new_board.get_board())
    if direction == 'left':
        if blank % 3 != 0:
            t_col = (blank % 3) - 1
            t_row = int(blank / 3)
            new_board.set_board(exchange(blank, t_row * 3 + t_col, new_board.get_board()))
    if direction == 'right':
        if blank % 3 != 2:
            t_col = (blank % 3) + 1
            t_row = int(blank / 3)
            new_board.set_board(exchange(blank, t_row * 3 + t_col, new_board.get_board()))
    if direction == 'up':
        if int(blank / 3) != 0:
            t_col = (blank % 3)
            t_row = int(blank / 3) - 1
            new_board.set_board(exchange(blank, t_row * 3 + t_col, new_board.get_board()))
    if direction == 'down':
        if int(blank / 3) != 2:
            t_col = (blank % 3)
            t_row = int(blank / 3) + 1
            new_board.set_board(exchange(blank, t_row * 3 + t_col, new_board.get_board()))
    return new_board


def branch(board):
    blank_index = find_blank(board.get_board())
    branch = []
    if blank_index % 3 != 0:
        new_board1 = copy.deepcopy(board)
        new_board1.set_depth(board.get_depth() + 1)
        new_board1 = move_blank('left', new_board1)
        branch.append(new_board1)
    if blank_index % 3 != 2:
        new_board2 = copy.deepcopy(board)
        new_board2.set_depth(board.get_depth() + 1)
        move_blank('right', new_board2)
        branch.append(new_board2)
    if int(blank_index / 3) != 0:
        new_board3 = copy.deepcopy(board)
        new_board3.set_depth(board.get_depth() + 1)
        move_blank('up', new_board3)
        branch.append(new_board3)
    if int(blank_index / 3) != 2:
        new_board4 = copy.deepcopy(board)
        new_board4.set_depth(board.get_depth() + 1)
        move_blank('down', new_board4)
        branch.append(new_board4)
    return branch


def clone(old_board):
    increment_branch_num()
    return boards.Board(old_board.get_board(), old_board.get_depth() + 1, branch_num)


def find_blank(board):
    blank = None
    for i in board:
        if board[i] == 0:
            blank = i
            break
    return blank


def __eq__(board, end_board):
    return board == end_board


def misplaced_tiles(curr, goal):
    h = 0
    for i in range(0, 8):
        if curr[i] != goal[i]:
            h = h + 1
    return h


# Calculates the H value misplaced tiles
def manhattan(curr, goal):
    h = 0
    for i in range(0, 8):
        n = curr[i]
        for j in range(0, 8):
            if goal[j] == n:
                curr_row = i / 3
                curr_column = i % 3
                goal_row = j / 3
                goal_column = j % 3
                h = h + (abs(curr_row - goal_row) + abs(curr_column - goal_column))
    return h
