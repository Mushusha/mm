import math
a = []
with open ('a.txt', 'r') as f:
    for line in f:
        for z in line.split():
            a.append(float(z))
if len(a) == 0:
    print("error")
else:
    x = [0]*(len(a)//2)
    y = [0]*(len(a)//2)
    for i in range(0, len(a) - 1, 2):
        x[i//2] = a[i]
        y[i//2] = a[i+1]
    print(x)
    print(y)
    p = [0]*len(a)
    n = 0
    for i in range(0, len(x)):
        for j in range(0, len(x)):
            if i != j:
                more = 0
                less = 0
                for l in range(0, len(x)):
                    if (l != i) & (l != j):
                        if ((x[j] - x[i]) != 0):
                            k = (y[j] - y[i])/(x[j] - x[i])            
                            b = y[i] - k*x[i]
                            c = k*x[l] + b
                            d = y[l]
                        if ((x[j] - x[i]) == 0):
                            c = x[i]
                            d = x[l]
                        if c > d:
                            more += 1
                        if c < d:
                            less += 1
                if (less == 0) | (more == 0):
                    p[n] = x[i]
                    p[n + 1] = y[i]
                    n += 2
                    break
    
    for i in range (0, n , 2):
        print(i//2 + 1, "point:", p[i], p[i + 1])

