list1 = [["Ram",4] ,["shyam",6],["arun",5], ["subodh",7],["popi",9]]
#We can write like this if there is list
for item, style in list1:
	print(item, style)

#We can write like this if there is dictionery	
dict1 = dict(list1)
for item , style in dict1.items():
	print(item, style)
#only for key we can write like this in both case 
for item in dict1:
	print(item)
	
#quick quiz
list2 = [2,57,5,7,9,8,42]
for item in list2:
	if str(item).isnumeric and item > 6:
		print(item)