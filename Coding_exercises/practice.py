'return the inverse of a string'
def reverse(string):
    str= list(string)
    array = []
    for i in range(len(str)-1,-1,-1):
        array.append(str[i])
    sol = ''.join(array)
    return (sol)

'compute the factorial of n'
def factorial(n):
    solution = 1
    if n == 0:
        solution = 1
        print (solution)
    for i in range (0,n):
        solution = solution*(n-i)
    print (solution)

'return the longest word in a sentence'
def longest_word(sentence):
    st = sentence.split()
    max = 0
    for word in st:
        if len(word) > max:
             max = len(word)
    print (word)

'find the total sum of an array'
def sum_nums(num):
    suma = 0
    for i in range(0,num+1):
        suma = suma +i
    print(suma)

'create a timer converter'
def time_conversion(minutes):
    min = int(minutes/60)
    secs = minutes%60
    print (str(min) + ":"  + str(secs))

'count all vowels given a string'
def count_vowels(string):
    vowels = ["a","e","i","o","u"]
    st = list(string)
    array = []
    for i in st:
        if i in vowels:
            array.append(i)
    print(len(array))

"determine wether it's palindrome or not"
def palindrome(string):
    stri = list(string)
    arr =[]
    for i in range(len(stri)-1,-1,-1):
        arr.append(stri[i])
    res = ''.join(arr)
    if string == res:
        print("palindrome")
    else:
        print("not palindrome")

"determine wether z if within the next 3 letters after a"
def nearby_az(string):
    str= list(string)
    if "a" in str and "z" in str:
        if str.index("z") in range(str.index("a"),str.index("a")+4):
            print(True)
        else:
            print(False)
    else:
        print(False)

'given an array, find 2 numbers that add to zero'
def two_sum(nums):
    position = []
    for index in range(0,len(nums)):
        position.append(index)
    for i in nums:
        if (0-i) in nums:
            print (position[i],position[0-i])
            break
        else:
            print("nil")

'determine wether a number is power of 2'
def is_power_of_two(num):
    if num == 1 or num == 2:
        return True
    else:
        while True:
            new = num / 2
            if new == 1:
                return True
            if new % 2 != 0 or new == 0:
                return False
            if new % 2 == 0:
                num = new
                continue

'find the 3rd greatest value in an array'
def thrid_greatest(nums):
    for i in range (0,2):
        nums.remove(max(nums))
    print(max(nums))

'find the most common letter in a string'
def most_common_letter(string):
    array =[]
    frequency = []
    str =list(string)
    for i in str:
        if i not in array:
            array.append(i)
    for i in array:
            frequency.append(str.count(i))
    return array[frequency.index(max(frequency))],max(frequency)

'capitalize the first letter of every word in a string'
def capatalize_words(string):
    str = string.split()
    solution = []
    for word in str:
        letters = list(word)
        letters[0] = letters[0].upper()
        sol = ''.join(letters)
        solution.append(sol)
    res = ' '.join(solution)
    return res

'given an array of positions, arrange the string according to order of position'
def scramble_string(string,positions):
    solution = []
    letters = list(string)
    for i in range(0,len(positions)):
        solution.append(letters[positions[i]])
        result = ''.join(solution)
    return result

'determine wether a number is prime or not'
def prime(number):
    factors = []
    for i in range(1,number+1):
        if number% i == 0:
            factors.append(i)
    if len(factors) == 2:
        return True
    return False

'determine the nth prime number'
def nth_prime(n):
    primes = []
    i = 2
    while len(primes) < n:
        if prime(i) == True:
            primes.append(i)
        i=i+1
    return max(primes)

'find the greatest common factor'
def greatest_common_factor(number1, number2):
    mininmum = min(number1,number2)
    common_factors = []
    for i in range(1,mininmum+1):
        if number1% i == 0 and number2%i == 0:
            common_factors.append(i)
    return max(common_factors)
