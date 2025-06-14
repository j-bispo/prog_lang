# Program: 
#Author: Joseph Alberto
# Date: Jun 09, 2025
# Description: 
# License: CC BY

from pacote import camera
from pacote import captura

def main():

    cap = camera.inicializar_camera()
    if cap:
        captura.capturar_imagem(cap, 5, 'captura.jpg')
        cap.release()

if __name__ == "__main__":
    main()

    # Fim do programa