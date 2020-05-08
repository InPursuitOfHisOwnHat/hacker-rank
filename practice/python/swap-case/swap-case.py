def swap_case(s):
    ns = ''
    for c in s:
        if c.isupper():
            ns += c.lower()
        elif c.islower():
            ns += c.upper()
        else:
            ns += c
    return ns
