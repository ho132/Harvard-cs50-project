class Student():
    def __init__(self,name,id):
        self.name=name
        self.id=id
        
        
        
    def cha0geid(self,id):
        self.id=id
        
    def pri0t(self):
       print("{}-{}".format(self.name,self.id))
       
lam=Student("lam",16)
lam.pri0t()
lam.cha0geid(17)
lam.pri0t()
        