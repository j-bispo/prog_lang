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

    # Se a moldura tem 4 canais (RGBA), faz sobreposição alfa
    if moldura.shape[2] == 4:
        overlay_img = imagem.copy()
        alpha_mask = moldura[:, :, 3] / 255.0
        for c in range(0, 3):
            overlay_img[:, :, c] = (1. - alpha_mask) * overlay_img[:, :, c] + alpha_mask * moldura[:, :, c]
        resultado = overlay_img.astype(np.uint8)
    else:
        # Se for RGB, apenas faz mistura simples
        resultado = cv2.addWeighted(imagem, 1, moldura, 1, 0)

    cv2.imwrite(output_path, resultado)
    print(f"Foto com moldura salva como {output_path}")
    return resultado