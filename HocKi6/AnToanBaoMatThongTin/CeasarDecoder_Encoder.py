def caesar_decoder(text, shift, mode):
  """
  Decodes or encodes text using a Caesar cipher.

  Args:
    text: The text to decode or encode.
    shift: The number of positions to shift the letters.
    mode: 'decode' to decode, 'encode' to encode.

  Returns:
    The decoded or encoded text.
  """

  result = ""
  for char in text:
    if char.isalpha():
      base = ord('A') if char.isupper() else ord('a')
      new_char_code = (ord(char) - base + shift * (-1 if mode == 'decode' else 1)) % 26 + base
      result += chr(new_char_code)
    else:
      result += char
  return result

def caesar_encoder(text, shift, mode='encode'):
    """Encodes or decodes text using a Caesar cipher."""

    result = ""
    for char in text:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            new_char_code = (ord(char) - base + shift) % 26 + base
            result += chr(new_char_code)
        else:
            result += char
    return result

# Example usage:
encrypted_text = "Khoor Zruog!"

shift = 3
decoded_text = caesar_decoder(encrypted_text, shift, 'decode')
encoded_text = caesar_decoder("Hello World!", shift, 'encode')

print(decoded_text)  # Output: Hello World!
print(encoded_text)