
#include <cstdlib>
#include <ncureses.h>

bool gameOver;
const int width = 20, height = 20;
int x, y, fruitX, fruitY, score;
enum Direction = {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
}
Direction dir;

void setup(){

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);


    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = (rand()%width)+ 1;
    fruitY = (rand()%height)+ 1;
    score = 0;

}

void draw(){

}

void input(){

}

void logic(){

}

int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        logic();
    }
    return 0;
}