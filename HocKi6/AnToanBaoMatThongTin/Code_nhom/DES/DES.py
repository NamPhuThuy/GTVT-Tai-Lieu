import Algorithm
import Converter
import BitwiseOper
import copy

key_list = []
C_list = []
D_list = []

if __name__ == '__main__':

    # K = "03756CD378146EC7"
    # M = "66581B2AE5B0BD6D"

    K = ''
    M = ''
    with open("Input.txt", "r") as file:
        a = [str(i) for i in file.read().split()]
        print(a)
        K = a[0]
        M = a[1]
        pass


    # Prepare 16 keys for the algo
    with open("Output.txt", "w") as f:
        C0, D0 = Algorithm.pc1(Converter.hex_to_bin(K))
        f.write(f"C0 = {Converter.bin_to_hex(C0)}, \nDo = {Converter.bin_to_hex(D0)}\n")
        # print("C0 = ", Converter.bin_to_hex(C0), "Do = ", Converter.bin_to_hex(D0))


        for i in range(16):
            C0, D0 = Algorithm.shift_left(C0, D0, Algorithm.shiftArray[i])
            key_list.append(Algorithm.pc2(C0, D0))

        for i in range(len(key_list)):
            f.write(f'K({i}) = {key_list[i]}\n')
            f.write(f'K({i}) = {Converter.bin_to_hex(key_list[i])}\n')

        f.write("\n")

        L, R = Algorithm.initial_permutation(M)  # đã check với làm tay
        f.write(f"L = {Converter.bin_to_hex(L)}\nR = {Converter.bin_to_hex(R)}\n")

        # Đúng tới lần lặp thứ 2
        # R của lần lặp thứ 3 thì có lỗi
        # The main encode-loop
        for i in range(16):
            # print("Lần lặp thứ ", i + 1, ": ")
            tmpL = copy.copy(L)
            tmpR = copy.copy(R)

            tmpR = Algorithm.expand_right(tmpR)  # đúng với i = 0
            A = BitwiseOper.bin_xor_bin(tmpR, key_list[i])  # đúng với i = 0

            f.write(f"eR = {Converter.bin_to_hex(tmpR)}\nA = {Converter.bin_to_hex(A)}\n")

            B = Algorithm.s_box(A)  # đúng với i = 0
            f.write(f"b = {Converter.bin_to_hex(B)}\n")

            F = Algorithm.p_box(B)  # đúng với i = 0
            f.write(f"f = {Converter.bin_to_hex(F)}\n")

            tmpL = R

            tmpR = BitwiseOper.bin_xor_bin(L, F)  # đúng với i = 0
            f.write(f"L({i + 1}) = {Converter.bin_to_hex(tmpL)}\nR({i + 1}) = {Converter.bin_to_hex(tmpR)}\n\n")

            R = tmpR
            L = tmpL



        lastKey = R + L
        f.write(f'last key: {lastKey}\n')
        cipherBinar = Algorithm.last_IP_1(lastKey)
        cipherHex = Converter.bin_to_hex(cipherBinar)
        f.write(f"CipherText = {cipherHex}")