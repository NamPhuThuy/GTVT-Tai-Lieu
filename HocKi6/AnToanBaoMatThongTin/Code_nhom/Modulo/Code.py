class Modulo:
    @staticmethod
    def modul(a, m, n):
        res = 1
        a %= n
        l = [a]
        m1 = bin(m)[2:]
        for i in reversed(m1):
            x = l[-1]
            if i == '1':
                res = (res * x) % n
            l.append((x * x) % n)
        return res


class ExtendEuclid:
    @staticmethod
    def EEuclid(a, b):
        if a == 0:
            return 1, 0, b
        else:
            x, y, gcd = ExtendEuclid.EEuclid(b % a, a)
            return y, x - (b // a) * y, gcd

    @staticmethod
    def modul(a, n):
        x, y, gcd = ExtendEuclid.EEuclid(a, n)
        if gcd != 1:
            return "No cmt"
        else:
            return y if y > 0 else n + y


class Euler:
    @staticmethod
    def prime(n):
        d = {}
        while n % 2 == 0:
            if 2 in d:
                d[2] += 1
            else:
                d[2] = 1
            n = n // 2

        for i in range(3, int(n ** 0.5) + 1, 2):
            while n % i == 0:
                if i in d:
                    d[i] += 1
                else:
                    d[i] = 1
                n = n // i

        if n > 2:
            d[n] = 1

        return d

    @staticmethod
    def Modul(n):
        res = 1
        d = Euler.prime(n)
        for k, v in d.items():
            res *= k ** v - k ** (v - 1)
        return res


class ModulChina:
    @staticmethod
    def Modul(m, a):
        M = 1
        for i in m:
            M *= i

        res = 0
        for i in range(len(m)):
            m_ = M // m[i]
            x = ExtendEuclid.modul(m_, m[i])
            res += a[i] * x * m_

        return res % M


class PrimitiveRoot:
    @staticmethod
    def modul(a, n):
        phi = Euler.Modul(n)
        for i in range(2, phi):
            if pow(a, i, n) == 1:
                return False
        return True


class Logarithm:
    @staticmethod
    def modul(a, b, n):
        for k in range(n):
            if pow(a, k, n) == b:
                return k
        return None