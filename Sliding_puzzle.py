import random
import os

def initiate_puzzle(size):
    puzzle = []
    for i in range(1, size**2, 3):
        puzzle.append(list(range(i, i+3)))
    puzzle[-1][-1] = ' '
    return puzzle

def show_puzzle(puzzle):
    for row in puzzle:
        print(" ".join(map(str, row)))

def shuffle_puzzle(puzzle):
    cnt = 0
    while cnt <= 300:
        dx, dy = int(random.random()*3)-1, int(random.random()*3)-1

        i, j = get_index(puzzle, ' ')
        n_i, n_j = i + dx, j + dy

        if 0 <= n_i < len(puzzle) and 0 <= n_j < len(puzzle[0]):
            puzzle[n_i][n_j], puzzle[i][j] = puzzle[i][j], puzzle[n_i][n_j]
            cnt += 1

def get_index(puzzle, n):
    xy = sum(puzzle, []).index(n)
    return xy//len(puzzle), xy%len(puzzle)

def move_by_number(puzzle, n):
    i, j = get_index(puzzle, n)
    a = False
    if i > 0 and puzzle[i-1][j]==' ':
        a = move_by_index(puzzle, i-1, j, n)
    if i < len(puzzle)-1 and puzzle[i+1][j]==' ':
        a = move_by_index(puzzle, i+1, j, n)
    if j > 0 and puzzle[i][j-1]==' ':
        a = move_by_index(puzzle, i, j-1, n)
    if j < len(puzzle[0])-1 and puzzle[i][j+1]==' ':
        a = move_by_index(puzzle, i, j+1, n)
    return a

def move_by_index(puzzle, i, j, n):
    oi, oj = get_index(puzzle, n)
    #print(oi, oj, "->", i, j)
    puzzle[oi][oj], puzzle[i][j] = puzzle[i][j], puzzle[oi][oj]
    return True
    
cls = lambda: os.system('clear') # windows : cls

size = int(input(' -> please insert puzzle size : '))
puzzle = initiate_puzzle(size)

complete = [row[:] for row in puzzle]

shuffle_puzzle(puzzle)
show_puzzle(puzzle)

while puzzle != complete:
    num = int(input(' -> select a number to move : '))
    res = move_by_number(puzzle, num)

    cls()
    if not res:
        print("You can't move!!")

    show_puzzle(puzzle)

print('\nyou solved the puzzle!')
