from scipy import misc
from numpy import uint8 as u8
from imageio import imread
from imageio import imwrite
import math
import sys

print ("Enter K1 for change brigth: ")
#K1 = float(sys.argv[1])
K1 = float(input())
print ("Enter K2 for change contrast: ")
#K2 = float(sys.argv[2])
K2 = float(input())
print ('Enter InputFile: ')
#im = imread(sys.argv[3])
im = imread(input())
print ('Enter OutputFile: ')
#f = str(sys.argv[4])
f = str(input())
h = len(im)
w = len(im[0])
m = [0, 0, 0]
im2 = [ i for i in range(0, h) ]
for x in range(0, h):
    im2[x] = [ i for i in range(0, w) ]
    for y in range(0, w):
        for j in range (0, 3):
            m[j] += int(im[x][y][j])
            
for j in range (0, 3):
    m[j] = m[j]/(h*w)

for x in range(0, h):
    for y in range(0, w):
        b = [im[x][y][0], im[x][y][1], im[x][y][2]]
        for j in range (0, 3):
            b[j] *= K1
            b[j] = (b[j] - m[j])*K2 + m[j]
            if b[j] > 255:
                b[j] = 255         
            elif b[j] < 0:
                b[j] = 0
        im2[x][y] = [u8(b[0]), u8(b[1]), u8(b[2])]        
imwrite(f, im2, format = 'bmp')
