def search(pattern, text):
    M = len(pattern)
    N = len(text)
    for i in xrange(N - M):
        for j in xrange(M):
            if text[i + j] != pattern[j]:
                break
        if j is M - 1:
            print "Patter found at index:", i

if __name__ == '__main__':
    text = "AABAACAADAABAAABAA"
    pattern = "AABA" 
    search(pattern, text)
    text = 'this is a test text'
    pattern = 'test'
    search(pattern, text)
