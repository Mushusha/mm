import math

def fun(a):
    for i in range(1, len(a) - 1):
        if (a[i] < a[i + 1]) & (a[i] < a[i - 1]):
            a[i] = min(a)
        elif (a[i] < a[i - 1]) & (a[i] == a[i + 1]):
            j = i
            while (a[i] == a[j]) & (j < len(a) - 1):
                j += 1
            if a[j] > a[i]:
                for k in range(i, j):
                    a[k] = min(a)
    if a[0] < a[1]:
        a[0] = min(a)
    elif a[0] == a[1]:
        i = 0
        while a[0] == a[i]:
            i += 1
        if a[0] < a[i]:
            for j in range (0, i):
                a[j] = min(a)
    if a[len(a) - 1] < a[len(a) - 2]:
        a[len(a) - 1] = min(a)
    elif a[len(a) - 1] == a[len(a) - 2]:
        i = 0
        while a[len(a) - 1] == a[len(a) - i - 1]:
            i += 1
        if a[len(a) - 1] < a[len(a) - i - 1]:
            for j in range (len(a) - i - 1, len(a)):
                a[j] = min(a)
    
    return (len(a))
    
a = []
with open ('a.txt', 'r') as f:
    for line in f:
        for x in line.split():
            a.append(float(x))
fun(a)
print(a)
