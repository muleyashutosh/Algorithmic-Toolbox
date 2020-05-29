def F(n):
	if n <= 1:
		return n
	p1 = 0
	p2 = 1
	c = 1
	for i in range(2, n):
		p1 = p2
		p2 = c
		c = p1 + p2;
	return c
	
	
def get_pisano_length(m):
	n = 2
	p1 = F(n) % m
	n += 1
	p2 = F(n) % m
	n += 1	
	l = 2
	for i in range(2, m*4 + 1):
		if (p1 == 0) and (p2 == 1):
			return l
		p1 = p2
		p2 = F(n) % m
		n += 1
		l += 1
	
	return -1
		
def Fmodm(n, m):
	n = n % get_pisano_length(m)
	#print(n)
	#print( n % m)
	return F(n) % m
		 
n, m = map(int,input().split())

print(Fmodm(n, m))
