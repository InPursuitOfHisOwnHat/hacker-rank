if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    # Remove from list then sort
    max_score = max(arr)
    arr_no_max = list(filter(lambda x : x != max_score, arr))
    print(max(arr_no_max))
