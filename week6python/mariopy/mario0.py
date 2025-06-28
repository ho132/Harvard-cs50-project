for i in range(3):
   print("#")

#######
from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n>0:
        break

for i in range(n):
   print("#")
#####

def main():

height=get_height
for i in range(height):
    print("#")



def get_height():

while True:
    n = get_int("Height: ")
    if n>0:
        ##if i break i will not call it
    return n


            main()
def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")


main()
