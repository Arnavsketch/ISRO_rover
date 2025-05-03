import cv2
import numpy as np

class CubeDetector:
    def __init__(self):
        pass

    def filter_contours(self, contours):
        approximations = []
        for contour in contours:
            perimeter = cv2.arcLength(contour, True)
            approximation = cv2.approxPolyDP(contour, 0.04 * perimeter, True)
            if len(approximation) == 4:
                approximations.append(approximation)
        return approximations

    def detect_and_draw_cubes(self, frame):
        # Convert frame to grayscale
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Apply Gaussian blur to reduce noise
        blurred = cv2.GaussianBlur(gray, (5, 5), 0)

        # Perform edge detection
        edges = cv2.Canny(blurred, 50, 150)

        # Find contours in the edge-detected image
        contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # Filter contours to only keep those representing cube shapes
        cube_contours = self.filter_contours(contours)

        # Draw outlines of cube-shaped objects on the frame
        for contour in cube_contours:
            cv2.drawContours(frame, [contour], -1, (0, 255, 0), 2)

        return frame
