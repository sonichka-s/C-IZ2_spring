from random import randrange

rows = 5
cols = 10

f = open("input_matrix.txt", "w+")

for i in range(rows):
    matrix_array = []

    for j in range(cols):
        matrix_array.append(str(randrange(1000)))

    m_string = " ".join(matrix_array)

    if i != rows - 1:
        f.write(m_string + "\n")
    else:
        f.write(m_string)

f.close()


