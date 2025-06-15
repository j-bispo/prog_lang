import cv2

# Carregar as imagens
foto = cv2.imread('captura.jpg')
moldura = cv2.imread('moldura.png', cv2.IMREAD_UNCHANGED)  # usar UNCHANGED para PNG com alfa

# Definir posição e tamanho da área da moldura onde a foto será inserida
# Exemplo: canto superior esquerdo (x, y) = (100, 100), tamanho 300x400 px
x, y, w, h = 100, 100, 300, 400

# Redimensionar a foto para caber no espaço
foto_redimensionada = cv2.resize(foto, (w, h))

# Se a moldura tem canal alfa
if moldura.shape[2] == 4:
    # Separar canais
    moldura_rgb = moldura[:, :, :3]
    moldura_alpha = moldura[:, :, 3] / 255.0

    # Colocar a foto no local desejado da moldura
    moldura_rgb[y:y+h, x:x+w] = foto_redimensionada

    # Recompor canais com alfa
    moldura_final = cv2.merge((moldura_rgb, (moldura_alpha*255).astype('uint8')))
else:
    # Apenas insere a foto no local desejado da moldura (sem transparência)
    moldura[y:y+h, x:x+w] = foto_redimensionada
    moldura_final = moldura

# Salvar ou mostrar o resultado
cv2.imwrite('foto_na_moldura.png', moldura_final)
cv2.imshow('Resultado', moldura_final)
cv2.waitKey(0)
cv2.destroyAllWindows()