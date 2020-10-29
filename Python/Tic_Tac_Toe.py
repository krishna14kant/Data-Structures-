b=[]
q=[]
import random
# Make the Board
board= ['1','2','3',
       '4','5','6',
       '7','8','9']
# defining a function for printing the board
def printBoard():
    print(board[0] + ' |' + board[1] + ' |' + board[2])
    print('--|--|--')
    print(board[3] + ' |' + board[4] + ' |' + board[5])
    print('--|--|--')
    print(board[6] + ' |' + board[7] + ' |' + board[8])

printBoard()
print("Press 'Y'to play with your friend or Press 'N' to play with computer")
choose=input()
printBoard() 
print('Choose any number from [1,9] to play ')
if choose=='Y' :
    for i in range(9):
        if i%2 == 0:
            player1=int(input("Player 1 Turn 'X' "))
            if (player1 >= 1 and player1 <= 9 and (player1 not in b)) :
                board[player1 - 1] = 'X'
                b.append(player1)
                printBoard()
                # Conditions for which 'X' Wins
                if (board[0] == board[1] == board[2] == 'X') or (board[3] == board[4] == board[5] == 'X') or (board[6] == board[7] == board[8] == 'X') or (
                    board[0] == board[4] == board[8] == 'X') or (board[2] == board[4] == board[6] == 'X') or (board[0] == board[3] == board[6] == 'X') or (
                    board[1] == board[4] == board[7] == 'X') or (board[2] == board[5] == board[8] == 'X'):
                    
                        print('Congratulations')
                        break
                        
            
            else:
                while(not (player1 >=1 and player1<=9 and (player1 not in b))):
                    print('Enter the valid move')
                    player1=int(input("Player 1 Turn 'X' "))
                board[player1 - 1] = 'X'
                printBoard()
                # Conditions for which 'X' Wins
                if (board[0] == board[1] == board[2] == 'X') or (board[3] == board[4] == board[5] == 'X') or (board[6] == board[7] == board[8] == 'X') or (
                    board[0] == board[4] == board[8] == 'X') or (board[2] == board[4] == board[6] == 'X') or (board[0] == board[3] == board[6] == 'X') or (
                    board[1] == board[4] == board[7] == 'X') or (board[2] == board[5] == board[8] == 'X'):
                    
                        print('Congratulations')
                        break
                
        else:
            player2 = int(input("Player 2 Turn 'O' "))
            if(player2 >= 1 and player2 <= 9 and player2 not in b) :
                board[player2 - 1] = 'O'
                b.append(player2)
                printBoard()
                # Conditions for which 'O' Wins
                if ((board[0] == board[1] == board[2] == 'O') or (board[3] == board[4] == board[5] == 'O') or (board[6] == board[7] == board[8] == 'O')
                or (board[0] == board[3] == board[6] == 'O') or (board[1] == board[4] == board[7] == 'O') or (board[2] == board[5] == board[8] == 'O')
                or (board[0] == board[4] == board[8] == 'O') or (board[2] == board[4] == board[6] == 'O')) :
            
                        print('Congratulations')
                        break
            else:
                while(not (player2 >=1 and player2<=9 and (player2 not in b))):
                    print('Enter the valid move')
                    player2=int(input("Player 2 Turn 'O' "))
                board[player2 - 1] = 'O'
                printBoard()
                # Conditions for which 'O' Wins
                if (board[0] == board[1] == board[2] == 'O') or (board[3] == board[4] == board[5] == 'O') or (board[6] == board[7] == board[8] == 'O') or (
                    board[0] == board[4] == board[8] == 'O') or (board[2] == board[4] == board[6] == 'O') or (board[0] == board[3] == board[6] == 'O') or (
                    board[1] == board[4] == board[7] == 'O') or (board[2] == board[5] == board[8] == 'O'):
                    
                        print('Congratulations')
                        break

                
    if((board[0] == board[1] == board[2] == 'X') or (board[3] == board[4] == board[5] == 'X') or (board[6] == board[7] == board[8] == 'X') or (
     board[0] == board[4] == board[8] == 'X') or (board[2] == board[4] == board[6] == 'X') or (board[0] == board[3] == board[6] == 'X') or (
     board[1] == board[4] == board[7] == 'X') or (board[2] == board[5] == board[8] == 'X')):
        print('Player 1 wins!!!')
    elif((board[0] == board[1] == board[2] == 'O') or (board[3] == board[4] == board[5] == 'O') or (board[6] == board[7] == board[8] == 'O')
        or (board[0] == board[3] == board[6] == 'O') or (board[1] == board[4] == board[7] == 'O') or (board[2] == board[5] == board[8] == 'O')
        or (board[0] == board[4] == board[8] == 'O') or (board[2] == board[4] == board[6] == 'O')):
        print('Player 2 wins!!!')
    else:
     print('Draw')


# If playing with CPU

else:
    for i in range(9) :
        if (i%2 == 0):
            
            n = int(input("Enter your move 'X' "))
            if(n >=1 and n<=9 and (n not in b)):
                board[n-1] = 'X'
                b.append(n)

                # Condition for 'X' Wins
                if (board[0] == board[1] == board[2] == 'X') or (board[3] == board[4] == board[5] == 'X') or (board[6] == board[7] == board[8] == 'X') or (
                    board[0] == board[4] == board[8] == 'X') or (board[2] == board[4] == board[6] == 'X') or (board[0] == board[3] == board[6] == 'X') or (
                    board[1] == board[4] == board[7] == 'X') or (board[2] == board[5] == board[8] == 'X'):
                    
                        print('X Wins!!!')
                        break
                        
            
            else:
                while (not (n >=1 and n<=9 and (n not in b))):
                    print('Enter the valid move')
                    n = int(input("X's Turn"))
                
                board[n-1] = 'X'
                
                # Conditions for which 'X' Wins
                if (board[0] == board[1] == board[2] == 'X') or (board[3] == board[4] == board[5] == 'X') or (board[6] == board[7] == board[8] == 'X') or (
                    board[0] == board[4] == board[8] == 'X') or (board[2] == board[4] == board[6] == 'X') or (board[0] == board[3] == board[6] == 'X') or (
                    board[1] == board[4] == board[7] == 'X') or (board[2] == board[5] == board[8] == 'X'):
                    
                        print('X Wins!!!')
                        break
        else:
            for i in [1,2,3,4,5,6,7,8,9]:
                if (i not in b):
                    q.append(i)
            n2 = random.choice(q)
            if n2 >= 1 and n2 <= 9 and (n2 not in b):
                b.append(n2)
                board[n2 - 1] = 'O'
                printBoard()
                # Conditions for which Computer Wins
                if (board[0] == board[1] == board[2] == 'O') or (board[3] == board[4] == board[5] == 'O') or (board[6] == board[7] == board[8] == 'O') or (
                    board[0] == board[4] == board[8] == 'O') or (board[2] == board[4] == board[6] == 'O') or (board[0] == board[3] == board[6] == 'O') or (
                    board[1] == board[4] == board[7] == 'O') or (board[2] == board[5] == board[8] == 'O'):
                    
                        print('You Lost')
                        break
                    

    if((board[0] == board[1] == board[2] == 'X') or (board[3] == board[4] == board[5] == 'X') or (board[6] == board[7] == board[8] == 'X') or (
     board[0] == board[4] == board[8] == 'X') or (board[2] == board[4] == board[6] == 'X') or (board[0] == board[3] == board[6] == 'X') or (
     board[1] == board[4] == board[7] == 'X') or (board[2] == board[5] == board[8] == 'X')):
        print('You win')
    elif((board[0] == board[1] == board[2] == 'O') or (board[3] == board[4] == board[5] == 'O') or (board[6] == board[7] == board[8] == 'O')
        or (board[0] == board[3] == board[6] == 'O') or (board[1] == board[4] == board[7] == 'O') or (board[2] == board[5] == board[8] == 'O')
        or (board[0] == board[4] == board[8] == 'O') or (board[2] == board[4] == board[6] == 'O')):
        print('Computer wins')
    else:
        print('Draw')
# Finished
# Enjoy Your Day
     

                

