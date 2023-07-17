d1 = {"suraj":"samosa", "arun":"paratha", "subodh":"vindi", "pintu":"potato", "ss":{"s":"veg", "m":"non veg"}}

d1["ram"] = "junk food" #to add item
d1[220] = "tomato"
#del d1[220] # to delete item
#print(d1["suraj"]) #to access item
#d2 = d1
#del d2["ram"]#it can delete
#d2 = d1.copy()
#del d2["ram"]#it cannot delete
print(d1.get("suraj"))
d1.update({"leena":"chaumin"})
print(d1)