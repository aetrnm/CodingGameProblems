sum = -1

ansWord = ''

oneP = 'e a i o n r t l s u'
twoP = 'd g'
threeP = 'b c m p'
fourP = 'f h v w y'
fiveP = 'k'
eightP = 'j x'
tenP = 'q z'

dictionary = []

#input
n = int(input())
for i in range(n):
    dictionary.append(input())
allowedLetters = input()
#

for curWord in dictionary:
    localSum = 0
    leftLetters = allowedLetters

    wordInDict = True
    for letter in curWord:
        if letter not in allowedLetters:
            wordInDict = False


    for letter in curWord:
        if letter not in leftLetters:
            localSum = -999
            break
        else:
            leftLetters = leftLetters.replace(letter, '')
            if letter in oneP:
                localSum += 1
            if letter in twoP:
                localSum += 2
            if letter in threeP:
                localSum += 3
            if letter in fourP:
                localSum += 4
            if letter in fiveP:
                localSum += 5
            if letter in eightP:
                localSum += 8
            if letter in tenP:
                localSum += 10

    if localSum > sum and wordInDict:
        sum = localSum
        ansWord = curWord

print(ansWord)
