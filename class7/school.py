class Student:

    def __init__(self, student_id, name, age, score):
        self.student_id = student_id
        self.name = name
        self.age = age
        self.score = score

    def print(self):
        print(f'Student id {self.student_id} name {self.name} age {self.age} score {self.score}')