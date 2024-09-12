from unitAES import *
class AES:
    def __init__(self, plainText, cipherKey, n):
        self.n = n
        self.plainText = self.AddToMatrix(plainText)
        self.cipherKey = self.AddToMatrix(cipherKey)

    def AddToMatrix(self, str):
        matrix = [[0] * self.n for _ in range(self.n)]
        index = 0
        for i in range(0, len(str),2):
            row = index % self.n
            col = index // self.n
            matrix[row][col] = str[i:i+2]
            index +=1
        return matrix

    def printMatrix(self, matrix):
        for row in matrix:
            for v in row:
                print(v, end=' ')
            print()
    def RootWord(self,row, n):
        return row[n:] + row[:n]

    def SubWord(self, matrix):
        for i in range(self.n):
            v = matrix[i]
            row = int(v[0], 16)
            col = int(v[1], 16)
            matrix[i] = S_Box[row][col]
        return matrix

    def Xor(self, a, b):
        return hex(int(a, 16) ^ int(b, 16))[2:].zfill(2)

    def CreateKey(self,indexRC):
        firstE = [self.cipherKey[i][0] for i in range(self.n)]
        w0 = [self.cipherKey[i][self.n - 1] for i in range(self.n)]
        w0 = self.RootWord(w0, 1)
        w0 = self.SubWord(w0)
        w0[0] = self.Xor(w0[0], RC[indexRC - 1])

        for i in range(self.n):
            self.cipherKey[i][0] = self.Xor(w0[i], firstE[i])
        for col in range(1, self.n):
            for i in range(self.n):
                self.cipherKey[i][col] = self.Xor(self.cipherKey[i][col], self.cipherKey[i][col - 1])
        #print(self.cipherKey)
        self.printMatrix(self.cipherKey)

    def SubBytes(self, matrix):
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                v = matrix[i][j]
                row = int(v[0], 16)
                col = int(v[1], 16)
                matrix[i][j] = S_Box[row][col]
        return matrix

    def ShiftRows(self, matrix):
        for i in range(self.n):
            matrix[i] = self.RootWord(matrix[i], i)
        return  matrix

    def mixColumns(self, matrix):
        mixMatrix = [[0] * self.n for _ in range(self.n)]
        for row in range(self.n):
            for col in range(self.n):
                mixMatrix[row][col] = self.resMix(matrix, row, col)
        # self.printMatrix(mixMatrix)
        return mixMatrix

    def resMix(self, matrix, row, col):
        res = 0
        for i in range(self.n):
            mbin = bin(int(matrix[i][col], 16))[2:].zfill(8)
            # print(matrix[i][col] + " " + mbin + " " + mbin[0] + " " + (mbin[1:] + '0'))
            if M_Mix[row][i] == '02':
                if mbin[0] == '0':
                    res ^= int(mbin[1:] + '0', 2)
                else:
                    res ^= int(mbin[1:] + '0', 2) ^ int('1b', 16)
            elif M_Mix[row][i] == '03':
                res ^= int(matrix[i][col], 16)
                if mbin[0] == '0':
                    res ^= int(mbin[1:] + '0', 2)
                else:
                    res ^= int(mbin[1:] + '0', 2) ^ int('1b', 16)
            else:
                res ^= int(matrix[i][col], 16)
        return hex(res)[2:].zfill(2)

    def AddRoundKey(self,matrix):
        for row in range(self.n):
            for col in range(self.n):
                matrix[row][col] = self.Xor(matrix[row][col], self.cipherKey[row][col])
        return matrix

    def solve(self, matrix):
        res = self.AddRoundKey(self.plainText)
        solution_lines = []

        for i in range(1,11):
            print("Vòng lặp thứ " + str(i))
            print("State = " + str(res))
            solution_lines.append("\n")
            solution_lines.append("Vòng lặp thứ " + str(i))
            solution_lines.append("State = " + str(res))

            res = self.SubBytes(res)
            print("Sau SubBytes: " + str(res))
            solution_lines.append("Sau SubBytes: " + str(res))

            res = self.ShiftRows(res)
            print("Sau ShiftRows: " + str(res))
            solution_lines.append("Sau ShiftRows: " + str(res))

            if i != 10:
                res = self.mixColumns(res)
                print("Sau MixColumns: " + str(res))
                solution_lines.append("Sau MixColumns: " + str(res))


            self.CreateKey(i)
            res = self.AddRoundKey(res)
            print("AddRoundKey(state, K"+str(i)+" ) = " + str(res))
            solution_lines.append("AddRoundKey(state, K" + str(i) + " ) = " + str(res))

        return solution_lines

def ReadFile(filename:str):
    with open(filename, "r") as file:
        lines = file.readlines()
        if len(lines) >= 2:
            plainText = lines[0].strip()
            cipherKey = lines[1].strip()

    return plainText, cipherKey

def printFile(filename: str, lines: list):
    with open(filename, "w", encoding="utf-8") as file:
        for line in lines:
            file.write(line + "\n")


if __name__ == '__main__':
    plainText, cipherKey = ReadFile('input.txt')
    a = AES(plainText, cipherKey, 4)
    solution = a.solve(a.plainText)
    print(solution)
    printFile("output.txt", solution)