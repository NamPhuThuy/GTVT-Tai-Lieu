def read_file_to_list_of_lists(filename):
  """
  Reads a file and stores the content in a list of lists.

  Args:
      filename: The path to the text file.

  Returns:
      A list of lists, where each inner list represents a line in the file.
  """
  data = []
  with open(filename, 'r') as f:
    lines = f.readlines()
    for line in lines:
      # Remove trailing whitespace and split based on spaces
      content = line.strip().split(' v ')
      # Skip empty lines
      if content:
        data.append(content)
  return data

# Example usage
filename = "Input.txt"  # Replace with your actual file name
list_of_lists = read_file_to_list_of_lists(filename)

print(list_of_lists)