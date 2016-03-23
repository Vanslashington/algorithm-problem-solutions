def closedSum(n):
    return (n * (n + 1)) / 2

def sumOfMultiples(n):
    m = n-1
    return 3*closedSum(m/3) + 5*closedSum(m/5) - 15*closedSum(m/15)
    # 3 6 9 12 15 18
    # 1 2 3 4  5  6

def test():
    assert closedSum(5) == 15
    s = sumOfMultiples
    assert s(10) == 23
    assert s(100) == 2318
    assert s(1) == 0
    assert s(10**9) > 0
    print "PASSED"
#test()

t = int(raw_input())
for n in (int(raw_input()) for i in xrange(t)):
    print sumOfMultiples(n)
