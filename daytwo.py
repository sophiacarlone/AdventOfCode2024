# Sophia Carlone
# day 2

import itertools


# Functions
def differences(l:list):
    difference = []
    for x in range(len(l)-1):
        difference.append( abs(l[x+1]-l[x]) ) 
    return difference

def success(number: list):
    safe = True
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
        return safe

# Main
sum1 = 0
sum2 = 0
safe = True

f = open("file.txt", 'r')
for x in f:
    safe = True
    x = x.replace("\n", "")
    number = x.split(" ")
    number = list(map(int, number))
    print(number)

    if success(number):
        # sum1 = sum1+1
        sum2 = sum2+1
    else:
        original = number.copy()
        for x in range(len(number)):
            testcp0 = number.copy()
            testcp0.pop(x)
            if success(testcp0):
                sum2 = sum2 + 1
                break

print(sum2)