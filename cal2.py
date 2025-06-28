def this_or_that(num1,num2):


    product = num1 * num2
    # check if product is less then 1000
    if product <= 1000:
        return product
    else:
        # product is greater than 1000 calculate sum
        return num1 + num2


num=int(input("NUM1: "))


num2=int(input("NUM2: "))

result = this_or_that(num,num2)
print("The result is", result)
