import Converter


# Predefined
pc1_table = [57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4]

shiftArray = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

# PC-2 table (56-bit to 48-bit permutation)
pc2_table = [14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32]

ip_table = [58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7]

# E-box table (32-bit to 48-bit permutation)
e_box_table = [32, 1, 2, 3, 4, 5, 4, 5,
         6, 7, 8, 9, 8, 9, 10, 11,
         12, 13, 12, 13, 14, 15, 16, 17,
         16, 17, 18, 19, 20, 21, 20, 21,
         22, 23, 24, 25, 24, 25, 26, 27,
         28, 29, 28, 29, 30, 31, 32, 1]

# Define S-box tables as a dictionary
s_boxes = {
    1: [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
        [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]
    ],

    2: [
        [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
        [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
        [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
        [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]
    ],
    3: [
        [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
        [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
        [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
        [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]
    ],
    4: [
        [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
        [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
        [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
        [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]
    ],
    5: [
        [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
        [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
        [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
        [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]
    ],
    6: [
        [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
        [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
        [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]
    ],
    7: [
        [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
        [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
        [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]
    ],
    8: [
        [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
        [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
        [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
        [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]
    ]
}



P_box = [16, 7, 20, 21,
         29, 12, 28, 17,
         1, 15, 23, 26,
         5, 18, 31, 10,
         2, 8, 24, 14,
         32, 27, 3, 9,
         19, 13, 30, 6,
         22, 11, 4, 25]

IP_1 = [
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
]

# Bai 1
# In: 64-bit key-K, PC1 table
# Out: C0, D0
def pc1(key):
    """
    This function takes a 64-bit binary key as a string and returns a 56-bit permuted key
    using the PC1 table for DES.
    """

    permuted_key = ""
    for i in pc1_table:
        permuted_key += key[i - 1]
    size = len(permuted_key)

    return [permuted_key[0:size//2], permuted_key[size//2:size]]

# Bai 2
# Input: Ci, Di, Si
# Output: C(i+1), D(i+1)
def shift_left(string1, string2, int):
    A = string1[int:] + string1[0:int]  # Shift all characters to the left
    B = string2[int:] + string2[0:int]

    return A, B

# Bai 3
# In: Ci, Di, PC2 table (i >= 1)
# Out: K1
def pc2(C_part, D_part):
    """
    Performs Permuted Choice 2 (PC-2) on a 56-bit key to generate a 48-bit subkey.

    Args:
    key_56: A 56-bit binary string representing the input key.

    Returns:
    A 48-bit binary string representing the subkey after PC-2.
    """

    key_56 = C_part + D_part
    # Convert key to binary list
    key_binary = [int(c) for c in key_56]

    # Apply PC-2 permutation
    subkey_binary = [key_binary[i - 1] for i in pc2_table]

    # Convert subkey back to string
    subkey_string = "".join(str(c) for c in subkey_binary)

    return subkey_string

# Bai 4
# In: M, IP table
# Out: L0, R0
def initial_permutation(M):
    m_bin = Converter.hex_to_bin(M)

    permuted = ""
    for i in ip_table:
        # print("i = ", i, "mbin = ", m_bin[i-1])
        permuted += m_bin[i - 1]
    # print(f'per: {permuted}')
    size = len(ip_table)  # = 48
    return permuted[0: size//2], permuted[size//2: size]
    # return permuted[0:32], permuted[32:64]
# Bai 5
# In: R0 (kết quả bai 4)
# Out: E[R0]
def expand_right(right_half):
  """
  Performs the E-box permutation on a 32-bit right half of the DES state.

  Args:
    right_half: A 32-bit binary string representing the right half of the DES state.

  Returns:
    A 48-bit binary string representing the expanded right half after E-box.
  """

  # Convert right half to binary list
  right_binary = [int(c) for c in right_half]

  # Apply E-box permutation
  expanded_binary = [right_binary[i - 1] for i in e_box_table]

  # Convert expanded half back to string
  expanded_string = "".join(str(c) for c in expanded_binary)

  return expanded_string

# Bai 7
# In: A (= K1 XOR E[R0]), 8 bảng Si (1 <= i <= 8)
# Out: B = S(A)
def s_box(input):

    ans = ""
    for i in range(8):
        # Split the input_string into 6-bit-length strings
        a = input[(i * 6): (i + 1) * 6] #full: 010110


        b = Converter.bin_to_dec(a[0] + a[5]) # first part: 01 -> 1
        c = Converter.bin_to_dec(a[1:5]) # second part: 0110 -> 6

        d = s_boxes[i+1][int(b)][int(c)] #locate the value in s_box -> in the (i+1)th s_box, the b-th row and c-th column
        ans += str(Converter.dec_to_bin(str(d)))

    return ans

# bai 8: Thực hiện hoán vị P đối với SB
# In: B (kết quả bai 7), P
# Out: F
def p_box(data):
    permuted_data = ""

    for i in range(32):
        permuted_data += str(data[P_box[i] - 1])  # Adjust for 0-based indexing
    return permuted_data

print(p_box("11000110101011000001111001010111"))
# Bai 9: Thực hiện vòng lặp thứ nhất
# Input: L0 = ; R0 = (kết quả bài 4), F (kết quả bài 8)
# Output: L1 = R0 = ; R1 = L0 XOR F

def last_IP_1(key):
    permuted_key = ""
    for i in IP_1:
        permuted_key += key[i - 1]

    return permuted_key