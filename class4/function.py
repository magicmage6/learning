def my_print_func(message):
    print(message)

def add_func(num1, num2):
    return num1 + num2

my_print_func('hello2')
sum = add_func(10, 20)
my_print_func(sum)

def print_list(list1):
    for num in list1:
        print(num)

print_list(['a', 'b', 'c'])