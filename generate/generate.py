from copy import copy, deepcopy
import numpy as np
import csv
import random

matrix1 = []
matrix2 = []

with open('input.csv', 'w', newline='') as csvfile:
    inputWriter = csv.writer(csvfile, delimiter=',',quotechar='\'', quoting=csv.QUOTE_MINIMAL)
    for i in range(0,1024):
        lineArray = []
        for j in range(0,1024):
            randomValue = random.randint(0,32767)
            lineArray.append(randomValue)
        inputWriter.writerow(lineArray)
        matrix1.append(lineArray)

    inputWriter.writerow([])

    for i in range(0,1024):
        lineArray = []
        for j in range(0,1024):
            randomValue = random.randint(0,32767)
            lineArray.append(randomValue)
        inputWriter.writerow(lineArray)
        matrix2.append(lineArray)

result = np.dot(matrix1,matrix2)

with open('output.csv', 'w', newline='') as csvfile:
    inputWriter = csv.writer(csvfile, delimiter=',',quotechar='\'', quoting=csv.QUOTE_MINIMAL)
    inputWriter.writerows(result)
