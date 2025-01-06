import random

# 카드 덱 생성 함수
def makeCardDeck():
    shape = ['Spade', 'Club', 'Diamond', 'Heart']
    number = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
    cardDeck = {}

    for s in shape:
        for n in number:
            key = f"{s[0]}{n}"
            value = f"{s}{n}"
            cardDeck[key] = value

    return cardDeck

# 카드 배분 함수
def dealing(name, cardDeck):
    assigned_cards = []
    for _ in range(4):
        card = random.choice(list(cardDeck.keys()))
        assigned_cards.append(card)
        del cardDeck[card]
    return name, assigned_cards

# 카드 확인 함수
def checkCard(cardDeck, perCard):
    all_keys = [card for _, cards in perCard for card in cards]
    for key in all_keys:
        if key in cardDeck:
            print("Error Deck")
            return
    print("Your card good!", [name for name, _ in perCard])

# 메인 프로그램
def main():
    nameList = []
    perCard = []

    numPeople = int(input("Enter number of people: "))
    for _ in range(numPeople):
        nameList.append(input("Enter name: "))

    cardDeck = makeCardDeck()

    for name in nameList:
        perCard.append(dealing(name, cardDeck))

    print("Done dealing")

    print("Checking card deck")
    checkCard(cardDeck, perCard)

    perCard = dict(perCard)
    for key in perCard:
        print(key, perCard[key])

if __name__ == "__main__":
    main()
