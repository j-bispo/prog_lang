import cv2

def redimensionar(foto):

    # Defina o tamanho desejado (exemplo: 300x400 pixels)
    largura = 791
    altura = 555
    novo_tamanho = (largura, altura)

    # Redimensione a foto
    foto_redimensionada = cv2.resize(foto, novo_tamanho)
    cv2.imwrite('redimensionada.jpg', foto_redimensionada)

    return foto_redimensionada