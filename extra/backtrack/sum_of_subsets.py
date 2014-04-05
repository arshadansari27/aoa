import random

def recursive_solution(subset, considered, remaining_sum):
    if len(subset) == 0:
        return False
    if remaining_sum < 0:
        return False
    elif remaining_sum == 0:
        return considered
    else:
        for i in xrange(len(subset) - 1):
            value = recursive_solution(subset[i + 1:], considered + [subset[i]], remaining_sum - subset[i])
            if value is not False:
                return value
        return False


def sum_of_subsets(values, total):
    #Remove duplicates and sort the values
    values = sorted(list(set(values)))
    for i in xrange(len(values) - 1):
        value = recursive_solution(values[i + 1:], [values[i]], total - values[i])
        if value:
            print value 

if __name__ == '__main__':
    values = [random.randint(1, 100) for i in xrange(11)]
    sum_of_subsets(values, 200)
