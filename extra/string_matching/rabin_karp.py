d = 256


def search(pattern, text):
    q = 193
    M = len(pattern)
    N = len(text)
    p = 0
    t = 0
    h = 1;
    for i in xrange(M - 1):
        h = (h * d) % q

    for i in xrange(M):
        p = (d * p + ord(pattern[i])) % q
        t = (d * t + ord(text[i])) % q
    
    i = 0
    while i < (N - M):
        if p == t:
            j = 0
            while j < M:
                if not text[i + j] == pattern[j]:
                    break
                j += 1
            if j == M :
                print "Pattern found at %d" % i
        if i < N - M:
            t = (d * (t - ord(text[i]) * h) + ord(text[i + M])) % q
            if t < 0:
                t = t + q
        i += 1


if __name__ == '__main__':
    print "******"
    text = "AABAACAADAABAAABAA"
    pattern = "AABA" 
    search(pattern, text)
    print "******"
    text = 'this is a test text'
    pattern = 'test'
    search(pattern, text)
