import numpy as np
import cv2 as cv



def main():
    caminhoFront = None
    camminhoBack = None

    with open("C:\\Users\\Murilo\\Desktop\\CG\\ChromaKey2\\nomesImg.txt", "r") as arquivo:
        caminhoFront = arquivo.readline()
        caminhoFront = caminhoFront.strip()
        camminhoBack = arquivo.readline()
        camminhoBack = camminhoBack.strip()

    img = cv.imread("C:\\Users\\Murilo\\Desktop\\CG\\ChromaKey2\\resultado.pnm")
    img_front = cv.imread(caminhoFront)
    img_back = cv.imread(camminhoBack)

    #cv.imshow("Window",img_back)
    #cv.waitKey(0)

    #cv.imshow("Window",img_front)
    #cv.waitKey(0)

    cv.imshow("Window",img)
    cv.waitKey(0)

if __name__ == "__main__":
    main()