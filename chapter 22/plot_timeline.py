import matplotlib.pyplot as plt

def read_pairs(filename):
    pairs = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:  # Ensure the line is not empty
                parts = line.split(',')
                if len(parts) == 2:
                    name, year = parts[0].strip(), parts[1].strip()
                    try:
                        year = int(year)
                        pairs.append((name, year))
                    except ValueError:
                        print(f"Skipping line with non-integer year: {line}")
                else:
                    print(f"Skipping improperly formatted line: {line}")
    return pairs

def plot_timeline(pairs):
    pairs.sort(key=lambda x: x[1])
    names = [pair[0] for pair in pairs]
    years = [pair[1] for pair in pairs]

    plt.figure(figsize=(10, 5))
    plt.scatter(years, names)
    plt.title('Programming Languages Timeline')
    plt.xlabel('Year')
    plt.ylabel('Programming Language')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    input_file = 'input.txt'
    pairs = read_pairs(input_file)
    if pairs:
        plot_timeline(pairs)
    else:
        print("No valid (name, year) pairs found.")
