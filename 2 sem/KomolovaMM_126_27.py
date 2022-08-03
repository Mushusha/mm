a = input("Введите имя файла:\n")
error=0
try :f = open(a)
except FileNotFoundError:
    print("Файл не найден")
    error=1
if error!=1:
    m = f.readline()
    a = m.split()
    try: a[0]
    except IndexError:
        print("Файл пустой")
        error=1
    if error!=1:
        a = int(a[0])
        k = 0
        x = 0
        z = 0
        for line in f:
            k += 1
            t = int(line)
            if (a == t) and (z == 0):
                x += 1
                z += 1
            if t != a:
                x -= 1
                z = 0
                a = t
        print(k + x)
    f.close()
