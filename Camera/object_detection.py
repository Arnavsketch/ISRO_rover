import cv2
import imutils
import math

###################################
webcam = True
path = '1.jpg'  # Path to the image file if not using webcam
cap = cv2.VideoCapture(0)
cap.set(10, 160)
cap.set(3, 1920)
cap.set(4, 1080)
scale = 3
###################################

def distance(point1, point2):
    return math.sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)

def detect_obstacle(img, obstacle_type, obstacle_size):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    edged = cv2.Canny(blurred, 30, 150)

    contours = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = imutils.grab_contours(contours)

    for contour in contours:
        area = cv2.contourArea(contour)
        if area > 500:  # Filter out small contours
            perimeter = cv2.arcLength(contour, True)
            approx = cv2.approxPolyDP(contour, 0.02 * perimeter, True)
            x, y, w, h = cv2.boundingRect(approx)
            aspect_ratio = w / float(h)
            if obstacle_type == 'Cube':
                if abs(w - obstacle_size) <= 5 and abs(h - obstacle_size) <= 5 and 0.8 <= aspect_ratio <= 1.2:
                    cv2.drawContours(img, [contour], -1, (0, 255, 0), 2)
                    cv2.putText(img, obstacle_type, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    cv2.putText(img, f"Size: {obstacle_size} mm", (x, y - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            elif obstacle_type == 'Crater':
                radius = max(w, h) // 2
                diameter = radius * 2
                if abs(diameter - obstacle_size) <= 10 and 0.8 <= aspect_ratio <= 1.2:
                    cv2.drawContours(img, [contour], -1, (0, 0, 255), 2)
                    cv2.putText(img, obstacle_type, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
                    cv2.putText(img, f"Size: {obstacle_size} mm", (x, y - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

while True:
    if webcam:
        success, img = cap.read()
    else:
        img = cv2.imread(path)

    img = imutils.resize(img, width=640)  # Resize the image for better processing

    detect_obstacle(img, 'Cube', 150)  # Detect Cube obstacle of side 150 mm
    detect_obstacle(img, 'Cube', 300)  # Detect Cube obstacle of side 300 mm
    detect_obstacle(img, 'Crater', 200)  # Detect Crater obstacle of diameter 200 mm
    detect_obstacle(img, 'Crater', 400)  # Detect Crater obstacle of diameter 400 mm

    cv2.imshow('Obstacle Detection', img)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
