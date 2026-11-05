import numpy as np
import cv2 as cv
from matplotlib import pyplot as plot

file = input("Informe o nome da imagem original: ")
file2 = input("Informe o nome da imagem com 1-vizinho: ")
file3 = input("Informe o nome da imagem com 4-vizinhos: ")

img = cv.imread(f".\\imgs_text\\{file}")
img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
img2 = cv.imread(f".\\imgs_text\\{file2}")
img2 = cv.cvtColor(img2, cv.COLOR_BGR2RGB)
img3 = cv.imread(f".\\imgs_text\\{file3}")
img3 = cv.cvtColor(img3, cv.COLOR_BGR2RGB)

plot.subplot(131)
plot.imshow(img)
plot.title("Original")

plot.subplot(132)
plot.imshow(img2)
plot.title("1-vizinho")

plot.subplot(133)
plot.imshow(img3)
plot.title("4-vizinhos")
plot.show()