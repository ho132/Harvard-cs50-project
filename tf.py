def tf (numberList):


    print("Given list:", numberList)

    first_num = numberList[0]
    last_num = numberList[-1]

    if first_num == last_num:
        return True
    else:
        return False

numbers_x = [10, 20, 30, 40, 10]
print("result is", tf(numbers_x))

numbers_y = [75, 65, 35, 75, 30]
print("result is", tf(numbers_y))

