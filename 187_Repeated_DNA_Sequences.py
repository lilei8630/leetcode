map = {}
res = []
s = "AAAAAAAAAAAA"
for index in range(10,len(s)+1):
	elem = s[index-10:index]
	if(map.has_key(elem)):
		if(map[elem]==1):
			res.append(elem)
			map[elem]=map[elem]+1
		else:
			map[elem]=map[elem]+1
	else:
		map[elem]=1
print res
