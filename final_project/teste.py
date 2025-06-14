import cv2
import time

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Não foi possível acessar a câmera.")
    exit()

start_time = time.time()
img_captured = False

while True:
    ret, frame = cap.read()
    if not ret:
        print("Erro ao capturar imagem.")
        break

    elapsed = time.time() - start_time

    # Mostra o vídeo ao vivo
    cv2.imshow('Webcam', frame)

    # Captura a imagem após 5 segundos
    if not img_captured and elapsed >= 5:
        cv2.imwrite('captura.jpg', frame)
        print("Foto capturada!")
        img_captured = True

    # Fecha a janela se a pessoa apertar ESC
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()