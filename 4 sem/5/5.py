import sys
import cv2 as cv
import numpy as np
from pyx import *
from imageio import imread

im = cv.imread('i.bmp', cv.IMREAD_GRAYSCALE)
im = np.rot90(im, -1)
h = len(im)
w = len(im[0])
img = cv.Canny(im, 160, 180)
new = canvas.canvas()
p = []

for x in range (0, h):
    for y in range (0, w):    
        if img[x][y] == 255:
            p.append([])
            p[-1].append([x, y])
            num = 1
            s = []
            s.append((x, y))
            f = 0
            img[x][y] = 100
            while(len(s)):
                for i in range(min(s[-1][0] + 1, h - 1), max(s[-1][0] - 2, 0), -1):
                    for j in range(min(s[-1][1] + 1, w - 1), max(s[-1][1] - 2, 0), -1):
                        if (img[i][j] == 255):
                            f = 1
                            s.append((i ,j))
                            img[i][j] = 200
                            if (num % 4 == 0):
                                if (img[max(i - 1, 0):min(i + 2, h), max(j - 1, 0):min(j + 2, w)] == 2).sum() == 0:
                                    img[i, j] = 100
                                    p[-1].append([i, j])
                            num = (num + 1) % 23
                        if f:   
                            break
                    if f:
                        break
                if f:
                    f = 0
                else:
                    s.pop()
                    if (p[-1] != []):
                        p.append([])
                    num = 1 
#cv.imwrite('b.bmp', img)     
for t in p:
    if (len(t) >= 1):
        t = np.array(t)
        sz = len(t)*2
        A = np.zeros((sz, sz))
        A[0, 0] = 2
        A[0, 1] = -1
        A[sz - 1, sz - 2] = -1
        A[sz - 1, sz - 1] = 2
        for i in range (1, sz - 1, 2):
            A[i][i - 1] = 1
            A[i][i] = -2
            A[i][i + 1] = 2
            A[i][i + 2] = -1
            A[i + 1][i] = 1
            A[i + 1][i + 1] = 1
        Qx = np.zeros(sz)
        Qy = np.zeros(sz)
        Qx[0] = t[0][0]
        Qy[0] = t[0][1]
        for i in range (2, sz, 2):
            Qx[i] = 2*t[i//2][0]
            Qy[i] = 2*t[i//2][1]
        Qx[-1] = t[-1][0]
        Qy[-1] = t[-1][1]
        M = np.vstack((np.linalg.solve(A, Qx), np.linalg.solve(A, Qy))).T
        B = np.zeros((len(t)*3, 2))
        for i in range (0, len(t)):
            B[i*3] = t[i]
            B[i*3 + 1] = M[i*2]
            B[i*3 + 2] = M[i*2 + 1]
        for i in range(0, len(t)*3 - 3, 3):
            new.stroke(path.curve(B[i][0], B[i][1], B[i + 1][0], B[i + 1][1], B[i + 2][0], B[i + 2][1], B[i + 3][0], B[i + 3][1]), [style.linewidth.THICK])
            
pg = document.page(new, fittosize = 1)
doc = document.document(pages = [pg])
doc.writePDFfile('i')

        

        





    
