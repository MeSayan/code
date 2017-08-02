def hello_world():
    print("Hello World")
    print("How are you")

def isprime(x):
    for i in range(2,x):
        if (x%i) == 0:
            return(False)        
    return(True)


