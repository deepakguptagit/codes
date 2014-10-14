t = int(raw_input(""))

while t!=0:
	n = int(raw_input(""))
	if n==1:
		print 1
	elif n%2==0:
		print (n/2)*(n/2)
	else:
		print (n/2)*((n/2)+1)	
	t = t-1