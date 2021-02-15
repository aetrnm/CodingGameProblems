alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?"

width = int(input())
height = int(input())
textToPrint = input().upper()

asciiText = []

for i in range(height):
    row = input()
    asciiText.append(row)
    
for i in range(height):
    s = ""
    for j in textToPrint:
        try:
            posOfLetter = alphabet.index(j)
            s += asciiText[i][posOfLetter*width:posOfLetter*width+width]
        except ValueError:
            s += asciiText[i][len(asciiText[i])-width:len(asciiText[i])]
            
    print(s)
