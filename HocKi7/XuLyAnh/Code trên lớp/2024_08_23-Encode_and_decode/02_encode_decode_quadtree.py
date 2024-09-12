import cv2
import numpy as np

def quadtree_encode(image):
    """Encodes an image using a quadtree.

    Args:
        image: The input image as a NumPy array.

    Returns:
        A list of tuples representing the quadtree nodes. Each tuple contains:
            - The node type (0 for leaf, 1 for internal node)
            - The pixel value (for leaf nodes)
            - The top-left corner coordinates of the node
            - The width and height of the node
    """

    encoded_data = []
    _quadtree_encode_recursive(image, 0, 0, image.shape[0], image.shape[1], encoded_data)
    return encoded_data

def _quadtree_encode_recursive(image, x, y, width, height, encoded_data):
    if width == 1 and height == 1:
        encoded_data.append((0, image[y, x], x, y, width, height))
        return

    avg_pixel = np.mean(image[y:y+height, x:x+width])
    is_uniform = np.all(image[y:y+height, x:x+width] == avg_pixel)

    if is_uniform:
        encoded_data.append((0, avg_pixel, x, y, width, height))
        return

    # Divide the image into four quadrants
    mid_x = x + width // 2
    mid_y = y + height // 2

    # Recursively encode each quadrant
    _quadtree_encode_recursive(image, x, y, width // 2, height // 2, encoded_data)
    _quadtree_encode_recursive(image, mid_x, y, width // 2, height // 2, encoded_data)
    _quadtree_encode_recursive(image, x, mid_y, width // 2, height // 2, encoded_data)
    _quadtree_encode_recursive(image, mid_x, mid_y, width // 2, height // 2, encoded_data)

def quadtree_decode(encoded_data, shape):
    """Decodes a quadtree-encoded image.

    Args:
        encoded_data: The encoded quadtree data.
        shape: The shape of the original image.

    Returns:
        The decoded image as a NumPy array.
    """

    decoded_image = np.zeros(shape, dtype=np.uint8)
    for node in encoded_data:
        node_type, pixel_value, x, y, width, height = node
        if node_type == 0:
            decoded_image[y:y+height, x:x+width] = pixel_value
    return decoded_image

# Example usage
image = cv2.imread('../images/cat.png')
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

encoded_data = quadtree_encode(gray)
decoded_image = quadtree_decode(encoded_data, gray.shape)

cv2.imshow('Original Image', gray)
cv2.imshow('Decoded Image', decoded_image)
cv2.waitKey(0)
cv2.destroyAllWindows()