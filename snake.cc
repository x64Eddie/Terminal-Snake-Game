/**
 * This is going to be the snake obj. Its going to control where the snake in the
 * game is, for example, the input of the snake the printing of the snake in the
 * game field among other things.
 **/ 
class Snake{
    private:
        int coorX, coorY;
        int leftKey, rightKey, upKey, downKey;

    public:
        Snake(int startX, int startY){
            coorX = startX;
            coorY = startY;
        }
        void setControls(int left, int right, int up, int down){
            leftKey = left;
            rightKey = right;
            upKey = up;
            downKey = down;
        }
        void initSnake(){

        }

}