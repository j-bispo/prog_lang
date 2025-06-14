# Program: 
#Author: Joseph Alberto
# Date: Jun 09, 2025
# Description: 
# License: CC BY
# Se você quiser usar funções ou classes de vários módulos dentro do pacote,
# você pode importar cada módulo separadamente, assim:
# from pacote import module1, module2, module3

# Ou importar cada módulo em linhas separadas:
# from pacote import module1
# from pacote import module2
# from pacote import module3

# Alternativamente, você pode importar o pacote inteiro e acessar os módulos assim:
# import pacote
# pacote.module1.welcome()

from pacote import camera
from pacote import captura

def main():

    cap = camera.inicializar_camera()
    if cap:
        captura.capturar_imagem(cap, delay=5, filename='captura.jpg')
        cap.release()

if __name__ == "__main__":
    main()

    # Fim do programa