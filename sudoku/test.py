import os


directory = 'boards'
for filename in os.listdir(directory):
    if filename.endswith(".txt"):
        print(os.path.join(directory, filename))
    else:
        continue