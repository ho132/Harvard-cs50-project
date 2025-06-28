# Capitalizes a copy of a string

# Get a string
s = input("s: ")

# Capitalize copy of string
t = s.capitalize()

# Print strings
print(f"s: {s}")
print(f"t: {t}")





       import sys
s=input("s: ")
t=s.capitalize()  #capitalize first letter only
print(f"s:{s}")
print(f"t:{t}")     #because if you capitalize s and store it in t,
#we accidentally capitalized both s and t.
#but in this case, in Python, when I actually run this and type in "cat"
#In all lowercase, the original s is unchanged
#because, when I use capitalize on line 3, this is, indeed, capitalizing s.
#But it's returning a copy of the result. It cannot change s itself
#because, again, for that technical term, s is immutable.
#Strings, once they exist, cannot be changed themselves.
#But you can return copies and modify mutated copies of those same strings.
