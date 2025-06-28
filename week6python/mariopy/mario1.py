for i in range(3):
    for j in range(3):
        print("#", end="")  #prints a "#" without moving to a new line (due to end="").
    print()
 #is used to move to a new line. after printibg 3 #





 #In the inner loop, the variable j is used to control the number of times the printf("#") statement is executed. In each iteration of the inner loop (controlled by j), a "#" is printed. The inner loop runs three times, printing three "#" symbols in a row. The outer loop, controlled by the variable i, repeats this process three times, creating three rows of "#" symbols.



#orr

for i in range(3):
    print("#" * 3)

