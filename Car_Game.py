Command =""
started = False
while True:
    Command = input("> ").lower()
    if Command == "start" :
        if started:
            print("Car is  already Started!")
        else:
            started = True
            print("Car Started....")
    elif Command == "stop" :
        if not started:
            print("Car is already Stopped!")
        else:
            started=False
            print("Car Stopped...")
    elif Command == "help" :
        print(''' 
Start - To start the Car
Stop - To stop the Car
Quit - To Quit
        ''')
    elif Command == "quit":
        break

    else:
        print("Sorry,I don't understand that")


