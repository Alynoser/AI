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

