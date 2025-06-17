import cv2

# Carregue a foto original
foto = cv2.imread('captura.jpg')

# Defina o tamanho desejado (exemplo: 300x400 pixels)
largura = 700
altura = 400
novo_tamanho = (largura, altura)

# Redimensione a foto
foto_redimensionada = cv2.resize(foto, novo_tamanho)

# Exiba e/ou salve a imagem redimensionada
cv2.imshow('Foto Redimensionada', foto_redimensionada)
cv2.imwrite('foto_enquadrada.jpg', foto_redimensionada)
cv2.waitKey(0)
cv2.destroyAllWindows()