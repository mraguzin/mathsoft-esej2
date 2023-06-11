import sys
import subprocess
import numpy as np
import math
#from fractions import Fraction

targets1 = ["bit_test", "adaptive_test", "sqrt32_test"]
targets2 = ["sqrt_test", "sqrt2_test"]
TOL = 1e-6
errors = dict()
t = dict()
iteracija = 100000000
argument = 100000009

for mod in targets1:
    rez = subprocess.run(
                ["./" + mod, str(argument), str(iteracija)],
                text=True,
                capture_output=True)
    linija = rez.stdout
    dijelovi = linija.split()
    #t[mod] = float(''.join(filter(lambda x: str.isdigit(x) or x=='.', dijelovi[0])))
    t[mod] = float(dijelovi[0])

for mod in targets2:
    rez = subprocess.run(
                ["./" + mod, str(argument), str(iteracija)],
                text=True,
                capture_output=True)
    linija = rez.stdout
    dijelovi = linija.split()
    t[mod] = float(''.join(filter(lambda x: str.isdigit(x) or x=='.', dijelovi[0])))
    errors[mod] = abs(float(dijelovi[1]) - math.sqrt(argument))

with open("mjerenja.txt", "w") as f:
    print('VREMENA', file=f)
    for key,val in t.items():
        print(key + ':', val, file=f)
    print('APSOLUTNA GREŠKA', file=f)
    for key,val in errors.items():
        print(key + ':', val, file=f)

sys.exit(0)
