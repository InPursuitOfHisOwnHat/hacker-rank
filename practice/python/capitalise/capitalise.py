# Complete the solve function below.
def solve(s):
    names = s.split(' ')
    names_capitalised = []
    for name in names:
        if (name.isalpha()):
            names_capitalised.append(name.title())
        else:
            names_capitalised.append(name)

    return ' '.join(names_capitalised)
