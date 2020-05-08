import re

def fun(s):
    email_regex = r'^[a-zA-Z0-9\-\_]{1,}@[a-zA-Z0-9]*\.[a-zA-Z0-9]{1,3}$'
    re.compile(email_regex)
    if re.search(email_regex, s) is None:
        return False
    else:
        return True

def filter_mail(emails):
    return list(filter(fun, emails))

if __name__ == '__main__':
    n = int(input())
    emails = []
    for _ in range(n):
        emails.append(input())

filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(filtered_emails)