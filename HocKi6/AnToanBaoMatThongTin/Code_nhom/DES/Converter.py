def hex_to_bin(key_hex):
    """
  Converts a hexadecimal string to its binary equivalent.

  Args:
      hex_str: The hexadecimal string to be converted.

  Returns:
      The binary equivalent of the hexadecimal string.
  """

    hex_to_bin_dict = {
        "0": "0000", "1": "0001", "2": "0010", "3": "0011",
        "4": "0100", "5": "0101", "6": "0110", "7": "0111",
        "8": "1000", "9": "1001", "A": "1010", "B": "1011",
        "C": "1100", "D": "1101", "E": "1110", "F": "1111"
    }

    binary_str = ""
    for char in key_hex.upper():
        if char not in hex_to_bin_dict:
            raise ValueError(f"Invalid hexadecimal character: {char}")
        binary_str += hex_to_bin_dict[char]
    return binary_str

def bin_to_hex(binary):
  """
  Converts a binary string to its hexadecimal equivalent.
  """
  # Ensure binary string length is divisible by 4
  if len(binary) % 4 != 0:
    raise ValueError("Binary string length must be a multiple of 4")

  hex_map = {
      "0000": "0",
      "0001": "1",
      "0010": "2",
      "0011": "3",
      "0100": "4",
      "0101": "5",
      "0110": "6",
      "0111": "7",
      "1000": "8",
      "1001": "9",
      "1010": "A",
      "1011": "B",
      "1100": "C",
      "1101": "D",
      "1110": "E",
      "1111": "F"
  }

  hex_string = ""
  for i in range(0, len(binary), 4):
    # Group 4 binary digits
    group = binary[i:i+4]
    # Convert group to hexadecimal using dictionary lookup
    hex_string += hex_map[group]
  return hex_string

def bin_to_dec(binary_string):
 if not binary_string.isdigit():
   raise ValueError("Input string must contain only digits (0 or 1).")

 decimal_value = 0
 for i, digit in enumerate(reversed(binary_string)):
   if digit == '1':
     decimal_value += 2**i
 return str(decimal_value)

def dec_to_bin(decimal_str):
    # Handle negative numbers
    if decimal_str[0] == '-':
        return '-' + dec_to_bin(decimal_str[1:])  # Convert absolute value and prepend '-'

    decimal = int(decimal_str)
    binary = ""
    while decimal > 0:
        remainder = decimal % 2
        binary = str(remainder) + binary
        decimal //= 2

    binary = "0" * (4 - len(binary)) + binary
    return binary