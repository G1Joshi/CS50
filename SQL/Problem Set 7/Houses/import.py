from sys import argv, exit
import csv
from cs50 import SQL

db = SQL('sqlite:///students.db')

if len(argv) != 2:
    print('Correct Usage: python import.py characters.csv')
    exit(1)

with open(argv[1], 'r') as students:

    reader = csv.DictReader(students)

    for row in reader:
        name = row['name'].split()
        first_name = name[0]
        
        if len(name) == 3:
            middle_name = name[1]
            last_name = name[2]
        else:
            middle_name = None
            last_name = name[1]

        db.execute(
            'INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)',
            first_name,
            middle_name,
            last_name,
            row['house'],
            row['birth'],
        )
