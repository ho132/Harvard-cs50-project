from cs50 import get_int

x=get_int("x: ")
y=get_int("y: ")
print(x+y)

h=input("x: ")  ##The input function, by design, always returns a string of text.
l=input("y: ")
print(h+l)


h=int(input("x: "))  ##The input function, by design, always returns a string of text.
l=int(input("y: "))
print(h+l)

g=int(input("x: "))  ##The input function, by design, always returns a string of text.
k=int(input("y: "))
z=g/k           #convert it
#print(z)
#print(f"{z}")
print(f"{z:.50f}")  #.50 shows the 50 numbers after point and f means treat it as floating point
