
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

//This is going to draw the figures in to the screen
void Draw(){
//    system("clear");//clear the teminal window
    clear();
    //top wall
    for(int i = 0; i < width; i++){
        mvprintw(0,i,"#");
    }

    for(int i = 0; i < height-1; i++){
        for(int j = 0; j < width; j ++){
            
            if(j == 0 | j == (width -1)){
		//we are going to print the walls here
		mvprintw(i+1,j,"#");
		}
	    if(i == y && j ==  x){
		mvprintw(i,j,"@");;
		}
	    else if(i == fruitX && j == fruitY){
		mvprintw(i,j,"F");
		}
	    else{
//		mvprintw(i,j," ");
		}
        }
    }

    //bottom wall
    for(int i = 0; i < width; i++){
        mvprintw((width-1),i,"#");
    }

    //we are going to skip a line then we are going to put the score below the window
    mvprintw(height+1, 0,"Score: %d",score);

	refresh();
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

	keypad(stdscr, TRUE);
	halfdelay(1);
	int c = getch();

	switch(c){
		case KEY_LEFT:
			dir = LEFT;
			refresh();				
			break;
		case KEY_RIGHT:
			dir = RIGHT;
			refresh();
			break;
		case KEY_DOWN:
			dir = DOWN;
			refresh();
			break;
		case KEY_UP:
			dir = UP;
			refresh();
			break;
		case 113:
			gameOver = false;
			refresh();
			break;
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
    if(x > width || x < 0 || y > height || y < 0){
        gameOver = true;
    }

	if(x == fruitX && y == fruitY){
		score += 10;
		fruitX = (rand()%width);
    	fruitY = (rand()%height);
	}

}   

int main(){
    Setup();
	while(!gameOver){
        Draw();
        Input();
        Logic();
	}
	getch();
	endwin();
    
    return 0;
}
