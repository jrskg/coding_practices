list = ["Ram", "Shyam", "Hari","Gopal"]
"""
for item in list:
	print(item,"and",end = " ")
print("other remaining players")
"""
a = " and ".join(list)
print(a,"and other remaining players")