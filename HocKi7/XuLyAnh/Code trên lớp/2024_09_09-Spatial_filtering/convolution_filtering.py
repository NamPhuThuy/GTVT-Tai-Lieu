import numpy as np

def convolution_filter(input_matrix, operator_matrix, padding=0):
    """
    Performs convolution filtering on an input matrix using the given operator matrix.
  
    Args:
      input_matrix: The input matrix to be filtered.
      operator_matrix: The operator matrix used for convolution.
      padding: The amount of zero padding to apply to the input matrix.
  
    Returns:
      The resulting filtered matrix.
    """

    # Apply zero padding to the input matrix if specified
    if padding > 0:
        padded_input = np.pad(input_matrix, ((padding, padding), (padding, padding)), 'constant')
    else:
        padded_input = input_matrix

    # Calculate the output matrix dimensions
    output_shape = (padded_input.shape[0] - operator_matrix.shape[0] + 1,
                    padded_input.shape[1] - operator_matrix.shape[1] + 1)

    # Create the output matrix
    output_matrix = np.zeros(output_shape)

    # Perform convolution
    for i in range(output_shape[0]):
        for j in range(output_shape[1]):
            for k in range(operator_matrix.shape[0]):
                for l in range(operator_matrix.shape[1]):
                    output_matrix[i, j] += padded_input[i + k, j + l] * operator_matrix[k, l]

    return output_matrix

# Example usage
if __name__ == "__main__":
    input_matrix = np.array([[5, 5, 5, 5, 5, 5, 5],
                             [4, 5, 5, 5, 5, 5, 5],
                             [3, 4, 5, 5, 5, 5, 5],
                             [3, 3, 4, 5, 5, 5, 5],
                             [3, 3, 3, 4, 4, 4, 4],
                             [3, 3, 3, 3, 3, 3, 3],
                             [3, 3, 3, 3, 3, 3, 3]])
    
    operator_matrix = np.array([[-1, 0, 1],
                                [-1, 0, 1],
                                [-1, 0, 1]])
    
    result_matrix = convolution_filter(input_matrix, operator_matrix, padding=1)
    
    print(result_matrix)