#!/usr/local/bin/python3

from tkinter import *
from time import time

clr_pl1 = '#ffaaaa'
clr_pl2 = '#aaffff'

buf = input()
while buf.find("Plateau") == -1:
	if buf.find("p1") != -1:
			player1 = buf.split('/')[3].split('.')[0]
	if buf.find("p2") != -1:
		player2 = buf.split('/')[3].split('.')[0]
	buf = input()

width_board = int(buf.split(' ')[2].split(':')[0])
height_board = int(buf.split(' ')[1])
stroka = ""
for i in range(width_board):
	stroka = stroka + str(i)

fillers = []
while 1:
	try:
		lines = []
		# if buf.find("Plateau") != -1 or buf.find(stroka) != -1:
		buf = input()
		buf = input()
		for i in range(height_board):
			lines.append(buf.split(' ')[1])
			buf = input()
		while buf.find("Plateau") == -1:
			# lines.append(buf)
			buf = input()
		fillers.append(lines)
	except EOFError:
		break

for i in fillers:
	print(i)

w_map = 900
h_map = 800

window = Tk()
window.title("Filler")
window.geometry('1000x900+900+300')
Label(window, text=player1, bg=clr_pl1).place(relx=0.01, rely=0.01, width=100, height=20)
Label(window, text=player2, bg=clr_pl2).place(relx=0.2, rely=0.01, width=100, height=20)

b1 = Button(text="Start", width=10, height=3)

def change():
	c = Canvas(window, width=900, height=900, bg='white')
	c.place(rely=0.06)
	c.create_rectangle(10, 10, w_map, h_map)
	for filler in filler:
		for i in range(width_board):
			for j in range(height_board):
				if filler[i][j] == '.':
					c.create_rectangle(i * 10, j * 10, 65, 85, fill='yellow', outline='green',width=3)



 
b1.config(command=change)
b1.place(relx=0.5)



# c.create_rectangle(60, 80, 65, 85, fill='yellow', outline='green',
#                     width=3)
window.mainloop()