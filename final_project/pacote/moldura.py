import cv2
import numpy as np

def adicionar_moldura(redimensionada):
    # Carrega a imagem de fundo (moldura) e a foto a ser inserida
    fundo = cv2.imread('moldura.png')

    # Posição desejada (exemplo: x=130, y=245)
    x, y = 132, 244

    # Dimensões da foto redimensionada
    h, w = redimensionada.shape[:2]

    # Insere a foto na posição (x, y) da moldura
    fundo[y:y+h, x:x+w] = redimensionada

    cv2.imwrite('foto_salva.jpg', fundo)
    cv2.imshow('Resultado', fundo)
    cv2.waitKey(0)
    cv2.destroyAllWindows()