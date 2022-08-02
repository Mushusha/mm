from scipy import misc
from numpy import uint8 as u8
from imageio import imread
from imageio import imwrite

print ("Enter k: ")
k = int(input())
im = imread('InputFile.bmp')
h = len(im)
w = len(im[0])

im2 = [ i for i in range(0, h + 2*k) ]

for x in range(0, h + 2*k):
    im2[x] = [ i for i in range(0, w + 2*k) ]
    for y in range(0, w + 2*k):
        im2[x][y] = [u8(0), u8(0), u8(0)]
        
for x in range(k, h + k):
    for y in range(k, w + k):
        im2[x][y] = im[x - k][y - k]

imwrite('OutputFile.bmp', im2, format = 'bmp')

