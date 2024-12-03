# Sophia Carlone
# day 2

import itertools


# Functions
def differences(l:list):
    difference = []
    for x in range(len(l)-1):
        difference.append( abs(l[x+1]-l[x]) ) 
    return difference

# Main
sum1 = 0
safe = True

f = open("file.txt", 'r')
for x in f:
    safe = True
    x = x.replace("\n", "")
    number = x.split(" ")
    number = list(map(int, number))
    print(number)

    sorted_increasing = sorted(number)
    #print(sorted_increasing)
    sorted_decreasing = sorted(number, reverse = True)
    #print(sorted_decreasing)

    if (sorted_increasing == number or sorted_decreasing == number):
        d = differences(number)
        print(d)
        for x in d:
            if x > 3 or x < 1:
                safe = False
        if safe:
            sum1 = sum1 + 1
print(sum1)

