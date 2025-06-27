import cv2
import time

# Função para capturar uma imagem da webcam
def capturar(cap, delay, filename):

    # Marca o tempo de início da captura
    start_time = time.time() 
    img_captured = False 
    while True:
        # Captura um frame da webcam
        ret, frame = cap.read() 
        if not ret:
            print("Erro ao capturar imagem.")
            break

        # Contagem regressiva para a captura da imagem
        elapsed = int(time.time() - start_time)
        countdown = delay - elapsed

        # Se a contagem regressiva chegar a zero, captura a imagem
        if not img_captured and countdown > 0:
            msg = f"Capturando em {countdown}..."
            cv2.putText(frame, msg, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)
            
        # Se a imagem já foi capturada, exibe uma mensagem
        elif not img_captured and countdown <= 0:
            cv2.imwrite(filename, frame)
            print("Imagem capturada")
            img_captured = True

            break

        # Exibe o frame da webcam
        cv2.imshow('Webcam', frame)
        cv2.waitKey(1)

    # Lê a imagem capturada
    captura = cv2.imread(filename)  

    # Fecha a janela da webcam
    cv2.destroyAllWindows()

    return captura