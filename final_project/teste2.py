import cv2
import time

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Não foi possível acessar a câmera.")
    exit()

start_time = time.time()
img_captured = False
delay = 5  # tempo em segundos para capturar

while True:
    ret, frame = cap.read()
    if not ret:
        print("Erro ao capturar imagem.")
        break

    elapsed = int(time.time() - start_time)
    countdown = delay - elapsed

    # Mostra mensagem diferente conforme o tempo
    if not img_captured and countdown > 0:
        msg = f"Capturando em {countdown}..."
        cv2.putText(frame, msg, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)
    elif not img_captured and countdown <= 0:
        msg = "Foto capturada!"
        cv2.putText(frame, msg, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2)
        cv2.imwrite('captura.jpg', frame)
        img_captured = True

    cv2.imshow('Webcam', frame)

    # Fecha a janela se a pessoa apertar ESC
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()