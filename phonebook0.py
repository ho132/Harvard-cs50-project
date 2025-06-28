mplements a phone book

from cs50 import get_string

people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2750"    #key : value                 #scores=[]        (give u empty list )
                                                               #shorthand version of score=list()
                                                               #if i want dictionary
                                                               #i can put people={}
                                                               #or people=dict()
}

# Search for name
name = get_string("Name: ")                              #name=input("name:")
                                                                if name in people :
                                                                   # or  i can do
                                                                   number=people[name]
                                                                   #or people["david"]
                                                                  print(f"number:{people[name]}") #here :{number}
if name in people:
    print(f"Number: {people[name]}")
