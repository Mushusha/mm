import math
a = []
with open ('a.txt', 'r') as f:
    for line in f:
        for x in line.split():
            a.append(float(x))
if len(a) == 0:
    print("error")
else:
    k = 0
    for i in range(0, len(a) - 1):
        if a[i] == a[i + 1]:
            k += 1

    if k + 1 == len(a):
        print("yes")
    else:
        print("no")
    


            
