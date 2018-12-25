
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
    clear();

    for(int i = 0; i < width + 2; i++){
        mvprintw(0, i, "+");
    }
    for(int i = 0; i < height + 2; i++){
        for(int j = 0; j < width + 2; j++){
            if(i == 0 | i == 21){
                mvprintw(i, j, "+");
            }
            else if(j == 0 | j == 21){
                mvprintw(i, j, "+");
            }
            else if(i == y && j == x){
                mvprintw(i, j, "0");
            }
            else if(i == fruitY && j == fruitX){
                mvprintw(i, j, "@");
            }
        }
    }
    mvprintw(23, 0, "Score %d", score);
    refresh();

    getch();
    endwin();
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