#!/usr/local/bin/python3

from tkinter import *
root = Tk()
c = Canvas(width=300, height=300, bg='white')
c.focus_set()
c.pack()
 
ball = c.create_oval(140, 140, 160, 160, fill='green')

root.mainloop()