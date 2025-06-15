import cv2

# Carrega a imagem de fundo (moldura) e a foto a ser inserida
fundo = cv2.imread('moldura.png')
foto = cv2.imread('captura.jpg')

# Posição desejada (exemplo: x=50, y=100)
x, y = 130, 245

# Dimensões da foto
h, w = foto.shape[:2]

# Verifica se cabe
if y + h > fundo.shape[0] or x + w > fundo.shape[1]:
    print("A foto não cabe na moldura nessa posição!")
else:
    # Insere a foto na posição (x, y) da moldura
    fundo[y:y+h, x:x+w] = foto

    cv2.imwrite('foto_salva.jpg', fundo)

    cv2.imshow('Resultado', fundo)
    cv2.waitKey(0)
    cv2.destroyAllWindows()