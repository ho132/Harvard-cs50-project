def division(list):

    for i in list:
        if i%5==0:
            print(i)

input_string = input("Enter elements of a list separated by space: ")
user_list = [int(x) for x in input_string.split()]  ## the most common way to split a string into a list in Python.
print('string list: ', user_list)

division(user_list)

