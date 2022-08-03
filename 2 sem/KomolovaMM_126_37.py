a = input("Введите имя файла:\n")
error=0
try :f = open(a)
except FileNotFoundError:
    print("Файл не найден")
    error=1
if error!=1:
    i = 0
    n = 0
    s = 0
    for line in f:
        k = int(line)
        i += 1
        s += k*k
        n += k
    print(1/i*(s - n**2/i))
    f.close()
    

