from constants import *
import Converter


class Des:
    @staticmethod
    def GenerateKey(key):
        k = ''
        for i in key:
            k += bin(int(i, 16))[2:].zfill(4)

        res = ''
        for i in PC_1:
            res += k[i-1]
        return res
    @staticmethod
    def GeneratePlain(plain):
        p = ''
        for i in plain:
            p += bin(int(i, 16))[2:].zfill(4)
        print(f'plain: {p}')

        res = ''
        for i in IP:
            res += p[i-1]

        print(f'res: {res}')
        return res

    @staticmethod
    def CreateKey(key):
        k = Des.GenerateKey(key)
        C = k[0:28]
        D = k[28:56]

        res = []

        for i in range(16):
            C = C[LeftShift[i]:] + C[:LeftShift[i]]
            D = D[LeftShift[i]:] + D[:LeftShift[i]]
            CD = C + D
            K = ''
            for v in PC_2:
                K += CD[v-1]
            res.append(K)

        return res

    @staticmethod
    def AxorB(a, b):
        res = ''
        for i in range(len(a)):
            if a[i] == b[i]:
                res += '0'
            else:
                res += '1'
        return res

    @staticmethod
    def solve(plain, key):
        res = ''
        LR = []

        # List of keys
        k = Des.CreateKey(key)
        for i in range(len(k)):
            # print(f'K({i}) = {k[i]}')
            print(Converter.bin_to_hex(k[i]))

        p = Des.GeneratePlain(plain)

        left = p[0:32]
        right = p[32:64]
        # print(f'bin: l: {left}, r:{right}')
        # print(f'l = {Converter.bin_to_hex(left)}, r = {Converter.bin_to_hex(right)}')
        #
        # print(Converter.bin_to_hex("10010011011001101101000111010100"))

        LR.append((left, right))
        print()

        for i in range(16):
            Er = ''
            Sr = ''
            Pr = ''
            for e in E_Box:
                Er += right[e-1]

            print(f'Expand: {Converter.bin_to_hex(Er)}')

            # print(hex(int(Er,2))[2:])
            Er = Des.AxorB(Er, k[i])
            # print(hex(int(Er,2))[2:])
            print(f'A = Er Xor k[{i}] = {Converter.bin_to_hex(Er)}')

            for j in range(8):
                sr = Er[j * 6:j * 6 + 6]
                row = int(sr[0] + sr[-1], 2)
                col = int(sr[1:5], 2)
                # print(row, col)
                v = S_Box[j][row][col]
                Sr += bin(v)[2:].zfill(4)

            # print(hex(int(Sr,2))[2:])
            print(f'B = S_box(A) = {Converter.bin_to_hex(Sr)}' )
            for p in P_Box:
                Pr += Sr[p-1]
            # print(hex(int(Pr, 2))[2:])
            print(f'F = P_box(B) = {Converter.bin_to_hex(Pr)}')

            left = LR[-1][1]
            right = Des.AxorB(Pr, LR[-1][0])
            LR.append((left, right))

            print(Converter.bin_to_hex(LR[-1][0]))
            print(Converter.bin_to_hex(LR[-1][1]))
            # print(hex(int(LR[-1][1] + LR[-1][0], 2))[2:].zfill(2))
            print()

        M = LR[-1][1] + LR[-1][0]
        print(f"{M}")
        for i in IP_1:
            res += M[i-1]
        return hex(int(res, 2))[2:].zfill(2)

if __name__ == '__main__':
    plain = '66581B2AE5B0BD6D'
    key = '03756CD378146EC7'
    print(Des.solve(plain, key))