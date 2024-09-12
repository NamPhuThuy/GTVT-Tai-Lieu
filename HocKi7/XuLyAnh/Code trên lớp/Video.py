import cv2

def main():
    # Open the video capture device (0 for default camera)
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error opening video stream or file")
        return

    while True:
        ret, frame = cap.read()

        if not ret:
            print("Error reading frame")
            break

        # Process the frame here (e.g., apply filters, detect objects)

        cv2.imshow('frame', frame)

        if cv2.waitKey(1) == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()