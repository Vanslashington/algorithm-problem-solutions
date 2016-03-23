def sumOfMultiples(n):
    return sum(x for x in xrange(3, n, 3)) + \
           sum(x for x in xrange(5, n, 5) if x%3 != 0)

def test():
    s = sumOfMultiples
    assert s(10) == 23
    assert s(100) == 2318
    assert s(1) == 0
    assert s(10**8) > 0
    print "PASSED"

#test()
t = int(raw_input())
for n in (int(raw_input()) for i in xrange(t)):
    print sumOfMultiples(n)
