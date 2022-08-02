import math

def fun(a):
    b = []
    if a[0] < a[1]:
        b.append(0)
    for i in range(1, len(a) - 1):
        if (a[i] < a[i + 1]) & (a[i] < a[i - 1]):
            b.append(int(i))
    if a[len(a) - 1] < a[len(a) - 2]:
        b.append(len(a) - 1)
    for i in range(0, len(b) - 1):
        if i % 2 == 0:
            t = a[b[i]]
            a[b[i]] = a[b[i+1]]
            a[b[i+1]] = t                
    print(a)

a = []
with open ('a.txt', 'r') as f:
    for line in f:
        for x in line.split():
            a.append(float(x))
print(a)
fun(a)

