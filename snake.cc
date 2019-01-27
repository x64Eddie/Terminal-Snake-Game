/**
 * This is going to be the snake obj. Its going to control where the snake in the
 * game is, for example, the input of the snake the printing of the snake in the
 * game field among other things.
 **/ 
class Snake{
    private:
        int winW, winH;
        int coorX, coorY;
        int leftKey, rightKey, upKey, downKey;
        
        //Going to be printing the snake in the game
        void printing(){
            
        }

    public:
        Snake(int startX, int startY, int windowHeight, int windowWidth){
            coorX = startX;
            coorY = startY;
            winW = windowWidth;
            winH = windowHeight;
        }
        void setControls(int left, int right, int up, int down){
            leftKey = left;
            rightKey = right;
            upKey = up;
            downKey = down;
        }
        void initSnake(){

        }

};