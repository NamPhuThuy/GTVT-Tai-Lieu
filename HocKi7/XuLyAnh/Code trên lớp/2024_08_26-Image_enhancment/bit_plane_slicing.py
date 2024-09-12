import cv2
import numpy as np
import matplotlib.pyplot as plt

def bit_plane_slicing(image, plane):
    """
    Performs bit-plane slicing on an image.

    Args:
        image: The input image.
        plane: The bit plane to extract (0-7 for 8-bit images).

    Returns:
        The extracted bit plane as a NumPy array.
    """

    # Convert the image to grayscale if it's not already
    if len(image.shape) > 2:
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    else:
        gray = image

    # Create a mask to isolate the specified bit plane
    mask = 1 << plane

    # Extract the bit plane using bitwise AND and right shift
    bit_plane = (gray & mask) >> plane

    return bit_plane

def reconstruct_image(bit_planes):
    """
    Reconstructs an image from its bit planes.

    Args:
        bit_planes: A list of bit planes.

    Returns:
        The reconstructed image.
    """

    reconstructed_image = np.zeros_like(bit_planes[0])
    for i in range(8):
        reconstructed_image |= bit_planes[i] << i
    return reconstructed_image

# Load the image
image = cv2.imread('../images/wukong.jpg')

# Extract bit planes 0-7
bit_planes = [bit_plane_slicing(image, i) for i in range(8)]

for i, bit_plane in enumerate(bit_planes):
    plt.imshow(bit_plane.astype(np.float32), cmap='gray')
    plt.title(f'Bit Plane {i}')
    plt.show()

# Reconstruct the image from the bit planes
reconstructed_image = reconstruct_image(bit_planes)

# Display the reconstructed image
cv2.imshow('Reconstructed Image', reconstructed_image)
cv2.waitKey(0)

cv2.destroyAllWindows()