# Sophia Carlone
# day 2

import itertools


# Functions
def differences(l:list):
    difference = []
    for x in range(len(l)-1):
        difference.append( abs(l[x+1]-l[x]) ) 
    return difference

#og is list from file, s is sorted list
def diff_between(og:list, s:list):
    differences = 0
    factor = 0
    for x in range(len(og)):
        # difference.append(abs(s[x]-og[x]))
        if(abs(s[x] - og[x])>0):
            differences = (differences * (10 * factor)) + (x+1)
            factor = factor + 1
    return differences

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

    sorted_increasing = sorted(number)
    #print(sorted_increasing)
    sorted_decreasing = sorted(number, reverse = True)
    #print(sorted_decreasing)

    #part 1
    if (sorted_increasing == number or sorted_decreasing == number):
        d = differences(number)
        # print(d)
        print("matched a sort")
        num_unsafe = 0
        n = 0
        index = 0
        for x in d:
            if x > 3 or x < 1:
                safe = False
                print(x)
                num_unsafe = (num_unsafe * (10 * n)) + index+2
                print("num unsafe is currently")
                print(num_unsafe)
                n = n+1 
            index = index + 1
            print("index")
            print(index)
        if(num_unsafe < 10 and num_unsafe > 0):
            num_unsafe = num_unsafe-1
            safe = True
            print(num_unsafe)
            print("only one diff")
            number.pop(num_unsafe)
            print(number)
            d=differences(number)
            for x in d:
                if x > 3 or x < 1:
                    print("still not good")
                    safe = False
        # if safe:
        #     sum2 = sum2 + 1

    #part 2
    else:
        print("doesnt match sort")
        diff_incr = diff_between(number, sorted_increasing)
        diff_decr = diff_between(number, sorted_decreasing)
        print(diff_incr)
        print(diff_incr % 11)
        print(diff_decr)
        
        if(diff_incr < 9): #removing one from decr works
            print("A")
            number.pop(diff_decr-1)
            print(number)
            d=differences(number)
            for x in d:
                if x > 3 or x < 1:
                    print("in decresing, still not good")
                    safe = False
        elif(diff_decr < 9):
            print("B")
            number.pop(diff_incr-1)
            print(number)
            d=differences(number)
            for x in d:
                if x > 3 or x < 1:
                    print("in incr, still not good")
                    safe = False
        elif(diff_incr < 100 and diff_incr % 11 == 1): #special case
            print("C")
            # diff_incr = (int)(diff_incr / 10)
            diff_incr = diff_incr % 10
            number.pop(diff_incr-2)
            print(number)
            d=differences(number)
            for x in d:
                if x > 3 or x < 1:
                    print("in incr, still not good")
                    safe = False
        elif(diff_decr < 100 and diff_decr % 11 == 1): #special case
            print("D")
            diff_decr = diff_decr % 10
            number.pop(diff_decr-2)
            print(number)
            d=differences(number)
            for x in d:
                if x > 3 or x < 1:
                    print("in decr, still not good")
                    safe = False
        elif(diff_incr > 9 and diff_decr > 9):
            print("fell to bottom")
            safe = False

    if safe:
        print(safe)
        sum2 = sum2 + 1
    print()

print(sum2)

