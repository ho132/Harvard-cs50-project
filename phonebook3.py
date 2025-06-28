import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file                                                           ###But what's different, now, about this code is,
by simply using a dictionary writer here instead of the generic writer,
now, the columns can be in this order or this order or any order.
And the dictionary writer is going to figure out,
based on the first line of text in that CSV, where to put name,
where to put number.
So if you flip them, no big deal.
It's going to notice, oh, wait, the columns changed.
And it's going to insert the columns correctl
with open("phonebook.csv", "a") as file:

    # Print to file
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
