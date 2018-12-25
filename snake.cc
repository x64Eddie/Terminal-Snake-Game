
#include <iostream>
#include <ncurses.h>

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

    initscr();
    cbreak();
    refresh();
}

void Draw(){
//    system("clear");//clear the teminal window
    clear();
    //top wall
    for(int i = 0; i < width; i++){
        mvprintw(0,i,"#");
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j ++){
            
            if(j == 0 | j == (width -1)){
		//we are going to print the walls here
		mvprintw(j,i,"#");
		}
	    if(i == y && j ==  x){
		mvprintw(i,j,"O");;
		}
	    else if(i == fruitX && j == fruitY){
		mvprintw(i,j,"F");
		}
	    else{
		mvprintw(i,j," ");
		}
        }
    }

    //bottom wall
    for(int i = 0; i < width; i++){
        mvprintw((width-1),i,"#");
    }

    //we are going to skip a line then we are going to put the score below the window
    mvprintw(height+1, 0,"Score:");
}

int kbhit(void){
        int ch = getch();
        if(ch != ERR){
                ungetch(ch);
                return 1;
        }
        else{
                return 0;
        }
}


void Input(){
	if(kbhit()){
		switch(getch()){
			case 'a':
				dir = LEFT;
				refresh();				
				break;
			case 'd':
				dir = RIGHT;
				refresh();
				break;
			case 's':
				dir = DOWN;
				refresh();
				break;
			case 'w':
				dir = UP;
				refresh();
				break;
			case 'x':
				gameOver = false;
				refresh();
				break;
		}
	}
	
	
}

void Logic(){
	switch(dir){
		case STOP:
			break;
		case RIGHT:
			x++;
			break;
		case LEFT:
			x--;
			break;
		case UP:
			y++;
			break;
		case DOWN:
			y--;
			break;
	}

}   

int main(){
    Setup();
    while(!gameOver){
        Draw();
	std::cout << "pressed";
        Input();
        Logic();
	 }
    return 0;
}
