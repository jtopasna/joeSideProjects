/*
 Name: Joseph Topasna
 
 This is a 'Poker Hand' analyzer program.
 
 This program reads five cards from the user, then analyzes the cards
 and prints out the category of hand that they represent.
 
 Poker hands are categorized according to the following labels: Straight flush, 
 four of a kind, full house, straight, flush, three of a kind, two pairs, pair, 
 high card.
 
 High Card == There are no matching cards, and the hand is not a straight
 Pair == Two of the cards are identical
 Two Pair == Two different pairs
 Three of a kind == Three matching cards
 Straight == 5 consecutive cards
 Full House	== A pair and three of a kind
 Four of a kind	== Four matching cards

 To simplify the program will ignore card suits, and face cards. The values
 that the user inputs will be integer values from 2 to 9.
 */


#include <iostream>

using namespace std;

const int INDEX_DISPLACEMENT = 2;
const int MAX_CARDS = 5;
const int MAX_VALUES = 8;
const int FOUR_INSTANCE = 4;
const int THREE_INSTANCE = 3;
const int PAIR_VALUE = 2;
const int TWO_PAIR = 2;







void initArray(int [], int);

void promptUser();
void readUserCards(int [], int);






bool  containsFourOfaKind(const int hand[]);
bool  containsPair(const int hand[]);
bool  containsThreeOfaKind(const int hand[]);
bool  containsFullHouse(const int hand[]);
bool  containsTwoPair(const int hand[]);
bool  containsStraight(const int hand[]);






int main() {
    
    int hand[MAX_VALUES];
    initArray(hand, MAX_VALUES);
    
    promptUser();
    readUserCards(hand, MAX_CARDS);
    
    if (containsFourOfaKind(hand)) {
        cout << "Four of a Kind! \n";
    } else if (containsFullHouse(hand)) {
        cout << "Full House! \n";
    } else if (containsStraight(hand)) {
        cout << "Straight! \n";
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a kind! \n";
    } else if (containsTwoPair(hand)) {
        cout << "Two Pair! \n";
    } else if (containsPair(hand)) {
        cout << "Pair! \n";
    } else {
        cout << "High Card! \n";
    }
}






/*
readUserCards(int cardArray[], int arraySize) takes in cardArray[] by reference
 along with the size of cardArray[]. The user will input a card value 2-9 for
 arraySize number of times.
 
 readUserCards() stores user inputed cards in cardArray[] by incrementing the value of elements
 which correspond to a card value.
 
 For example, if cardArray[0] == 1, then this means the user inputed '2' for one
 of their cards. If cardArray[0] == 2, then this means the user inputed '2' twice.
 If cardArray[1] == 3, then this means the user inputed '3' THREE TIMES. If
 cardArray[2] == 1, then this means the user inputed '4' ONE time. And so on.
 
 Pre: hand[] is initialized so each value == 0; user only given option of inputting
 values 2-9; INDEX_DISPLACEMENT is specific to 2 being the minimum value
 Post: cardArray[] (pass by reference) will represent the number of times a user
 inputed a particular value
*/
void readUserCards(int cardArray[], int arraySize) {
    
    int userInt;
    
    for(int count = 0; count < arraySize; count++) {
        cout << "Card " << count + 1 << ": ";
        cin >> userInt;
        cardArray[userInt - INDEX_DISPLACEMENT] = cardArray[userInt - INDEX_DISPLACEMENT] + 1;
    }
}






/*
 prompUser() simply reads out instructions for the user to enter cards for
 analysis to see what kind of hand it is.
 
 Pre: None
 Post: User is prompted to enter five numeric cards between 2-9.
 */
void promptUser() {
    cout << "Enter five numeric cards, no face cards. Use 2 - 9. \n";
}






/*
 initArray(int array[], int size) will initialize an array of any size such that
 all elements in the array contain a value of 0.
 
 Pre: static array[] has int size number of elements.
 Post: all elements in array[] will contain the value 0
 */
void initArray(int array[], int size) {

    for (int count = 0; count < size; count++){
        array[count] = 0;
    }
}






/*
 containsFourOfaKind() cycles through hand[] (pass by value) and checks for
 instances of FOUR_INSTANCE (4). Four of a kinds are indicated with an int value
 of FOUR_INSTANCE(4) (i.e. a value of 4 at hand[0] indicates that card value '2'
 was inputted FOUR_INSTANCE (4) times by the user.
 
 Pre: hand[] is not empty, holds 8 values, and each element holds value
 Post: returns true if the array hand[] contains 4 instances of any card;
 returns false if not
 */
bool  containsFourOfaKind(const int hand[]) {
    
    for (int count = 0; count < MAX_VALUES; count++) {
        if (hand[count] == FOUR_INSTANCE) {
            return true;
        }
    }
    return false;
}







/*
 containsPair() cycles through hand[] (pass by value) and checks for
 instances of PAIR_VALUE (2). Pairs are indicated with an int value of PAIR_VALUE
 (i.e. a value of PAIR_VALUE at hand[0] indicates that card value '2' was
 inputted 2 times by the user.
 
 Pre: hand[] is not empty, holds 8 values, and each element holds value
 Post: returns true if the array hand[] contains PAIR_VALUE (2) instances of any
 card; returns false if not
 */
bool  containsPair(const int hand[]) {
    
    for (int count = 0; count < MAX_VALUES; count++) {
        if (hand[count] == PAIR_VALUE) {
            return true;
        }
    }
    return false;
}






/*
 containsThreeOfaKind() cycles through hand[] (pass by value) and checks for
 instances of 3. Three of a kinds are indicated with an int value of 3 (i.e. a
 value of 3 at hand[0] indicates that card value '2' was inputted 3 times by the
 user.
 
 Pre: hand[] is not empty, holds 8 values, and each element holds value
 Post: returns true if the array hand[] contains 3 instances of any card;
 returns false if not
 */
bool  containsThreeOfaKind(const int hand[]) {
    
    for (int count = 0; count < MAX_VALUES; count++) {
        if (hand[count] == THREE_INSTANCE) {
            return true;
        }
    }
    return false;
}






/*
containsFullHouse() cycles through hand[] (pass by value) and checks if it has a
 pair and a three of a kind. Pairs in hand[] are indicated with a value of 2 and
 threes of a kind are indicated with a value of 3. containsFullHouse() completes
 this check by sending containsThreeOfaKind() and containsPair() hand[] via pass
 by value.
 
 containsFullHouse() will return false if it does not contain both at least one
 three of a kind and one pair.
 
 Pre: hand[] is not empty, holds 8 values, and each element holds value
 Post: returns true if hand[] contains both a three of a kind and a pair
*/
bool  containsFullHouse(const int hand[]) {
    
    if (containsThreeOfaKind(hand) && containsPair(hand)) {
        return true;
    }
    return false;
}






/*
 containsTwoPair() cycles through hand[] (pass by value) and counts the number
 of pairs in the hand[] array. Pairs in hand[] are indicated with a value of 2
 (i.e. The value at that index (e.g. 0) occured twice indicates that card two
 was inputed twice by user)
 
 
 Pre: hand[] is not empty, holds 8 values, and each element holds value
 Post: returns true if the int pairCount is incremented twice or more;
 returns false if not
 */
bool  containsTwoPair(const int hand[]) {
    
    int pairCount = 0;
    
    for (int count = 0; count < MAX_VALUES; count++) {
        if (hand[count] == PAIR_VALUE) {
            pairCount++;
        }
    }
    if (pairCount >= TWO_PAIR) {
        return true;
    }
    return false;
}






/*
containsStraight() takes an array hand[] by value and goes through each element
 to check if each element is equal to the one after it. This function will
 return true if it finds four neighbors and false if not.
 
 Pre: hand[] is not empty, holds 8 values, and each element holds value
 Post: returns true if it finds 4 neighbors; returns false if not
 */
bool  containsStraight(const int hand[]) {
    
    int neighborCount = 0;
    
    for (int count = 0; count < MAX_VALUES - 1; count++) {
        if ((hand[count] == 1) && (hand[count] == hand[count+1])) neighborCount++;
    }
    if (neighborCount == FOUR_INSTANCE) {
        return true;
    }
    return false;
}






/*
 
 SAMPLE OUTPUT
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 3
 Card 4: 8
 Card 5: 7
 High Card!

 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 3
 Card 4: 5
 Card 5: 7
 Pair!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 2
 Card 4: 5
 Card 5: 3
 Two Pair!

 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 5
 Card 3: 3
 Card 4: 5
 Card 5: 7
 Three of a kind!

 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 3
 Card 2: 5
 Card 3: 6
 Card 4: 4
 Card 5: 7
 Straight!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 7
 Card 3: 5
 Card 4: 7
 Card 5: 7
 Full House!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 5
 Card 3: 5
 Card 4: 5
 Card 5: 5
 Four of a Kind!
 
 */
