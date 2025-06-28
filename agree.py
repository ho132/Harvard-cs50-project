from cs50  import get_string

s=get_string("do u agree ")
if s=="Y" or s=="y":
    print("Agreed.")
elif s=='N' or s=='n':
    print("Not agreed.")

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s.lower() in ["y", "yes"]:       #or i can do s=s.lower() but then i cant know wht s original was
    # or t=s.lower()

    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")


import re

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if re.search("^y(es)?$", s, re.IGNORECASE):
    print("Agreed.")
elif re.search("^no?$", s, re.IGNORECASE):
    print("Not agreed.")
