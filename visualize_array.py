import matplotlib.pyplot as plt
import csv

# Read data from CSV file
insertions = []
used = []
size = []

with open('array_data.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)  # Skip the header
    for row in reader:
        insertions.append(int(row[0]))
        used.append(int(row[1]))
        size.append(int(row[2]))

# Plotting the data
plt.figure(figsize=(10, 6))

# Plot for array usage
plt.plot(insertions, used, label='Used', marker='o')
plt.plot(insertions, size, label='Size', marker='x')

plt.xlabel('Insertions')
plt.ylabel('Array Size / Used')
plt.title('Dynamic Array Usage and Size Over Time')
plt.legend()
plt.grid(True)
plt.show()
