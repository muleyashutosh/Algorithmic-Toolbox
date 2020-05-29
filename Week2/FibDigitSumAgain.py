def F(n):
	if n <= 1:
		return n
	p1 = 0
	p2 = 1
	c = 1
	for i in range(2, n):
		p1 = p2
		p2 = c
		c = (p1 + p2) % 10;
	return c


def findSumDigit(n):
    # Here 60 is the length of pisano period for F(n) % 10
    n = n % 60
    x = F(n+2)
    if x == 0:
        return 9
    return x - 1
 
m, n = map(int,input().split())

x = findSumDigit(m-1)
#print(x)
y = findSumDigit(n)
#print(y)
if(y < x):
    y += 10
print(abs(y - x))
