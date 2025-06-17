# Program: 
#Author: Joseph Alberto
# Date: Jun 09, 2025
# Description: 
# License: CC BY

from pacote import camera
from pacote import captura
from pacote import moldura
from pacote import redimensionar

def main():
    cap = camera.inicializar_camera()  # Inicializa a câmera
    if cap:
        imagem = captura.capturar(cap, 5, 'captura.jpg')  # Captura uma imagem após 5 segundos
        cap.release()  # Libera a câmera após o uso

        if imagem is not None:
            imagem_redimensionada = redimensionar.redimensionar(imagem)  # Redimensiona a imagem capturada

            if imagem_redimensionada is not None:
                moldura.adicionar_moldura(imagem_redimensionada)
            else:
                print("Erro ao redimensionar a imagem.")
        else:
            print("Erro ao capturar a imagem.")

if __name__ == "__main__":
    main()
