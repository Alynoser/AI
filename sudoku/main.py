import board

filename = input("Enter the file name\n")

tempboard = board.Board()
tempboard.set_board(filename)
tempboard.print_board()
new = tempboard.get_section(0, 1)
print(new)
tempboard.set_board_section(0, 1, new)

tempboard.print_board()