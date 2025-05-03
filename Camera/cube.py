import cv2
from cube_detector import CubeDetector

def main():
    # Open video capture device (webcam)
    cap = cv2.VideoCapture(0)

    # Initialize cube detector
    detector = CubeDetector()

    while True:
        # Capture frame-by-frame
        ret, frame = cap.read()

        if ret:
            # Detect and draw cube outlines
            output_frame = detector.detect_and_draw_cubes(frame)

            # Display the resulting frame
            cv2.imshow('Cube Detection', output_frame)

        # Break the loop when 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the capture device and close all windows
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
