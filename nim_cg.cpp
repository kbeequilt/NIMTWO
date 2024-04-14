#include <iostream>
#include <iomanip>
#include "nim_cg.hpp"

using namespace std;

//This voided functions job is to simply display the instructions. the first set of instructions only plays if
//it is the first time running the program and then it switches to a simpler set of instructions.
void showInstructions(){
    //this static bool's job is to be false the first time this function plays and then always be true afterwards
    static bool simple = false;
    if (!simple) {
        cout << "Welcome to NIM!" << endl << endl
             <<"------------------------------------------------------------------------" << endl
             << "How To Play NIM" << endl
             << "On a players turn they choose to remove either one, two, or three sticks." << endl
             << "The player that removes the finals stick loses!" << endl
             <<"------------------------------------------------------------------------" << endl << endl;
        simple = true;
    }else{
        cout << endl << endl <<"Remove sticks until one player removes the final stick." << endl << endl;
    }
}
//this functions job is to take the number of sticks and then display it with setfill and setwidth
void showBoard(int sticks){
    cout << "Current amount of sticks: " << endl;
    cout << setfill('|') << setw(sticks) << "|" << endl;

}

//this function calls how many sticks the user wants removed and then outputs it to the main function.
int getMove(int sticks){
    int stickRemove;
    cout << "How many sticks do you want removed?" << endl;
    cin >> stickRemove;

    //this while loop makes sure that the amount of sticks you want removed is a valid amount.
    //it also clears the cin so that the program doesn't break
    while(!cin || stickRemove <= 0 || stickRemove >= 4){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid number, pick a new number" << endl;
        cin >> stickRemove;
    }
    //this while loop makes sure that you cannot remove more stick then are available.
    while (sticks < stickRemove){
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid number, pick a new number" << endl;
        cin >> stickRemove;
    }
    return stickRemove;

}

//this function asks you if you want to play again using a char array to that you are able to write the whole word
//or just the first letter.
int playAgain(){
    char again[10];
    //this is an infinite loop that I made because we always break out of it using return functions. this is to make
    //sure that we always get an answer that we want.
    while(1 < 2) {
        cout << "Want to play again? (Y/N)" << endl;
        cin >> again;
        if (again[0] == 'y' || again[0] == 'Y') {
            return 1;
        } else if (again[0] == 'n' || again[0] == 'N') {
            cout << "So long";
            return 0;
        } else {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input" << endl;
        }
    }

}