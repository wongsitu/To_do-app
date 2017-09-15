'remove all vowels in a string'
def disvowel (string):
    vowels = ["a","e","i","o","u"]
    letters = list(string)
    array = []
    print (letters)
    for i in letters:
        if i not in vowels:
            array.append(i)
    word = ''.join(array)
    print(word)

disvowel("foobars")

'determine wether there are 3 consecutive numbers that sum 7'

numbers = [0,-2,1,8]

def lucky_sevens(numbers):
    array=[]
    for i in numbers:
            array.append(i)
    for j in range (0, len(array)-2):
        if (array[j]+array[j+1]+array[j+2]==7):
            print(array[j])
            print(array[j+1])
            print(array[j+2])

lucky_sevens(numbers)

'given an array, determine the sum of all odd elements'

number=[1,2,3,4,5]

def oddball_sum(numbers):
    for i in numbers:
        if (i%2 ==0):
            numbers.remove(i)
    print(sum(numbers))

oddball_sum(number)
