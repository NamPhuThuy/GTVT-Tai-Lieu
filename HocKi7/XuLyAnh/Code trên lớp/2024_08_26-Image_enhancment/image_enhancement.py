import cv2
import numpy as np
import matplotlib.pyplot as plt

def show_images_with_titles_and_positions(image_BGR_list, title_list, pos_list, big_title, colsNum = 4, xLabel = 'x axis', yLabel = 'y axis'):
    """
    Displays a list of images with specified titles and positions using Matplotlib subplots.

    Args:
        image_BGR_list: A list of NumPy image arrays.
        title_list: A list of titles for each image (optional).
        pos_list: A list of subplot positions (optional).
    """

    # Create the dimensions of the figure and set title:
    plt.figure(figsize=(12, 6))
    plt.suptitle(big_title, fontsize=14, fontweight='bold')

    num_images = len(image_BGR_list)

    # make sure every image has a title
    if not title_list:
        title_list = [f"Image {i+1}" for i in range(num_images)]
    if not pos_list:
        pos_list = range(1, num_images + 1)

    rowsNum = int(np.ceil(num_images / colsNum))
    print("Row number:", rowsNum, "Column number:", colsNum)

    # Add images to the plot 
    for i, (image_BGR, title, pos) in enumerate(zip(image_BGR_list, title_list, pos_list)):
        image_RGB = image_BGR[:, :, ::-1]

        plt.imshow(image_RGB)

        plt.title(title)
        plt.subplot(rowsNum, colsNum, pos)
        plt.axis('off')

    plt.tight_layout()
    plt.show()

def negative_image_example():
    # Load the image
    image = cv2.imread('../images/wukong.jpg')
    
    # Invert the colors (create the negative image)
    negative_image = 255 - image
    
    image_BGR_list = [image, negative_image]
    title_list = ['Original Image', 'Negative Image']
    pos_list = [1, 2]
    
    show_images_with_titles_and_positions(image_BGR_list, title_list, pos_list, "Example", 2)

def log_transformation_example():
    image = cv2.imread('../images/jungle.png')
    # Convert the image to floating-point data type for calculations
    temp_image = image.astype(np.float32)

    # Add 1 to avoid log(0)
    temp_image += 1

    # Apply the logarithmic transformation
    '''
    np.max(temp_image): Calculate the maximum pixel value in the image.
    np.log(1 + np.max(temp_image)): Takes the natural logarithm of the maximum pixel value plus 1. This is done to avoid taking the logarithm of 0, which is undefined.
    255 / np.log(1 + np.max(temp_image)): Divides 255 (the maximum pixel value for 8-bit images) by the calculated logarithm. This scaling factor ensures that the enhanced image values will fall within the range of 0 to 255.'''
    c = 255 / np.log(1 + np.max(temp_image))
    enhanced_image = (c / 2) * np.log(temp_image)

    # Convert back to 8-bit integer
    enhanced_image = enhanced_image.astype(np.uint8)

    image_BGR_list = [image, enhanced_image]
    title_list = ['Original Image', 'After effect Image']
    pos_list = [1, 2]

    show_images_with_titles_and_positions(image_BGR_list, title_list, pos_list, "Example", 2)


def power_transform_example():
    """Applies a power-law transformation to enhance the image."""
    
    # Convert the image to floating-point data type for calculations
    image = cv2.imread('../images/jungle.png')
    gamma = 0.4
    temp_image = image.astype(np.float32)

    # Apply the power-law transformation
    c = 255 / np.power(np.max(temp_image), gamma)
    enhanced_image = c * np.power(temp_image, gamma)

    # Convert back to 8-bit integer
    enhanced_image = enhanced_image.astype(np.uint8)

    image_BGR_list = [image, enhanced_image]
    title_list = ['Original Image', 'After effect Image']
    pos_list = [1, 2]
    
    show_images_with_titles_and_positions(image_BGR_list, title_list, pos_list, "Example", 2)


# Applies contrast stretching to the image.
def contrast_stretching_example():
    image = cv2.imread('../images/cat.png')
    a = 45
    b = 120
    """
    Args:
        image: The input image.
        a: The minimum value of the output range.
        b: The maximum value of the output range.
    a=0, b=255: Full contrast stretching, mapping the entire range of pixel values to the full output range.
    a > 0, b < 255: Reduces contrast, compressing the range of pixel values.
    a < 0, b > 255: Increases contrast, expanding the range of pixel values.
    """

    # Find the minimum and maximum pixel values in the image
    min_val = np.min(image)
    max_val = np.max(image)

    # Calculate the scaling factor
    c = (b - a) / (max_val - min_val)
    d = a - c * min_val

    # Apply the contrast stretching transformation
    stretched_image = c * image + d

    # Clip the values to ensure they are within the valid range
    stretched_image = np.clip(stretched_image, 0, 255).astype(np.uint8)
    image_BGR_list = [image, stretched_image]
    title_list = ['Original Image', 'After effect Image']
    pos_list = [1, 2]
    
    show_images_with_titles_and_positions(image_BGR_list, title_list, pos_list, "Example", 2)
    

if __name__ == "__main__":
    negative_image_example()
    # log_transformation_example()
    # power_transform_example()
    # contrast_stretching_example()