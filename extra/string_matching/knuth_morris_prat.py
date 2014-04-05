def search(pattern, text):
    i, j = 0, 0
    ptrn_length = len(pattern)
    txt_length = len(text)

    b = pre_process(pattern)

    while i < txt_length:
        while j >= 0 and text[i] != pattern[j]:
            j = b[j]
        i += 1
        j += 1

        if j == ptrn_length:
            print "Found substring at index:", i - ptrn_length
            j = b[j]

def pre_process(pattern):
    i = 0
    j = -1
    ptrn_length = len(pattern)
    b = [-1 for k in xrange(ptrn_length + 1)]
    b[i] = j
    while i < ptrn_length:
        while j >= 0 and pattern[i] != pattern[j]:
            j = b[j]
        i += 1
        j += 1
        b[i] = j
    return b

if __name__ == '__main__':
    text = "abcabdabcabdabcabdabdabc"
    pattern = "abcabdabc"
    print search(pattern, text)
