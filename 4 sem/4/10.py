from PIL import Image, ImageEnhance

print ("Enter K1: ")
K1 = float(input())
print ("Enter K2: ")
K2 = float(input())
im = Image.open(input('Enter InputFile: '))

brightness = ImageEnhance.Brightness(im)
imout = brightness.enhance(K1)    
contrast = ImageEnhance.Contrast(imout)
imoutput = contrast.enhance(K2)
imoutput.save('Output.bmp')

