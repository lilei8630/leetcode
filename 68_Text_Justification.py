s = [""]
l = 2
res = []
line=""
i=0
while i < len(s):
	if(len(line)+len(s[i])<=l):
		line = line + s[i]
		line = line +" "
		if(i==(len(s)-1)):
			len1 = len(line.replace(' ',''))
			len2 = len(line.strip())
			remain = l - len1
			temp = line.strip().split(" ")
			num_words = len(temp)
			num_slot = num_words-1
			more = remain if num_slot==0 else remain % num_slot
			each = 0 if num_slot==0 else remain / num_slot
			if(len2<l):
				res.append(line+" "*(l-len2))
			else:
				newline = ""
				for j in range(0,num_words):
					newline += temp[j]
					if(j==0):
						newline +=' '*(each+more)
					else:
						newline +=' '*each
				res.append(newline[0:l])
	else:
		len1 = len(line.replace(' ',''))
		remain = l - len1
		temp = line.strip().split(" ")
		num_words = len(temp)
		num_slot = num_words-1
		more = remain if num_slot==0 else remain % num_slot
		each = 0 if num_slot==0 else remain / num_slot
		newline = ""
		for j in range(0,num_words):
			newline += temp[j]
			
			if(j==0):
				newline +=' '*(each+more)
			else:
				newline +=' '*each
		res.append(newline[0:l])
		line=""
		i = i - 1
	i = i+1
	
print res
			
	
