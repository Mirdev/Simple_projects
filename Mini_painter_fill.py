# -*- coding: utf-8 -*-

board = [[1, 1, 2, 2, 2, 2],
         [1, 1, 1, 3, 3, 2],
         [1, 1, 3, 3, 3, 2],
         [4, 5, 5, 3, 3, 2],
         [4, 1, 1, 3, 2, 2],
         [4, 4, 1, 3, 3, 2]]

# mini_board : paint board
# x, y : column and row for selected pixel
# color : new color
# fill all around same color of selected pixel
def fill(mini_board, x, y, color):
    d = mini_board[y][x]
    mini_board[y][x] = color
    if x>-1 and d == mini_board[y][x-1] : fill(mini_board, x-1, y, color)
    if x<5 and d == mini_board[y][x+1] : fill(mini_board, x+1, y, color)
    if y>-1 and d == mini_board[y-1][x] : fill(mini_board, x, y-1, color)
    if y<5 and d == mini_board[y+1][x] : fill(mini_board, x, y+1, color)

# print board
def show(mini_board):
    for row in mini_board:
        for item in row:
            print(item, end = " ")
        print() 

# show initial board
show(board)

while True:
    print ('please intert key..')
    print ('f -> fill q -> quit')

    # input command
    cmd = input()

    if cmd == 'f':
        print ('insert x, y index & color')

        # get indices and color with space separator
        index = input()
        x, y, color = map(int, index.split(' '))

        try:
            fill(board, x, y, color)
        except:
            print ('invalid index')
        show(board)

    elif cmd == 'q': # if input value is 'q' then close this programm
        break
    else:
        print ('no command available')
