from csv import reader, DictReader
from sys import argv

if len(argv) < 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()

with open(argv[2]) as dfile:
    dr = reader(dfile)
    for row in dr:
        dl = row

d = dl[0]
sequences = {}

with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        ds = row
        ds.pop(0)
        break

for item in ds:
    sequences[item] = 1

for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(d)):
        while temp > 0:
            temp -= 1
            continue

        if d[i: i + l] == key:
            while d[i - l: i] == d[i: i + l]:
                temp += 1
                i += l

            if temp > tempMax:
                tempMax = temp

    sequences[key] += tempMax

with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        for d in sequences:
            if sequences[d] == int(person[d]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")
