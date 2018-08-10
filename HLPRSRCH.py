    total = int(input())
    mat = int(input())
    unmat = total - mat
    per = int(input())
    n = int(input())
    z = int(input())
    time = int(z/per)
     
    for _ in range(time):
    	newunmat = n*mat
    	mat = mat + unmat
    	unmat = newunmat
     
    print(mat+unmat) 
