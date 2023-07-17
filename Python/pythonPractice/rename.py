import os

path = input("Enter absolute or relative path of the folder : ")
currentExt = input("Enter current extension of your file that you want to change : ")
newExt = input("Enter new extension : ")
folder = os.listdir(path)

for file in folder:
    if file.endswith(currentExt):
        os.rename(f"{path}/{file}", f"{path}/{file[:-len(currentExt)]}.{newExt}")
