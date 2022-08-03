from os import _exit as exit
a = input("Введите имя файла:\n")
error=0
try :f = open(a)
except FileNotFoundError:
    print("Файл не найден")
    error=1
if error!=1:
    m = f.readline()
    a = m.split()
if error!=1:
    try: a[0]
    except IndexError:
        print("Файл пустой")
        error=1
    if error!=1:
        a = int(a[0])
        i = 1
        s = 0
        for line in f:
            k = int(line)
            i += 1
            s += k
        print((s+a)/i)
    f.close()
    
