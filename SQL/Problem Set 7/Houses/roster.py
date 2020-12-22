from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    print('Correct Usage: python roster.py house')
    exit(1)

house = argv[1]
db = SQL('sqlite:///students.db')

students = db.execute(
    'SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first',
    house
)

for student in students:
    birth = student['birth']
    first = student['first']
    middle = student['middle']
    last = student['last']

    name = []
    name.append(first)

    if middle is not None:
        name.append(middle)

    name.append(last)

    print(f"{' '.join(name)}, born {birth}")
