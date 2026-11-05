import numpy as np
import cv2 as cv
from matplotlib import pyplot as plot

file, ext = input("Digite o nome da img com a extensão: ").split(".")


img = cv.imread(f".\\imgs\\{file}.{ext}")
img = cv.cvtColor(img, cv.COLOR_BGR2RGB)

alt, comp, _ = img.shape

with open(f".\\imgs_text\\{file}.ppm", "w") as arquivo:
    arquivo.write("P3\n")
    arquivo.write(f"{comp} {alt}\n")
    arquivo.write("255\n")
    for x in img:
        for y in x:
            for z in y:
                arquivo.write(f"{str(z)} ")
        arquivo.write("\n")
