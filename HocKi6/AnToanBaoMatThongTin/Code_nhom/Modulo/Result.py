from Code import Modulo, ExtendEuclid, Euler, ModulChina, PrimitiveRoot, Logarithm

with open('input_mod.txt', 'r') as file:
    lines = file.readlines()

results = []

# Modulo
a, m, n = map(int, lines[0].split())
result_modulo = Modulo.modul(a, m, n)
results.append("Modulo: " + str(result_modulo))



# ExtendEuclid
a, b = map(int, lines[1].split())
result_extend_euclid = ExtendEuclid.modul(a, b)
results.append("ExtendEuclid: " + str(result_extend_euclid))

# Euler
n = int(lines[2])
result_euler = Euler.Modul(n)
results.append("Euler: " + str(result_euler))

# ModulChina
m = list(map(int, lines[3].split()))
a = list(map(int, lines[4].split()))
result_modul_china = ModulChina.Modul(m, a)
results.append("ModulChina: " + str(result_modul_china))

# PrimitiveRoot
a, n = map(int, lines[5].split())
result_primitive_root = PrimitiveRoot.modul(a, n)
results.append("PrimitiveRoot: " + str(result_primitive_root))

# Logarithm
a, b, n = map(int, lines[6].split())
result_logarithm = Logarithm.modul(a, b, n)
results.append("Logarithm: " + str(result_logarithm))

# Modulo
a, m, n = map(int, lines[7].split())
result_modulo = Modulo.modul(a, m, n)
results.append("Modulo: " + str(result_modulo))
with open('output_mod.txt', 'w') as file:
    file.write('\n'.join(results))
    # Modulo
    a, m, n = map(int, lines[8].split())
    result_modulo = Modulo.modul(a, m, n)
    results.append("China: " + str(result_modulo))
    with open('output_mod.txt', 'w') as file:
        file.write('\n'.join(results))