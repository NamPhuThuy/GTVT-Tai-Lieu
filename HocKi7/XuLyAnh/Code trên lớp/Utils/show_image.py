import matplotlib.pyplot as plt
import numpy as np

def show_with_matplotlib(img_BGR, title):
    # Convert BGR image to RGB:
    img_RGB = img_BGR[:, :, ::-1]

    # Show the image using matplotlib:
    plt.imshow(img_RGB)
    plt.title(title)
    plt.show()

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
        print("Debug: ", i)
        image_RGB = image_BGR[:, :, ::-1]
        print("Debug: 00")


        plt.imshow(image_RGB)
        print("Debug: 1")

        plt.title(title)
        print("Debug: 2")
        plt.subplot(rowsNum, colsNum, pos)
        print("Debug: 3")
        plt.axis('off')
        print("Debug: show complete")

    plt.tight_layout()
    plt.show()
