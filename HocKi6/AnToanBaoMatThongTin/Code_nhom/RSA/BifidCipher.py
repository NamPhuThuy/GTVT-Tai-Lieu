def create_polybius_square(key):
  """
  Creates a Polybius square using the given key.

  Args:
      key: A string to use as the base for the square.

  Returns:
      A list of lists representing the Polybius square.
  """
  alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  square = []
  row = []
  for char in key:
    if char.upper() not in row and char.upper() in alphabet:
      row.append(char.upper())
  for char in alphabet:
    if char.upper() not in row and char.upper() not in key:
      row.append(char.upper())
    if len(row) == 5:
      square.append(row)
      row = []
  if len(row) > 0:
    square.append(row)
  return square

def find_position(char, square):
  """
  Finds the row and column position of a character in the square.

  Args:
      char: The character to find.
      square: The Polybius square.

  Returns:
      A tuple containing the row and column position (0-indexed).
  """
  for row_index, row in enumerate(square):
    for col_index, col_char in enumerate(row):
      if col_char == char.upper():
        return row_index, col_index

def bifid_encrypt(message, key):
  """
  Encrypts a message using the Bifid cipher.

  Args:
      message: The message to encrypt.
      key: The key to use for encryption.

  Returns:
      The encrypted message.
  """
  square = create_polybius_square(key)
  encrypted_message = ""
  for char in message.upper():
    if char.isalpha():
      row, col = find_position(char, square)
      encrypted_message += str(row + 1) + str(col + 1)
    else:
      encrypted_message += char
  return encrypted_message

def bifid_decrypt(encrypted_message, key):
  """
  Decrypts a message encrypted with the Bifid cipher.

  Args:
      encrypted_message: The encrypted message to decrypt.
      key: The key used for encryption.

  Returns:
      The decrypted message.
  """
  square = create_polybius_square(key)
  decrypted_message = ""
  for i in range(0, len(encrypted_message), 2):
    if i < len(encrypted_message):
      row = int(encrypted_message[i]) - 1
      col = int(encrypted_message[i+1]) - 1
      decrypted_message += square[row][col]
  return decrypted_message

# Example usage
message = "BLFEIGIOUA"
key = "THERE"

encrypted_message = bifid_encrypt(message, key)

encrypted_message = "BLFEIGIOUA"
decrypted_message = bifid_decrypt(encrypted_message, key)

print("Original message:", message)
print("Encrypted message:", encrypted_message)
print("Decrypted message:", decrypted_message)