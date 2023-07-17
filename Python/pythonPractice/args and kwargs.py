def Example(*list, **dict):
	print("The names are:")
	for item in list:
		print(item)
	for name, relation in dict.items():
		print(f"{name} is my {relation}")
		
list = ["Samsad", "Arun", "Roshan", "Umashankar", "Vansh"]
dict = {"Smasad":"dost", "Arun":"enemy","Roshan":"friend", "Umashankar":"dost 2", "Vansh":"dost 3" }
Example(*list, **dict)