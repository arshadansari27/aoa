from Queue import PriorityQueue
import math

def print_board(board):
    row = len(board)
    for i in xrange(row):
        print "|", " ".join("%2d" % u for u in board[i]), "|"
    print "\n"

def get_alternative(board, x1, y1, x2, y2):
    n_board = [[u for u in v] for v in board]
    n_board[x1][y1], n_board[x2][y2] = n_board[x2][y2], n_board[x1][y1]
    return n_board

def get_possible_alterations(output, board):
    row = len(board)
    col = len(board[0])
    for i in xrange(row):
        for j in xrange(col):
            if board[i][j] == 0:
                x, y = i, j
                break
    alternatives = []
    if x is not 0:
        b = get_alternative(board, x - 1, y, x, y)
        d = get_position_difference(output, b)
        alternatives.append((d, b,))
    if y is not 0:
        b = get_alternative(board, x, y - 1, x, y)
        d = get_position_difference(output, b)
        alternatives.append((d, b,))
    if y is not col - 1:
        b = get_alternative(board, x, y + 1, x, y)
        d = get_position_difference(output, b)
        alternatives.append((d, b,))
    if x is not row - 1:
        b = get_alternative(board, x + 1, y, x, y)
        d = get_position_difference(output, b)
        alternatives.append((d, b,))
    return alternatives

def get_position_difference(output, board):
    positions = {}
    assert len(output) == len(board)
    row = len(output)
    col = len(output[0])
    for i in xrange(row):
        for j in xrange(col):
            positions[output[i][j]] = (i, j,)
    difference = []
    for i in xrange(row):
        for j in xrange(col):
            u, v = positions[board[i][j]]
            difference.append(math.sqrt(pow((u - i), 2) + pow((v - j),2)))
    return sum(difference)
            
def get_hash_set(board):
    lst = []
    
    row = len(board)
    col = len(board[0])
    for i in xrange(row):
        for j in xrange(col):
            lst.append(board[i][j])
    return "".join(str(i) for i in lst)


def solve(output, puzzle_board):
    pq = PriorityQueue()
    output_hash = get_hash_set(output)
    board_set = set([])
    board_set.add(get_hash_set(puzzle_board))
    d = get_position_difference(output, puzzle_board)
    pq.put((d, puzzle_board,))
    while not pq.empty():
        d, board = pq.get()
        if get_hash_set(board) == output_hash:
            print "Output is:"
            print_board(board)
            break

        alternatives = get_possible_alterations(output, board) 
        for a in alternatives:
            hash_set = get_hash_set(a[1])
            if hash_set in board_set:
                continue
            board_set.add(hash_set)
            pq.put(a)


if __name__ == '__main__':
    output = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 0]]
    puzzle_board = [[0, 12, 9, 13], [15, 11, 10, 14], [3, 7, 2, 5], [4, 8, 6, 1]]
    solve(output, puzzle_board)
