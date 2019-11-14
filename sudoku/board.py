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
		for y in range(9):
			print()
			for x in range(9):
				print (self.playboard[y][x], end = " ")
		print()

	def get_section(self, ytp, xtp, tempboard1):
		tempboard = [[0 for i in range(3)] for j in range(3)]

		for y in range(3):
			for x in range(3):
				tempboard[y][x] = tempboard1[(ytp*3) + y][(xtp*3) + x]
		return tempboard

	def set_board_section(self, ytp, xtp, tempboard):

		for y in range(3):
			for x in range(3):
				self.playboard[(ytp*3) + y][(xtp*3) + x] = tempboard[y][x]

	def findFewest(self,tempboard1):
		fewestOptions = 100
		xFew = -1
		yFew = -1
		for y in range (9):
			for x in range (9):
				temp = tempboard1[y][x]
				if (int(temp) == 0):
					options = 0
					possible = self.getOptions(y,x,tempboard1)
					for i in range(9):
						if (possible[i] != 0):
							options = options + 1
					if (options < fewestOptions):
						fewestOptions = options
						xFew = x
						yFew = y
		fewest = [yFew, xFew, fewestOptions]
		return(fewest)

	def getOptions(self,y,x,tempboard1):
		possible = self.find_avaliable(y,x,tempboard1)
		row = self.getRow(x,tempboard1)
		row.sort()
		collum = self.getCollum(y,tempboard1)
		collum.sort()
		for i in range(9):
			for j in range(9):
				if (((possible[i] == row[j]) | (possible[i] == collum[j])) & (possible[i] != 0)):
					possible[i] = 0
		return possible


	def getRow(self,x,tempboard1):
		row = [0,0,0,0,0,0,0,0,0]
		for y in range(9):
			temp = tempboard1[y][x]
			row[y] = int(temp)
		return row

	def getCollum(self,y,tempboard1):
		collum = [0, 0, 0, 0, 0, 0, 0, 0, 0]
		for x in range(9):
			temp = tempboard1[y][x]
			collum[x] = int(temp)
		return collum

	def find_avaliable(self, ytp, xtp,tempboard1):
		x = int(xtp / 3)
		y = int(ytp / 3)
		tempboard = self.get_section(int(y),int(x),tempboard1)
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

	def firstRec(self):
		tempboard = copy.deepcopy(self.playboard)
		ops = self.findFewest(tempboard)
		if ops[2] == 0:
			return False
		if ops[0] == -1 and ops[1] == -1:
			return True
		oplist = self.getOptions(ops[0], ops[1], tempboard)
		oplist = self.remove_values_from_list(oplist, 0)
		for i in oplist:
			retvar = self.recsolve(ops[0], ops[1], i, tempboard)
			if retvar:
				self.playboard[ops[0]][ops[1]] = i
				return True
		return False

	def recsolve(self, y, x, tempvar, tempboard):
		boardtp = copy.deepcopy(tempboard)
		boardtp[y][x] = tempvar
		if self.isValid(boardtp)==False:
			return False
		ops = self.findFewest(boardtp)
		if ops[2] == 0:
			return False
		if ops[0] == -1 and ops[1] == -1:
			return True
		oplist = self.getOptions(ops[0], ops[1], boardtp)
		oplist = self.remove_values_from_list(oplist, 0)
		for i in oplist:
			retvar = self.recsolve(ops[0], ops[1], i, boardtp)
			if retvar:
				self.playboard[ops[0]][ops[1]] = i
				return True
		return False

	def isValid(self,tempboard1):
		for y in range(9):
			for x in range(9):
				if self.checkSpot(y,x,tempboard1) == False:
					return False


	def checkSpot(self,yo,xo,tempboard1):
		row = self.getRow(xo,tempboard1)
		collum = self.getCollum(yo,tempboard1)
		xtp = int(xo/3)
		ytp = int(yo/3)
		tempboard = self.get_section(ytp,xtp,tempboard1)
		value = tempboard1[yo][xo]
		for i in range (3):
			for j in range(3):
				if ((((xtp*3)+i) == xo) & (((ytp*3)+j) == yo)):
					pass
				elif (tempboard[j][i] == 0):
					pass
				elif tempboard[j][i] == value:
					return False
		for k in range (9):
			if k == yo:
				pass
			elif row[k] == 0:
				pass
			elif row[k] == value:
				return False
		for l in range (9):
			if l == xo:
				pass
			elif collum[l] == 0:
				pass
			elif collum[l] == value:
				return False
		return True





