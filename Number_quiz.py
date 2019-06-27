import random

hidden = random.randint(1,100)

i = 0
while i < 7:
    guess = int(input())
    if guess == hidden:
        print( 'you nailed it!', guess)
        break
    elif guess > hidden:
        print('The value is smaller than your guess')
    else:
        print('The value is bigger than your guess')
    i += 1
else:
    print('failed to guess a number in 7 times!')
