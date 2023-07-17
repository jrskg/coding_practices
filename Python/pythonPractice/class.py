class Employee:
    def __init__(self, id, name, role, language):
        self.id = id
        self.name = name
        self.role = role
        self.language = language
    def getInfo(self):
        print(f"{self.name} is a {self.role} whose id is {self.id} and uses {self.language}.")

def greet(fx):
    def mfx(*args, **kwargs):
        print("Good morning..")
        fx(*args, **kwargs)
        print("Thanks for using")
    return mfx

@greet
def add(a, b):
    print(a+b)

if __name__ == "__main__":
    e1 = Employee("001", "Suraj Gupta", "Mern-Developer", "JavaScript")
    # e1.getInfo()
    # print(e1)
    add(1, 2)