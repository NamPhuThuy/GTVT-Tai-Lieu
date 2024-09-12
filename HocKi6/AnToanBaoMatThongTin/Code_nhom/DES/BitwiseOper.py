import Converter

def bin_xor_bin(bin_str1, bin_str2):
  if len(bin_str1) != len(bin_str2):
    raise ValueError("Binary strings must have equal length")

  result = ""
  for i in range(len(bin_str1)):
    if bin_str1[i] == bin_str2[i]:
      result += "0"
    else:
      result += "1"
  return result

def hex_xor_hex(hex1, hex2):
  binary = Converter.hex_to_bin(hex1)
  binary2 = Converter.hex_to_bin(hex2)

  return Converter.bin_to_hex(bin_xor_bin(binary, binary2))


print(hex_xor_hex("500F7CD3", "5FD982CD"))