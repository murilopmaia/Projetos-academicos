for i in range(1, 25+1):
    for j in range(1, 25+1):
        if i == j:
            continue
        print(f'd({i},{j}). ', end='')
    print()