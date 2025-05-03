import cv2
import numpy as np

# Function to detect green color in a frame
def detect_green(frame):
    # Convert the frame from BGR to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # Define the lower and upper bounds for green color in HSV
    lower_green = np.array([40, 100, 100])
    upper_green = np.array([80, 255, 255])

    # Threshold the HSV image to get only green color
    mask_green = cv2.inRange(hsv, lower_green, upper_green)

    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(frame, frame, mask=mask_green)

    return res

# Open the webcam
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Detect green color
    green_detect = detect_green(frame)

    # Display the original frame and the detected green color
    cv2.imshow('Original', frame)
    cv2.imshow('Green Detection', green_detect)

    # Break the loop when 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the capture
cap.release()
cv2.destroyAllWindows()
