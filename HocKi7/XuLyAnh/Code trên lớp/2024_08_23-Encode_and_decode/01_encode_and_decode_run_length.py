import cv2
import numpy as np

def runlenghtdecodetest(thresh,m,n):
    y = np.zeros((m, n), dtype = np.uint8)
    count = 0
    for i in range(len(thresh)):
        for j in range(thresh[i][1]):
            y[count//n, count%n] = thresh[i][0]
            count += 1
    return y

def runlenghtencodetest(thresh, m, n):
    thresh = thresh.flatten()
    count = 1
    y = []
    for i in range(len(thresh) - 1):
        if thresh[i] == thresh[i + 1]:
            count += 1
        else:
            y.append([int(thresh[i]), count])
            count = 1
    y.append([int(thresh[i]), count])
    return y

if __name__ == "__main__":
    gray_image = cv2.imread('../images/avatar.png', cv2.IMREAD_GRAYSCALE)
    
    # Threasholding (Ngưỡng hóa) to convert a grayscale image into a binary image
    '''
    gray_image: input grayscale image.
    127: Threshold value. 
        Pixels with values >= 127 will be set to 255 (white)
        Pixels with values < 127 will be set to 0 (black).
        
    255: Maximum value for the output image (usually 255 for 8-bit images).
    cv2.THRESH_BINARY: The thresholding type. This type sets pixels to either 0 or 255 based on the threshold.
    '''
    ret, thresh = cv2.threshold(gray_image, 127, 255, cv2.THRESH_BINARY)
    
    # Display the binary image
    cv2.imshow('Binary Image', thresh)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
    
    np.savetxt('binary_image.txt', thresh, fmt='%d')
    
    # Convert binary image into 1-dimension array
    
    rl = runlenghtencodetest(thresh,thresh.shape[0],thresh.shape[1])
    print(rl)
    res = runlenghtdecodetest(rl,thresh.shape[0],thresh.shape[1])
    print(res)
    cv2.imshow('Binary Image', res)
    cv2.waitKey(0)
    cv2.destroyAllWindows()