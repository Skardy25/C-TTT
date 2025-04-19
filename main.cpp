// Online C++ compiler to run C++ program online
#include <iostream>
#include <ctime>
#include <cstdlib> 

void drawBorad(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTitle(char *spaces);

int main() {
    srand(time(0));
    
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    
    drawBorad(spaces);
    
    while(running){
        playerMove(spaces, player);
        if(checkWinner(spaces, player, computer )){
            running == false;
            drawBorad(spaces);
            break;
        }
        if(checkTitle(spaces)){
            running == false;
            std::cout << "Fin del juego empate." << std::endl;
            break;
        }
        computerMove(spaces, computer);
        drawBorad(spaces);
    }
    return 0;
}

void drawBorad(char *spaces){
   std::cout << "   |   |    " << std::endl;
   std::cout << " "<< spaces[0] <<" |"  << " "<< spaces[1] <<" |" << " "<< spaces[2] << std::endl;
   std::cout << "___|___|___" << std::endl;
   std::cout << "   |   |    " << std::endl;
   std::cout << " "<< spaces[3] <<" |"  << " "<< spaces[4] <<" |" << " "<< spaces[5] << std::endl;
   std::cout << "___|___|___" << std::endl;
   std::cout << "   |   |    " << std::endl;
   std::cout << " "<< spaces[6] <<" |"  << " "<< spaces[7] <<" |" << " "<< spaces[8] << std::endl;
   std::cout << "___|___|___" << std::endl;
   
}
void playerMove(char *spaces, char player){
    int number;
    do{
        std::cout << "Ingrese la posicion (1-9) : " << std::endl;
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
        
    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int randomNum ;
    do {
        randomNum = rand() % 9;
        if(spaces[randomNum] == ' '){
            spaces[randomNum] = computer;
            break;
        }
    }while(true);
    
}
bool checkWinner(char *spaces, char player, char computer){
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (spaces[i] == player && spaces[i + 1] == player && spaces[i + 2] == player) {
            std::cout << "¡Ganaste!" << std::endl;
            return true;
        }
        if (spaces[i] == computer && spaces[i + 1] == computer && spaces[i + 2] == computer) {
            std::cout << "¡Perdiste!" << std::endl;
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (spaces[i] == player && spaces[i + 3] == player && spaces[i + 6] == player) {
            std::cout << "¡Ganaste!" << std::endl;
            return true;
        }
        if (spaces[i] == computer && spaces[i + 3] == computer && spaces[i + 6] == computer) {
            std::cout << "¡Perdiste!" << std::endl;
            return true;
        }
    }

    // Check diagonals
    if ((spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player)) {
        std::cout << "¡Ganaste!" << std::endl;
        return true;
    }
    if ((spaces[0] == computer && spaces[4] == computer && spaces[8] == computer) ||
        (spaces[2] == computer && spaces[4] == computer && spaces[6] == computer)) {
        std::cout << "¡Perdiste!" << std::endl;
        return true;
    }

    return false;
}
bool checkTitle(char *spaces){
    int count = 0;
    for(size_t i = 0 ; i < 9; ++i){
        if(spaces[i] == ' '){
            count++;
        }
    }
    return count == 0 ? true : false;
}
