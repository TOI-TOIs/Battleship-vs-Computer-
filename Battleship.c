#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[]) {
    char PlB[10][10];
    char name[20];
    char status1[20] = "Not placed yet"; 
    char status2[20] = "Not placed yet";
    char orient;
    char accept;

    int i, j, age, choice;
    int place1 = 0, place2 = 0; // The status of every boat
    int pos1, pos2;
    int OutOfBounds = 0; // This variable is to simplify the boundary checks.
    int len; // This variable is to simplify the lengths of the boats.
    int Autoattack = 0,remember1 = 0, remember2 = 0,strick = 0; //the variables for the targeted attack

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            PlB[i][j] = '.';
        }
    }

    // TASK 1
    printf("Welcome to Battleship vs Computer\n\n\n");
    printf("Initial Empty Board (10x10)\n\n");  

    printf("   1  2  3  4  5  6  7  8  9  10\n"); // Prints so it can be more friendly to use 
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        for (j = 0; j < 10; j++) {
            printf("%c  ", PlB[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Enter your name: ");
    scanf("%19s", name);

    do {
        printf("Enter your age: ");
        scanf("%d", &age);
    } while (age <= 0 || age > 119);

    // TASK 2
	printf("Player %s will play first. Computer plays Second.\n",name);
	printf("--- Ship placement phase for player %s ---\n",name);
	printf("You must place 2 ships: one of length 2 and one of length 4.\n");
    accept = 'N';
    while (accept != 'Y' && accept != 'y'){
        while (place1 == 0 || place2 == 0) {
            
            if (place1 == 1){
                strcpy(status1, "Placed");
            }
            if (place2 == 1){
                strcpy(status2, "Placed");             
            }

            printf("Select which ship to place:\n");
            printf("\t1: ship of length 2 (%s)\n",status1);
            printf("\t2: ship of length 4 (%s)\n",status2);


            do {
                printf("Enter 1 or 2: "); // epilogi varkas
                scanf("%d", &choice);
                
                if ((choice == 1 && place1 == 1) || (choice == 2 && place2 == 1)) {
                    printf("This ship has already been placed. Select again.\n");
                    choice = 0; 
                } 
                else if (choice != 1 && choice != 2) {                                         // check for boat
                    printf("Invalid choice. Try again.\n");
                }
            } while (choice != 1 && choice != 2);


            do {
                OutOfBounds = 0;
                if (choice == 1){
                    len = 2;
                }
                else{
                    len = 4;
                }

                printf("Enter starting cell for ship of length 2 (row col, 1-10):");
                scanf("%d %d", &pos1, &pos2);

                
                pos1--; 
                pos2--; // i need this beucase i have the code possitions between 1-10 for the user


                if (pos1 < 0 || pos1 > 9 || pos2 < 0 || pos2 > 9) {
                    printf("Out of bounds. Try again. \n");                       // first boundiaries
                    OutOfBounds = 1;
                }
                else{
                    printf("Ship can be placed horizontally or vertically.\n");
                    printf("Enter orientation (H/h for horizontal, V/v for vertical:)");
                    scanf(" %c", &orient); 

                    if (orient == 'H' || orient == 'h') {
                        if (pos2 + len > 10) {
                            printf("Out of bounds. Try again.\n");                //the second limits for horizontal
                            OutOfBounds = 1;
                        } 
                        else {

                            if (choice == 1) {
                                if (PlB[pos1][pos2] == '.' && PlB[pos1][pos2 + 1] == '.'){      //the third limits for the small boat and horizontal
                                PlB[pos1][pos2] = '<';
                                PlB[pos1][pos2 + 1] = '>';
                                }
                                else{
                                    printf("Position taken, Please try again.\n");
                                    OutOfBounds = 1;
                                }
                            } 
                            else {
                                if (PlB[pos1][pos2] == '.' && PlB[pos1][pos2 + 1] == '.' && PlB[pos1][pos2 + 2] == '.' && PlB[pos1][pos2 + 3] == '.'){
                                PlB[pos1][pos2] = '<';                                          // the third limits for big boat and horizontal
                                PlB[pos1][pos2 + 1] = '='; 
                                PlB[pos1][pos2 + 2] = '=';
                                PlB[pos1][pos2 + 3] = '>';
                                }
                                else{
                                    printf("Position taken, Please try again.\n");
                                    OutOfBounds = 1;
                                }
                            }
                        }
                    } 
                    else if (orient == 'V' || orient == 'v') {
                        if (pos1 + len > 10) {
                            printf("Out of bounds. Try again.\n");                   //the second linits for vertical
                            OutOfBounds = 1;
                        } 
                        else {
                            if (choice == 1) {
                                if (PlB[pos1][pos2] == '.' && PlB[pos1 + 1][pos2] == '.'){      //the second limits for small boat and vertical
                                PlB[pos1][pos2] = '^';
                                PlB[pos1 + 1][pos2] = 'v';
                                }
                                else{
                                    printf("Position taken, Please try again.\n");
                                    OutOfBounds = 1;
                                }
                            } 
                            else {
                                if (PlB[pos1][pos2] == '.' && PlB[pos1 +1 ][pos2] == '.' && PlB[pos1 + 2][pos2] == '.' && PlB[pos1 + 3][pos2] == '.'){
                                PlB[pos1][pos2] = '^';                                          // the second limits for big boat and vertical
                                PlB[pos1 + 1][pos2] = '|';
                                PlB[pos1 + 2][pos2] = '|';
                                PlB[pos1 + 3][pos2] = 'v';
                                }
                                else{
                                    printf("Position taken, Please try again.\n");
                                    OutOfBounds = 1;
                                }
                            }
                        }
                    } else {
                        printf("Invalid input. Please try again.\n");
                        OutOfBounds = 1;
                    }
                }
            } while (OutOfBounds == 1);

            
            if (choice == 1){
                place1 = 1;
            }
            else {
                place2 = 1;
            }

            printf("\nThe board with the ships placed:\n");
            printf("   1  2  3  4  5  6  7  8  9  10\n"); 
            for (i = 0; i < 10; i++) {
                printf("%2d ", i + 1);
                for (j = 0; j < 10; j++) {
                    printf("%c  ", PlB[i][j]);
                }
                printf("\n");
            }
        }
        printf("Do you accept this placement:(Y/N)");
        scanf(" %c",&accept);
        printf("\n");
        while (accept != 'Y' && accept != 'y' && accept != 'N' && accept != 'n'){
            printf("Invalid option. Try again.");
            printf("Do you accept this placement:(Y/N)");
            scanf(" %c",&accept);
        }
        if (accept == 'N'|| accept == 'n'){
            place1 = 0;
            place2 = 0;
            strcpy(status1, "Not Placed yet.");
            strcpy(status2, "Not Placed yet.");
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 10; j++) {
                    PlB[i][j] = '.';
                }
            }
        }
    } 
    printf("\nAll ships are placed. Game starts!\n");
    
    //TASK 3
    char BotB[10][10];                        //the board fot the bot
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            BotB[i][j] = '.';
        }
    }

    srand(time(NULL));
    int continie = 0;                           //variavle for simplify the while
    while (continie == 0){
        pos1 = (rand() % 10);
        pos2 = (rand() % 10);
        int orient = 1 + (rand() % 2);          // 1 for vertical / 2 for horizontal
        
        if (orient == 1){
            if (pos1 < 9){
                BotB[pos1][pos2] = '*';
                BotB[pos1+1][pos2] = '*';
                continie = 1;
            }
        }
        else{
            if (pos2 < 9){
                BotB[pos1][pos2] = '*';
                BotB[pos1][pos2+1] = '*';
                continie = 1;
            }
        }
    }

    continie = 0;                           ////variavle for simplify the while
    while (continie == 0){
        pos1 = (rand() % 10);
        pos2 = (rand() % 10);
        int meria = 1 + (rand() % 2);          // 1 for vertical / 2 for horizontal
        
        if (meria == 1){
            if (pos1 < 7){
                if (BotB[pos1][pos2] != '*' && BotB[pos1+1][pos2] != '*' && BotB[pos1+2][pos2] != '*' && BotB[pos1+3][pos2] != '*'){
                    BotB[pos1][pos2] = '*';
                    BotB[pos1+1][pos2] = '*';
                    BotB[pos1+2][pos2] = '*';
                    BotB[pos1+3][pos2] = '*';
                    continie = 1;
                }
            }
        }
        else{
            if (pos2 < 7){
                if ( BotB[pos1][pos2] != '*' && BotB[pos1][pos2+1] != '*' && BotB[pos1][pos2+2] != '*' && BotB[pos1][pos2+3] != '*'){
                    BotB[pos1][pos2] = '*';
                    BotB[pos1][pos2+1] = '*';
                    BotB[pos1][pos2+2] = '*';
                    BotB[pos1][pos2+3] = '*';
                    continie = 1;
                }
            }
        }
    }

    char DecoyB[10][10];
    int hit,ScoreB = 0,ScoreP = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            DecoyB[i][j] = '.';
        }
    }
    do{
        do{
            hit = 0;
            if (ScoreP < 6 ){
                do{
                    OutOfBounds = 0;
                    printf("Enter the coordinates you want to hit:(1-10 1-10)");
                    scanf(" %d %d", &pos1, &pos2);
                    pos1--;
                    pos2--;
                    if (pos1 > 9 || pos2 > 9 || pos1 < 0 || pos2 < 0){
                        printf("Out of Bounds.\n");
                        OutOfBounds = 1;
                    }
                    else if (DecoyB[pos1][pos2] != '.'){
                        printf("This coordinates has already been hit.\n");
                        OutOfBounds = 1;
                    }
                } while (OutOfBounds == 1);
                if (BotB[pos1][pos2] == '*'){
                    printf("You found a target.\n");
                    DecoyB[pos1][pos2] = '@';
                    hit = 1;
                    ScoreP++;
                }
                else{
                    printf("You missed.\n");
                    DecoyB[pos1][pos2] = 'X';
                }
                printf("   1  2  3  4  5  6  7  8  9  10\n"); 
                for (i = 0; i < 10; i++) {
                    printf("%2d ", i + 1); 
                    for (j = 0; j < 10; j++) {
                        printf("%c  ", DecoyB[i][j]);
                    }
                    printf("\n");
                }
            }
    } while (hit == 1);

    if (ScoreP != 6){
        do{
            hit = 0;
            do{
                OutOfBounds = 0;                        //if it's not autoattack to go to random
                if (Autoattack == 0){
                    pos1 = (rand() % 10);
                    pos2 = (rand() % 10);
                }
                else{
                    pos1 = remember1;
                    pos2 = remember2;
                }
                if (strick == 1){
                    pos1++;
                }
                else if (strick == 2){                  //if it's autoattack to check sideways
                    pos1--;
                }
                else if (strick == 3){
                    pos2++;
                }
                else if (strick == 4){
                    pos2--;
                }
                
                if (pos1 < 0 || pos1 > 9 || pos2 < 0 || pos2 > 9){
                    strick++;
                    OutOfBounds = 1;
                }
                else if (PlB[pos1][pos2] == 'X' || PlB[pos1][pos2] == '@'){ // check the possition of the autoattack
                    strick++;
                    OutOfBounds = 1;
                }

                if (PlB[pos1][pos2] != 'X' && PlB[pos1][pos2] != '@'){
                    if (PlB[pos1][pos2] != '.'){
                        printf("Bot found a target.\n");
                        PlB[pos1][pos2] = '@';
                        ScoreB++;
                        hit = 1;
                        Autoattack = 1;
                        remember1 = pos1;
                        remember2 = pos2;
                    }
                    else{
                        printf("Bot missed.\n");
                        PlB[pos1][pos2] = 'X';
                        strick++;
                        hit = 0;
                    }
                    printf("   1  2  3  4  5  6  7  8  9  10\n"); 
                    for (i = 0; i < 10; i++) {
                        printf("%2d ", i + 1);
                        for (j = 0; j < 10; j++) {
                            printf("%c  ", PlB[i][j]);
                        }
                        printf("\n");
                    }
                }
                if (strick > 4){
                    strick = 0;
                    Autoattack =0;  
                }
            } while (OutOfBounds == 1);  
        } while (hit == 1);   
    }
    } while (ScoreB < 6 && ScoreP < 6); 

    printf("The game has ended.\n");
    if (ScoreB == 6){
        printf("Computer won");
    }
    else{
        printf("%s won",name);
    }
    return 0;
}