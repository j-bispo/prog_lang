import cv2

# Função para inicializar a câmera
def inicializar_camera(camera_id=0): 
    cap = cv2.VideoCapture(camera_id) 
    # Verifica se a câmera foi aberta corretamente
    if not cap.isOpened():
        print("Não foi possível acessar a câmera.")
        return None
    # Retorna a câmera
    return cap 