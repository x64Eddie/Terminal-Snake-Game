
#include <iostream>

bool gameOver;
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score;
enum Direction {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
Direction dir;

void Setup(){

    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = (rand()%width);
    fruitY = (rand()%height);
    score = 0;

}

void Draw(){
    system("clear");//clear the teminal window

    //top wall
    for(int i = 0; i < width; i++){
        std::cout << "#";
    }
    std::cout << std::endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j ++){
            
            if(j == 0 | j == (width -1)){
		//we are going to print the walls here
		std::cout << "#";
		}
	    else{
		std::cout << " ";
		}
        }
	std::cout << std::endl;
    }

    //bottom wall
    for(int i = 0; i < width; i++){
        std::cout << "#";
    }

    //we are going to skip a line then we are going to put the score below the window
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void Input(){

}

void Logic(){

}

int main(){
    Setup();
	Draw();
//    while(!gameOver){
//        Draw();
//        Input();
//        Logic();
// }
    return 0;
}
