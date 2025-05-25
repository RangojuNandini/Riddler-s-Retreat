#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 1000
#define TOP_PLAYERS 30

// Function prototypes
int askQuestion(const char *question, const char *correctAnswer, int points);
int set1();
int set2();
int set3();
int set4();
int set5();
int set6();
void displayLeaderboard(char playerNames[][50], int playerScores[], int totalPlayers, int currentPlayerIndex);
void sortLeaderboard(char playerNames[][50], int playerScores[], int totalPlayers);
void clearInputBuffer();  // Clear input buffer for name input

int main()
{
    int totalPlayers = 0;  // Initialize totalPlayers to 0
    int totalScore = 0;
    int choose;
    int currentPlayerIndex;

    // Global leaderboard arrays
    char playerNames[MAX_PLAYERS][50];
    int playerScores[MAX_PLAYERS];

    while (1) {  // This loop keeps the process running
        printf("                                                ****RIDDLER'S RETREAT****\n");
        printf("Enter your name: ");
        fgets(playerNames[totalPlayers], 50, stdin);
        playerNames[totalPlayers][strcspn(playerNames[totalPlayers], "\n")] = '\0';  // Remove newline character

        printf("Welcome, %s!\n", playerNames[totalPlayers]);
        totalScore = 0;  // Reset score for the new player

        // Play the game - player chooses a set
        while (1) {
            printf("Choose a Set to play:\n");
            printf("1.Set1\n2.Set2\n3.Set3\n4.Set4\n5.Set5\n6.Set6\n");
            printf("Enter your choice: ");
            scanf("%d", &choose);
            printf("Please enter all words in lowercase letters\n");
            clearInputBuffer();

            switch (choose) {
                case 1:
                    totalScore = set1();
                    break;
                case 2:
                    totalScore = set2();
                    break;
                case 3:
                    totalScore = set3();
                    break;
                case 4:
                    totalScore = set4();
                    break;
                case 5:
                    totalScore = set5();
                    break;
                case 6:
                    totalScore = set6();
                    break;
                default:
                    printf("Wrong entry. Please choose a valid set.\n");
                    continue;
            }

            // Update the score for the current player
            playerScores[totalPlayers] = totalScore;

            // Sort the leaderboard and display it
            sortLeaderboard(playerNames, playerScores, totalPlayers + 1);  // Include current player in leaderboard
            displayLeaderboard(playerNames, playerScores, totalPlayers + 1, totalPlayers);  // Show the current player's position

            printf("\nThank you for playing this session!\n");

            // Ask if the player wants to play again
            char choice;
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &choice);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            clearInputBuffer();

            if (choice == 'n' || choice == 'N') {
                totalPlayers++;  // Increment totalPlayers when the player finishes for good
                break;  // Exit the inner game loop and move to the next player
            } else {
                // Reset total score for a new session, keep the player on the leaderboard
                totalScore = 0;
            }
        }
    }

    return 0;
}

void sortLeaderboard(char playerNames[][50], int playerScores[], int totalPlayers)
{
	int i,j;
    for (i = 0; i < totalPlayers - 1; i++) {
        for (j = i + 1; j < totalPlayers; j++) {
            if (playerScores[i] < playerScores[j]) {
                // Swap scores
                int tempScore = playerScores[i];
                playerScores[i] = playerScores[j];
                playerScores[j] = tempScore;

                // Swap names
                char tempName[50];
                strcpy(tempName, playerNames[i]);
                strcpy(playerNames[i], playerNames[j]);
                strcpy(playerNames[j], tempName);
            }
        }
    }
}

void displayLeaderboard(char playerNames[][50], int playerScores[], int totalPlayers, int currentPlayerIndex)
{
	int i;
    printf("\n** TOP 30 LEADERBOARD **\n");

    // Display top 30 players
    for (i = 0; i < TOP_PLAYERS && i < totalPlayers; i++) {
        printf("%d. %s: %d points\n", i + 1, playerNames[i], playerScores[i]);
    }

    //Displays Total number of players
    printf("\nTotal players so far :   ",playerNames[currentPlayerIndex]);
    int rank = -1;
    for (i = 0; i < totalPlayers; i++) {
        if (strcmp(playerNames[i], playerNames[currentPlayerIndex]) == 0) {
            rank = i + 1;
            break;
        }
    }
    printf("%d\n", rank);
}

int askQuestion(const char *question, const char *correctAnswer, int points)
{
    char ans[50];
    int score = 0;
    clock_t start, end;
    double timeTaken;

    printf("%s\n", question);
    start = clock();  // Start the timer

    printf("You have 30 seconds to answer. Enter your answer: ");
    scanf("%[^\n]%*c", ans);

    end = clock();  // Stop the timer
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    if (timeTaken > 30) {
        printf("Time's up! You took too long to answer.\n");
        printf("The correct answer was: %s\n\n", correctAnswer);
    } else {
        if (strcmp(ans, correctAnswer) == 0) {
            printf("Correct!!\n\n");
            score += points;
        } else {
            printf("Wrong answer. The correct answer was: %s\n\n", correctAnswer);
        }
    }

    return score;
}

int set1()
{
    int score = 0;
    score += askQuestion("1. I am an odd number. Take away a letter and I become even. What number am I?", "seven", 5);
    score += askQuestion("2. I am the only organ that named myself.What am I?", "brain", 5);
    score += askQuestion("3. I'm tall when Iam young and short when I'm old.What am I?","candle",5);
    score += askQuestion("4. Where is the only place where today comes before yesterday?", "dictionary", 5);
    score += askQuestion("5. What begins with an e and only contains one letter?", "envelope", 5);
    return score;
}

int set2()
{
    int score = 0;
    score += askQuestion("1. What starts with T,ends with T,and has T in it?", "teapot", 5);
    score += askQuestion("2. What has to be broken before you can use it?", "egg", 5);
    score += askQuestion("3. What has a face and two hands but no arms or legs?", "clock", 5);
    score += askQuestion("4. What bank has no money?", "bloodbank", 5);
    score += askQuestion("5. Which letter of the alphabet has the most water?", "c", 5);
    return score;
}

int set3()
{
    int score = 0;
    score += askQuestion("1. What is the richest nut?", "cashewnut", 5);
    score += askQuestion("2. What kind of room has no walls,doors,windows?", "mushroom", 5);
    score += askQuestion("3. What belongs to you, but your friends use it more than you do?", "name", 5);
    score += askQuestion("4. What has legs but cannot walk?", "chair", 5);
    score += askQuestion("5. Nobody empties me, but I never stay full for long. What am I?", "moon", 5);
    return score;
}

int set4()
{
    int score = 0;
    score += askQuestion("1. What goes up but never comes back down?", "age", 5);
    score += askQuestion("2. What is full of holes but still holds water?", "sponge", 5);
    score += askQuestion("3. I have cities but not houses. I have mountains but no trees. I have coasts but no sand. What am I?", "map", 5);
    score += askQuestion("4. I have a neck, but no head. What am I?", "bottle", 5);
    score += askQuestion("5. The more you take,the more you leave behind", "footsteps", 5);
    return score;
}

int set5()
{
    int score = 0;
    score += askQuestion("1. Take off my skin - I won't cry, but you will! What am I?", "onion", 5);
    score += askQuestion("2. If you have it,you don't share it.If you share it,you don't have it.What is it?", "secret", 5);
    score += askQuestion("3. What has words,but never speaks?","book", 5);
    score += askQuestion("4. The more there is,the lesss you see.What am I?","darkness", 5);
    score += askQuestion("5. What is always in front of you but cannot be seen?", "future", 5);
    return score;
}

int set6()
{
    int score = 0;
    score += askQuestion("1. I am always hungry, I must always be fed. The finger I touch, will soon turn red. What am I?", "fire", 5);
    score += askQuestion("2. What comes once in a minute, twice in a moment, but never in a thousand years?", "m", 5);
    score += askQuestion("3. It has keys,but no locks.It has space,but no room.You can enter,but you can't go inside.What is it?","keyboard",5);
    score += askQuestion("4. What has 13 heart,but no lungs and stomach?", "deck of cards", 5);
    score += askQuestion("5. What comes down but never goes up?", "rain", 5);
    return score;
}

void clearInputBuffer()
{
    while (getchar() != '\n');
}
