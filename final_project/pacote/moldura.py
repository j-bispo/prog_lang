import cv2
import numpy as np

def adicionar_moldura(imagem, moldura_path, output_path='foto_com_moldura.png'):
    # Lê a moldura (com transparência caso PNG)
    moldura = cv2.imread(moldura_path, cv2.IMREAD_UNCHANGED)
    if moldura is None:
        print("Não foi possível carregar a moldura.")
        return

    # Redimensiona a moldura para o tamanho da imagem capturada
    altura, largura = imagem.shape[:2]
    moldura = cv2.resize(moldura, (largura, altura))

    resultado = cv2.imread('moldura.png')

    cv2.imwrite(output_path, resultado)
    print(f"Foto com moldura salva como {output_path}")

    cv2.imshow('Foto com Moldura', resultado) # Exibe a imagem com moldura
    cv2.waitKey(0)
    cv2.destroyAllWindows()

    return resultado