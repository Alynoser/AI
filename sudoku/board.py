import re
import copy

class Board:

	def __init__(self):
		self.playboard = [[0 for x in range(9)] for y in range(9)]

	def set_board(self, filename):
		file = open(filename,"r")
		y = 0
		for line in file:
			x = 0 
			temp = line
			temp = re.sub(',', '', temp)
			temp = re.sub(' ', '', temp)
			temp = re.sub('\n', '', temp)
			for j in temp:
				self.playboard[y][x] = int(j)
				x = x + 1
			y = y + 1

	def print_board(self):
		x = 0
		y = 0
		for y in range(8):
			print()
			for x in range(8):
				print (self.playboard[y][x], end = " ")
		print()

	def get_section(self, ytp, xtp):
		tempboard = [[0 for i in range(3)] for j in range(3)]

		for y in range(3):
			for x in range(3):
				tempboard[y][x] = self.playboard[(ytp*3) + y][(xtp*3) + x]
		return tempboard

	def set_board_section(self, ytp, xtp, tempboard):

		for y in range(3):
			for x in range(3):
				self.playboard[(ytp*3) + y][(xtp*3) + x] = tempboard[y][x]

	def solve(self):
		fewestOptions = 100
		xFew = -1
		yFew = -1
		for y in range (9):
			for x in range (9):
				temp = self.playboard[y][x]
				if (int(temp) == 0):
					possible = self.find_avaliable(x,y)
					row = self.getRow(x)
					row.sort()
					collum = self.getCollum(y)
					collum.sort()
					for i in range (9):
						for j in range (9):
							if (((possible[i]==row[j])|(possible[i]==collum[j]))&(possible[i] !=0)):
								possible[i] = 0
					options = 0
					for i in range(9):
						if (possible[i] != 0):
							options = options + 1
					if (options < fewestOptions):
						fewestOptions = options
						xFew = x
						yFew = y
		fewest = [xFew, yFew, fewestOptions]
		return(fewest)


	def getRow(self,x):
		row = [0,0,0,0,0,0,0,0,0]
		for y in range(9):
			temp = self.playboard[y][x]
			row[y] = int(temp)
		return row

	def getCollum(self,y):
		collum = [0, 0, 0, 0, 0, 0, 0, 0, 0]
		for x in range(9):
			temp = self.playboard[y][x]
			collum[x] = int(temp)
		return collum

	def find_avaliable(self, xtp, ytp):
		x = int(xtp / 3)
		y = int(ytp / 3)
		tempboard = self.get_section(int(x),int(y))
		possible = [1,2,3,4,5,6,7,8,9]
		for i in range(3):
			for j in range(3):
				for k in range(9):
					temp =  tempboard[i][j]
					if (possible[k] == int(temp)) & (possible[k] != 0):
						possible[k] = 0
		return possible

	def remove_values_from_list(self, the_list, val):
		return [value for value in the_list if value != val]

	def recsolve(self, x, y, tempvar, tempboard):
		boardtp = copy.deepcopy(tempboard)
		boardtp[y][x] = tempvar
		if not boardtp.valid_board():
			return False
		ops = self.fewest_options(boardtp)
		if ops[2] == 0:
			return False
		if ops[0] == -1 and ops[1] == -1:
			return True
		oplist = self.get_options(ops[0], ops[1], boardtp)
		oplist = self.remove_values_from_list(oplist, 0)
		for i in oplist:
			retvar = self.recsolve(ops[0], ops[1], i, boardtp)
			if retvar:
				self.playboard[ops[0]][ops[1]] = i
				return True
		return False






