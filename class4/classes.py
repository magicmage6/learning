class Car:
   x = 0
   y = 0
   vx = 0
   vy = 0
   name = ''

   def print_status(self):
       print('name %s x %f y %f speed x %f speed y %f' % (self.name, self.x, self.y, self.vx, self.vy))
   
   def speed_up_x(self):
       self.vx = self.vx + 1

   def speed_up_y(self):
       self.vy = self.vy + 1
    
   def drive(self, driving_time):
       self.x = self.x + self.vx * driving_time
       self.y = self.y + self.vy * driving_time

car1 = Car()
car1.name = 'my first car'
car1.print_status()
car1.speed_up_x()
car1.speed_up_y()
car1.print_status()
car1.drive(20)
car1.print_status()
car2 = Car()
car2.name = 'my second car'
car2.vx = 2
car2.vy = 3
car2.drive(10)
car2.print_status()