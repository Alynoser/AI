import board
import timeit
import os

output = open("results.txt", "w+")

directory = 'boards'
for filename in os.listdir(directory):
	if filename.endswith(".txt"):
		tmpfile = os.path.join(directory, filename)
		tempboard = board.Board()
		tempboard.set_board(tmpfile)
		tempboard.print_board()
		time1 = timeit.default_timer()
		tempboard.firstRec()
		time2 = timeit.default_timer()
		output.write(filename + " run time is: " + str(time2 - time1))
		tempboard.print_board()
	else:
		continue

