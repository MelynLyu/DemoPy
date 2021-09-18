import random
import statistics

fullCards = list(range(2, 11)) * 4
print(fullCards)

print("The total number of points available in the deck is {:d}.".format(sum(fullCards)))

def DeltaDeck(fullCards:list) -> tuple:
    random.shuffle(fullCards)
    partCards_1 = fullCards[:len(fullCards) // 2]
    partCards_2 = fullCards[len(fullCards) // 2:]
    
    return (partCards_1, partCards_2)

deckResult = DeltaDeck(fullCards)
print(len(deckResult))
print(deckResult[0])
print(deckResult[1])