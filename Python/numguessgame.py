import random

top_of_range = input('type a number:')

if top_of_range.isdigit():
    top_of_range = int(top_of_range)
    if top_of_range <= 0:
        print('type something higher than zero')
        quit()
else:
    print('ples type a number next time')
    quit()

random_number = random.randint(0,top_of_range)
guesses = 0



while True:
    user_guess = input('make a guess')
    guesses = guesses+1
    if user_guess.isdigit():
        user_guess = int(user_guess)
        if(user_guess==random_number):
                print(f'Yey!you won in{guesses}  guessues')
                break
        else:
            if (user_guess > random_number):

                print(f'oooooop try again...lower down bro')     
            else:

                
                print(f'oooooop try again...go higher')        
                
           
        
    else:
        print('not a valid number!try again')  
        continue  
       


        
    