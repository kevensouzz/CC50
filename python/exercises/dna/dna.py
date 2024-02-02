from sys import argv
import csv


def dna_identification(strs, dna):
    str_info = strs[0][1:]
    str_count = [dna.count(word) for word in str_info]
    str_values = strs[1:]
    str_names = []
    for row in str_values:
        str_names.append(row[0])
        del row[0]

    for index, sublist in enumerate(str_values):
        if list(map(int, sublist)) == str_count:
            response = str_names[index]
            break
        else:
            response = "No Match!"

    print(response)


if len(argv) != 3:
    print("\nUSAGE: dna.py data.csv sequence.txt\n")
else:
    database_content = []

    with open(argv[1], "r") as database_file:
        database_reader = csv.reader(database_file)

        for row in database_reader:
            database_content.append(row)

    with open(argv[2], "r") as sequence_file:
        sequence_content = sequence_file.read()

    dna_identification(database_content, sequence_content)
