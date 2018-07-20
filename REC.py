def power(n, m):
	c=[[1, 2], [3, 4]]
	while n>0:
		if n%2==1:
			c[0][0]=(res[0][0]*transform[0][0])%m + (res[0][1]*transform[1][0])%m
			c[0][1]=(res[0][0]*transform[0][1])%m + (res[0][1]*transform[1][1])%m
			c[1][0]=(res[1][0]*transform[0][0])%m + (res[1][1]*transform[1][0])%m
			c[1][1]=(res[1][0]*transform[0][1])%m + (res[1][1]*transform[1][1])%m
			for i in range(2):
				for j in range(2):
					res[i][j]=c[i][j]
		n=n/2
		c[0][0]=(transform[0][0]*transform[0][0])%m + (transform[0][1]*transform[1][0])%m
		c[0][1]=(transform[0][0]*transform[0][1])%m + (transform[0][1]*transform[1][1])%m
		c[1][0]=(transform[1][0]*transform[0][0])%m + (transform[1][1]*transform[1][0])%m
		c[1][1]=(transform[1][0]*transform[0][1])%m + (transform[1][1]*transform[1][1])%m
		for i in range(2):
			for j in range(2):
				transform[i][j]=c[i][j]
 
T=int(input())
for _ in range(T):
	global transform
	global res
	transform=[]
	res=[]
	a, b, n, m = raw_input().split()
	a=long(a)
	b=long(b)
	n=long(n)
	m=int(m)
	a=int(a%m)
	b=int(b%m)
	if n==0:
		print(1%m)
	else:
		transform.append([a, 1])
		transform.append([0, 1])
		res.append([1, 0])
		res.append([0, 1])
		power(n, m)
		# print(res)
		print((res[0][0]+((res[0][1]*b)%m))%m)
