import board

filename = input("Enter the file name\n")

tempboard = board.Board()
tempboard.set_board(filename)
tempboard.print_board()
tempboard.firstRec()
tempboard.print_board()