#include <iostream>
#include <string>
#include <random>

//Making tic tac toe

//Declarations
//===========================================================================
//1.    print menu.
int printMenu();
//2.    Create the players.
std::string CreatePlayer();
//3.    print and update the board.
void PrintBoard();
//4.    Input validation.
int input_validation(std::string & player);
//5.    Switching players arround for each turn.
std::string switch_players(std::string& player1, std::string& player2);
//6.    Switching between the 'O' and 'X'.
char switch_char(char& a, char& b);
//7.    GameEngine
void GameEngine(std::string& player1, std::string& player2);
//8.    Check for a winner.
bool CheckForWinner(char& n1, char& n2, char& n3, char& n4, char& n5, char& n6, char& n7, char& n8, char& n9);
//9.    Random AI bot
int Ai_Random();
//Global variables for positions.
//===========================================================================
char n1 = '1', n2 = '2', n3 = '3', n4 = '4', n5 = '5', n6 = '6', n7 = '7', n8 = '8', n9 = '9';
int used_numbers[50];
int turns = 0;
int array_input[9];

int main()
{
    int input;
    input = printMenu();
    std::string player1, player2;

    if (input == 1)
    {
        std::cout << "Enter Player name...\n";
        std::string Player1ptr;
        player1 = CreatePlayer();
        std::cout << "Goodluck " << player1;
        std::cout << " your game is starting... " << std::endl;
        player2 = "Computer";
        GameEngine(player1, player2);
    }
    else if (input == 2)
    {
        std::cout << "Player 1 please enter a name...\n";
        player1 = CreatePlayer();
        std::cout << "Player 2 please enter a name...\n";
        player2 = CreatePlayer();
        std::cout << "Goodluck " << player1 << " and " << player2;
        std::cout << " your game is starting... " << std::endl;
        GameEngine(player1, player2);

    }
    return 0;
}

//  Function definitions.
//===========================================================================

//1.    Menu.
int printMenu()
{
    int choice;
    std::cout << "\tWelkom to Tik Tak Toe\n";
    std::cout << "\t****Please select****\n";
    std::cout << std::endl;
    std::cout << "\t (1)  * SinglePlayer\n";
    std::cout << "\t (2)  * Multiplayer\n";
    std::cin >> choice;
    return choice;
}

//2.    Creat player(s)
std::string CreatePlayer()
{
    std::string player;
    std::cin >> player;
    return player;
}

//3.    Print and update board.
void PrintBoard()
{
    std::cout << "     Tic Tak Toe" << std::endl;
    std::cout << std::endl;
    std::cout << "\t" << n1 << "|" << n2 << "|" << n3 << "\n";
    std::cout << "\t" << "-----\n";
    std::cout << "\t" << n4 << "|" << n5 << "|" << n6 << "\n";
    std::cout << "\t" << "-----\n";
    std::cout << "\t" << n7 << "|" << n8 << "|" << n9 << "\n";
}

//4   Input validation.
int input_validation(std::string & player)
{
    
      
    //Checking if the number is between 1 and 9;
    bool checking = true;
    int PlayerMove;
    std::cout << player << " is on turn \n";
    //SinglePlayer
    if (player == "Computer")
    {
        return Ai_Random();
    }

    
    while (!(std::cin >> PlayerMove))
    {
        std::cout << "Please fill in a number: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }

    while (PlayerMove < 1 || PlayerMove > 9)
    {
        std::cout << "Your number is not in range, please select 1 to 9: " << std::endl;
        std::cin >> PlayerMove;
    }
    // Checking if number isnt used before.
    while (checking)
    {
        for (int i = 0; i < 50; i++)
            if (used_numbers[i] == PlayerMove)
            {
                std::cout << "Whoops, this spot is already taken. Try another spot." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cin >> PlayerMove;
                std::cout << "Entered number is: " << PlayerMove << std::endl;
            }
        break;
    }  
    used_numbers[turns] = PlayerMove;
    turns++;
    checking = false;
    return PlayerMove;
    std::cout << "Returned number is: " << PlayerMove << std::endl;
}    

//5.    Switching players arround for each turn.
std::string switch_players(std::string & player1, std::string & player2)
{
    std::string temp;
    temp = player1;
    player1 = player2;
    player2 = temp;
    return player2;
}

//6.    Switching between the 'O' and 'X'.
char switch_char(char& player1, char& player2)
{
    char temp;
    temp = player1;
    player1 = player2;
    player2 = temp;
    return player2;
}
//7.    GameEngine.
void GameEngine(std::string & player1, std::string & player2)
{
    char player1Char = 'X';
    char player2Char = 'O';
    char player_char;
    int array_input[9];
    std::string player;
    PrintBoard();
    for (int x = 0; x < 9; x++)
    {
        player = switch_players(player1, player2);
        array_input[x] = input_validation(player);
        player_char = switch_char(player1Char, player2Char);
        switch (array_input[x])
        {
        case 1: n1 = player_char;
            break;
        case 2: n2 = player_char;
            break;
        case 3: n3 = player_char;
            break;
        case 4: n4 = player_char;
            break;
        case 5: n5 = player_char;
            break;
        case 6: n6 = player_char;
            break;
        case 7: n7 = player_char;
            break;
        case 8: n8 = player_char;
            break;
        case 9: n9 = player_char;
            break;
        default: std::cout << "ERROR! Something unexpected happend.";
            break;
        }
        PrintBoard();

        if (CheckForWinner(n1, n2, n3, n4, n5, n6, n7, n8, n9))
        {
            std::cout << player << " is the winner!!!";
            break;
        }
    }
}

//8.    Check for a winner.
bool CheckForWinner(char& n1, char& n2, char& n3, char& n4, char& n5, char& n6, char& n7, char& n8, char& n9)
{
    if (n1 == n2 && n2 == n3 && n3 == n1)
        return true;
    else if (n4 == n5 && n5 == n6 && n6 == n4)
        return true;
    else if (n7 == n8 && n8 == n9 && n9 == n7)
        return true;
    else if (n1 == n4 && n4 == n7 && n7 == n1)
        return true;
    else if (n2 == n5 && n5 == n8 && n8 == n2)
        return true;
    else if (n3 == n6 && n6 == n9 && n9 == n3)
        return true;
    else if (n1 == n5 && n5 == n9 && n9 == n1)
        return true;
    else if (n7 == n5 && n5 == n3 && n3 == n7)
        return true;
    else
        return false;
}

int Ai_Random()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> random(1, 9);
    int theNumb = random(generator);
    bool checking = true;
    
    while (checking)
    {
        for (int i = 0; i < 50; i++)
            if (used_numbers[i] == theNumb)
            {
                theNumb = random(generator);
            }
        break;
    }
    used_numbers[turns] = theNumb;
    turns++;
    checking = false;
    return theNumb;
}
