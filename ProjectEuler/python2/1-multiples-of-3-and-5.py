def sumOfMultiples(n):
    return sum(x for x in xrange(n) if x%3 == 0 or x%5 == 0)

def test():
    s = sumOfMultiples
    assert s(10) == 23
    assert s(100) == 2318
    assert s(1) == 0
    print "passed"

#test()
t = int(raw_input())
for n in (int(raw_input()) for i in xrange(t)):
    print sumOfMultiples(n)
