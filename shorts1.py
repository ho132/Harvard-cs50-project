nums=[x for x in range (500)]
#print(nums)  #list is like linked list 

num=list()       # a function that creates a list, and if you don't pass anything
#in it returns an empty list or an empty set of square brackets.
num=[1,2,3,4]
num.append(5)  #attach
num.insert(4,5)  #o what we're doing here is really just inserting
#into the fourth position the value 5.
#So this line, and this one that we just saw do exactly the same thing.
num[len(num): ] = [5]
print(num)