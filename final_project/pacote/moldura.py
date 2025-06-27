import cv2
import numpy as np

def adicionar_moldura(redimensionada, nome):
    # Carrega a imagem de fundo (moldura) e a foto a ser inserida
    fundo = cv2.imread('moldura.png')

    # Posição desejada (exemplo: x=130, y=245)
    x, y = 132, 244

    # Dimensões da foto redimensionada
    h, w = redimensionada.shape[:2]

    # Insere a foto na posição (x, y) da moldura
    fundo[y:y+h, x:x+w] = redimensionada

    cv2.imwrite(nome, fundo)
    cv2.namedWindow('Resultado', cv2.WINDOW_NORMAL)  # Cria uma janela nomeada
    cv2.resizeWindow('Resultado', 950, 750)  # Redimensiona a janela de exibição
    cv2.imshow('Resultado', fundo) # Exibe a imagem com a moldura
    cv2.waitKey(0)
    cv2.destroyAllWindows() # Fecha todas as janelas abertas