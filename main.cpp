// Author: Ellis Sentoso
// Email: esentoso@go.pasadena.edu
// Assignment: Programming Project #9, Chapter 7, Poker Hands Reader
// Description: Calculate the character frequency in a string and store the characters
// in a character array for letters, and occurence counts in the freq array
// Last Changed: May 15, 2019
#include <iostream>
#include <string>
/*----------------------------------------------------------------------------------------------------*/
void check_hands(int hands[], int suits[]);
// Precondition: 5 cards hand stored in the int array and char array for the suits of 5 cards
// Postconditiion: return cout statements of what the result of the hands is
/*----------------------------------------------------------------------------------------------------*/
void deal(int hands[], int suits[]);
// Precondition: 5 cards hand stored in the int array and char array for the suits of 5 cards
// Postconditiion: 5 dealt cards
/*----------------------------------------------------------------------------------------------------*/
int high(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: return the value of the high hand
/*----------------------------------------------------------------------------------------------------*/
bool one(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: Decides it's one pair
/*----------------------------------------------------------------------------------------------------*/
bool flush(int suits[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: Decides it's a flush
/*----------------------------------------------------------------------------------------------------*/
bool two(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion:  Decides it's 2 pairs
/*----------------------------------------------------------------------------------------------------*/
bool triple(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: Decides it's 3 of a kind
/*----------------------------------------------------------------------------------------------------*/
bool four(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: Deciders it's 4 of a kind
/*----------------------------------------------------------------------------------------------------*/
bool straight(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: Decides it's a straight
/*----------------------------------------------------------------------------------------------------*/
bool full(int hands[]);
// Precondition: 5 cards hand stored in the array
// Postconditiion: Decides it's a full house
/*----------------------------------------------------------------------------------------------------*/
void input_card_from_user(int hands[], int suits[]);
// Precondition: 5 cards hand stored in the array. Allows the user to input their own 5 cards
// Postconditiion: Values of 5 cards provided by the user
/*----------------------------------------------------------------------------------------------------*/

const int CARD_LIMIT = 5; // Each player can only have 5 cards for this Poker game


using namespace std;

int main()
{
    srand(time(0));
    
    int hands[CARD_LIMIT];
    //int test[CARD_LIMIT] = {1,2,5,8,3};
    int suits[CARD_LIMIT];
    char play_again;
    int choice = 0;
    
    do {
        cout<<"Press [1] for Dealer to deal cards"<<endl;
        cout<<"Press [2] for Player to input their cards"<<endl;
        cin>>choice;
        
        switch (choice) {
                
            case 1:
                deal(hands, suits);
                check_hands(hands,suits);
                break;
            case 2:
                input_card_from_user(hands, suits);
                check_hands(hands,suits);
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
        
        
        cout<<"Would you like a new hand?"<<endl;
        cin>>play_again;
    } while (play_again == 'Y' || play_again == 'y');
    
    return 0;
}

void input_card_from_user(int hands[], int suits[]) {
    cout<<"Enter all hands from (1-10 for numerical cards)"<<endl
        <<"Example: 10 then press enter "<<endl;
    cout<<"1 then press enter. This means 10 of Spades"<<endl
        <<"Repeat this till you have 5 cards "<<endl;
    cout<<"Press "<<endl
    <<"[11] for Jack "<<endl
    <<"[12] for Queen "<<endl
    <<"[13] for King"<<endl
    <<"For Suits"<<endl
     <<"Press"<<endl
    <<"[1] for Spades "<<endl
    <<"[2] for Hearts: "<<endl
    <<"[3] for Clubs "<<endl
    <<"[4] for Diamonds "<<endl;
    
    for (int i = 0; i < CARD_LIMIT; i++) {
        cin>>hands[i];
        cin>>suits[i];
    }
}

void deal(int hands[], int suits[]) {
    
    
    for (int i = 0; i < CARD_LIMIT; i++) {
        hands[i] = rand()%13 + 1; // store random values of 5 cards in the array
        suits[i] = rand()%4 + 1;
        switch (hands[i]) {
            case 10:
                cout<<"Ten ";
                break;
                
            case 11:
                cout<<"Jack ";
                break;
                
            case 12:
                cout<<"Queen ";
                break;
                
            case 13:
                cout<<"King ";
                break;
        }
        switch(suits[i]) {
            case 1:
                cout<<"Spades ";
                break;
            case 2:
                cout<<"Hearts ";
                break;
            case 3:
                cout<<"Clubs ";
                break;
            case 4:
                cout<<"Diamonds ";
                break;
            default:
                cout<<"Out of Bound"<<endl;
                break;
        }
        
        cout<<hands[i]<<endl;
        //        cout<<suits[i]<<endl;
    }
}

int high(int hands[]) {
    int max = hands[0]; // Storing the first card to be the biggest number for further comparison
    for (int i = 0; i < CARD_LIMIT; i++) {
        if (hands[i] > max) {
            max = hands[i];
        }
    }
    return max;
}

bool one(int hands[]) {
    
    for (int i = 0; i<CARD_LIMIT; i++) {
        for (int j = i + 1; j<CARD_LIMIT; j++) {
            if (hands[i]==hands[j])
                return true;
        }
        
    }
    return false;
    
}


bool two(int hands[]) {
    int pair_count = 0;
    for (int i = 0; i<CARD_LIMIT; i++) {
        for (int j = i + 1; j<CARD_LIMIT; j++) {
            if (hands[i] == hands[j]) {
                pair_count++;
            }
        }
    }
    if (pair_count == 2) {
        return true;
    }
    else {
        return false;
    }
    
}

bool triple(int hands[]) {
    
    
    for (int i = 0; i<CARD_LIMIT; i++) {
        int triple_counter = 0;
        
        for (int j = i + 1; j<CARD_LIMIT; j++) {
            if (hands[i] == hands[j]) {
                triple_counter++;
            }
            if (triple_counter == 2) {
                return true;
            }
        }
    }
    return false;
    
    
}

bool straight(int hands[]) {
    int min = hands[0];
    
    // First card
    for (int i = 0; i < CARD_LIMIT; i++) {
        if (hands[i] < min) {
            min = hands[i];
        }
    }
    // the rest of the cards after the first card
    for (int i = 1; i <= 4; i++) {
        bool is_straight = false;
        
        
        for (int j =0; j<CARD_LIMIT; j++) {
            if (hands[j] == (min + i)) {
                is_straight = true;
            }
        }
        
        if (is_straight == false) {
            return false;
        }
    }
    return true;
    
}

bool full(int hands[]) {
    int triple_counter = 0;
    for (int i = 0; i<CARD_LIMIT;i++) {
        int pair_counter = 0;
        
        for (int j = i + 1; j < CARD_LIMIT; j++){
            if (hands[i] == hands[j]){
                pair_counter++;
            }
            
            if (pair_counter == 2) {
                triple_counter = hands[i];
                break;
            }
        }
        
    }
    if (triple_counter == 0) {
        return false;
    }
    
    for (int i = 0; i < CARD_LIMIT; i++) {
        for( int j = i + 1; j < CARD_LIMIT; j++) {
            if ((hands[i] == hands[j]) && (hands[i] != triple_counter)) {
                return true;
            }
        }
    }
    
    return false;
}

bool four(int hands[]) {
    
    
    for (int i = 0; i<CARD_LIMIT; i++) {
        int pair_counter = 0;
        
        for (int j = i + 1; j<CARD_LIMIT; j++) {
            if (hands[i] == hands[j]) {
                pair_counter++;
            }
            if (pair_counter == 3) {
                return true;
            }
        }
    }
    return false;
}

bool flush(int suits[]) {
    
    int i = 0;
    for (int j = i + 1; j<CARD_LIMIT; j++) {
        if (suits[i] != suits[j]) {
            return false;
        }
        
    }
    return true;
    
    
}

void check_hands(int hands[], int suits[]) {
    
    cout<<"Result: ";
    
    if (flush(suits) && straight(hands)) {
        cout<<"Straight Flush";
        
    }
    else if (four(hands)) {
        cout<<"4 of a Kind";
        
    }
    
    else if (full(hands)) {
        cout<<"Fullhouse";
        cout<<endl;
        
    }
    else if (flush(suits)) {
        cout<<"Flush";
        
    }
    else if (straight(hands)) {
        cout<<"Straight";
        
    }
    
    
    else if (triple(hands)) {
        cout<<"3 of a Kind";
        cout<<endl;
        
    }
    else if (two(hands)) {
        cout<<"2 Pairs";
        cout<<endl;
        
    }
    else if (one(hands)) {
        cout<<"A Pair";
        
    }
    else {
        cout<<"High hand with "<<high(hands);
    }
    cout<<endl;
}

/* Sample Output
 
 Press [1] for Dealer to deal cards
 Press [2] for Player to input their cards
 1
 Diamonds 2
 Hearts 7
 Spades 5
 Clubs 1
 Clubs 8
 Result: High hand with 8
 Would you like a new hand?
 y
 Press [1] for Dealer to deal cards
 Press [2] for Player to input their cards
 1
 Spades 9
 King Hearts 13
 Clubs 2
 Clubs 1
 Hearts 6
 Result: High hand with 13
 Would you like a new hand?
 y
 Press [1] for Dealer to deal cards
 Press [2] for Player to input their cards
 2
 Enter all hands from (1-10 for numerical cards)
 Example: 10 then press enter
 1 then press enter. This means 10 of Spades
 Repeat this till you have 5 cards
 Press
 [11] for Jack
 [12] for Queen
 [13] for King
 For Suits
 Press
 [1] for Spades
 [2] for Hearts:
 [3] for Clubs
 [4] for Diamonds
 11
 1
 3
 2
 13
 3
 12
 3
 1
 2
 Result: High hand with 13
 Would you like a new hand?
 n
 
 
 
 */

