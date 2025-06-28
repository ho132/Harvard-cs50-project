#So what a tuple is, it is an ordered, immutable set of data,
#basically what we're saying here is we have a collection of a couple of things
#that we will never change, but the order matters.

presidents = {
    ("kajw wjj", 1823),
    ("lamwj",1893),
    

}
for prez,year in presidents:
              print("In  {1} , {0} took office".format(prez,year)) #nd because I have the 1 and 0 there as opposed to just leaving them blank,
#it swaps the order of them.

lama = {
    ("ahza"),
    ("girl"),
}                                                 #lists []
                                                    #tuples()
                                                #dict{}
print("in {0}".format(lama))

pizzas = {
    "cheese" : 9, 
     "veg"   : 7,
     "chicken": 12,     #(key ,value)
}

pizzas["cheese"]=8
#if pizzas["veg"]<12
#do smth
pizzas["bacon"]=14
for pizza, price in pizzas.items():
    print("{0},{1}".format(pizza, price))
    
for pie in pizzas:
    print(pie)
    
for pie, price in pizzas.items():
    print(price)      #but if I want to iterate over the values,
#I have to transform the dictionary into a list.
#In order to do that, I need to use the dot items
#method to transform my dictionary into a list for purposes
#of just iterating over this.



#when you transform the dictionary into a list to iterate over it as we do here,
#you're not guaranteed that that list is going to maintain its order.


for pie, price in pizzas.items():
    print("a whole {} pizza costs ${}".format(pie,price))
    
    # u can also do 
    #("a whole" +pie + z"pizza costs $"+str(price))
    
    #or this
    #("a whole %s pizza costs $%2d" % (pie,pric) #dont use it
