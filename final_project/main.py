# Program: Cabine de foto
#Author: Joseph Alberto
# Date: Jun 27, 2025
# Description: Esse código implementa a lógica de uma cabine de fotos, onde o usuário pode capturar uma imagem e adicionar uma moldura.
# License: CC BY

import msvcrt
from pacote import camera
from pacote import captura
from pacote import moldura
from pacote import redimensionar

def main():

    i = 1  # Contador para nomear as imagens capturadas

    while True:
        cap = camera.inicializar_camera()  # Inicializa a câmera
        if cap:
            imagem = captura.capturar(cap, 5, 'captura.jpg')  # Captura uma imagem após 5 segundos
            cap.release()  # Libera a câmera após o uso

            # Verifica se a imagem foi capturada com sucesso
            if imagem is not None:
                imagem_redimensionada = redimensionar.redimensionar(imagem)  # Redimensiona a imagem capturada

                # Se a imagem foi redimensionada com sucesso, adiciona a moldura
                if imagem_redimensionada is not None:
                    moldura.adicionar_moldura(imagem_redimensionada, f'foto_com_moldura_{i}.jpg')
                else:
                    print("Erro ao redimensionar a imagem.")
            else:
                print("Erro ao capturar a imagem.")

        # Mensagem para o usuário sobre como sair ou capturar novamente
        print("Pressione a barra de espaço para sair ou qualquer outra tecla para capturar novamente.")
        if msvcrt.getch() == b' ':
            print("Saindo do programa.")
            break
        else:
            print("Capturando novamente...")
            i += 1

if __name__ == "__main__":
    main()

 