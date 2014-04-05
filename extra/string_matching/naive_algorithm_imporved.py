def search(pattern, text):
    M = len(pattern)
    N = len(text)
    i = 0
    while i <= (N - M):
        j = 0
        while j < M:
            if text[i + j] != pattern[j]:
                break
            j += 1
        if j is M:
            print "Patter found at index:", i
            i = i + M
        elif j is 0:
            i += 1
        else:
            i += j

if __name__ == '__main__':
    text = "AABAACAADAABAAABAA"
    pattern = "AABA" 
    search(pattern, text)
    print "************"
    text = 'this is a test text'
    pattern = 'test'
    search(pattern, text)
    print "************"
    text = 'ABCEABCDABCEABCD'
    pattern = 'ABCD'
    search(pattern, text)
    print "************"
