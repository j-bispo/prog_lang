import cv2
import time

def capturar_imagem(cap, delay, filename='captura.jpg'):
    start_time = time.time()
    img_captured = False
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Erro ao capturar imagem.")
            break

        elapsed = int(time.time() - start_time)
        countdown = delay - elapsed

        if not img_captured and countdown > 0:
            msg = f"Capturando em {countdown}..."
            cv2.putText(frame, msg, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)
        elif not img_captured and countdown <= 0:
            msg = "Foto capturada!"
            cv2.putText(frame, msg, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2)
            cv2.imwrite(filename, frame)
            img_captured = True

        cv2.imshow('Webcam', frame)

        # Fecha a janela se a pessoa apertar ESC ou após capturar a foto
        key = cv2.waitKey(1) & 0xFF
        if key == 27:
            break

    cv2.destroyAllWindows()

    return cv2.imread(filename)