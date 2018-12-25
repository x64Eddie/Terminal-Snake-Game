
#include <iostram>

bool gameOver;
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score;
enum Direction {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
}
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
    system("cls")//clear the teminal window

    //top wall
    for(int i = 0; i < width; i++){
        count << "#";
    }
    count << endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j ++){
            
            if(j == 0 | j == (width - 1)){
                //we are going to print the walls here
                count << "#";
            }
            else{
                count << " ";
            }
        }
    }

    //bottom wall
    for(int i = 0; i < width; i++){
        count << "#";
    }
}

void Input(){

}

void Logic(){

}

int main(){
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
    }
    return 0;
}