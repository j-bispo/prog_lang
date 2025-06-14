import cv2

def inicializar_camera(camera_id=0):
    cap = cv2.VideoCapture(camera_id)
    if not cap.isOpened():
        print("Não foi possível acessar a câmera.")
        return None
    return cap