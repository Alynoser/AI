import re

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
				self.playboard[y][x] = j
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
		hasChanged=True
		while(hasChanged == True):
			hasChanged = False
			for y in range (9):
				for x in range (9):
					temp = self.playboard[y][x]
					if (int(temp) == 0):
						possible = self.find_avaliable(x,y)
						row = self.getRow(x)
						collum = self.getCollum(y)
						for i in range (9):
							if (((possible[i]==row[i])|(possible[i]==collum[i]))&(possible[i] !=0)):
								possible[i] = 0
						options = 0
						for i in range(9):
							if (possible[i] != 0):
								options = options + 1
						if (options == 1):
							for i in range(9):
								if (possible[i] != 0):
									move = possible[i]
							self.playboard[y][x] = move
							hasChanged = True


	def getRow(self,x):
		row = [0,0,0,0,0,0,0,0,0]
		for y in range(9):
			row[y] = self.playboard[y][x]
		return row

	def getCollum(self,y):
		collum = [0, 0, 0, 0, 0, 0, 0, 0, 0]
		for x in range(9):
			collum[x] = self.playboard[y][x]
		return collum

	def find_avaliable(self, xtp, ytp):
		x = int(xtp / 3)
		y = int(ytp / 3)
		tempboard = self.get_section(int(x),int(y))
		possible = [1,2,3,4,5,6,7,8,9]
		for i in range(3):
			for j in range(3):
				for k in range(9):
					if ((possible[k] == tempboard[(y*3)+i][(x*3)+j]) & (possible[k] != 0)):
						possible[k] = 0
		return possible





