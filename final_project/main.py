# Program: 
#Author: Joseph Alberto
# Date: Jun 09, 2025
# Description: 
# License: CC BY

from pacote import camera
from pacote import captura
from pacote import moldura

def main():

    cap = camera.inicializar_camera() # Inicializa a câmera
    if cap:
        imagem = captura.capturar_imagem(cap, 5, 'captura.jpg') # Captura uma imagem após 5 segundos
        cap.release() # Libera a câmera após o uso

    if imagem is not None:
        moldura.adicionar_moldura(imagem, 'moldura.png', output_path='foto_com_moldura.png')

if __name__ == "__main__":
    main()
