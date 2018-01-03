#include <Arduboy2.h>

Arduboy2 arduboy;

typedef char SquareVal;

#define SIDE_LENGTH 3
#define NUM_SQUARES (SIDE_LENGTH * SIDE_LENGTH)
#define EMPTY '.'
#define CROSS 'X'
#define NOUGHT 'O'

#define THINGO 20

SquareVal squares[SIDE_LENGTH][SIDE_LENGTH];

int selX = 0;
int selY = 0;

SquareVal player;

void clearBoard()
{
  for (int col = 0; col < SIDE_LENGTH; col++)
  {
    for (int row = 0; row < SIDE_LENGTH; row++)
    {
      squares[col][row] = EMPTY;
    }
  }
}

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(15);

  clearBoard();

  player = CROSS;
}

void displayBoard()
{
  arduboy.clear();

  for (int col = 0; col < SIDE_LENGTH; col++)
  {
    int x = col * THINGO;
    for (int row = 0; row < SIDE_LENGTH; row++)
    {
      int y = row * THINGO;
      arduboy.setCursor(x, y);
      int pos = (SIDE_LENGTH * col) + row;
      if (col == selX && row == selY)
      {
        arduboy.drawRect(x, y, THINGO, THINGO, WHITE);
      }
      arduboy.print(squares[col][row]);
    }
  }
  arduboy.display();
}

void changeTurn()
{
  player = player == CROSS ? NOUGHT : CROSS;
}

void loop()
{
  if (!(arduboy.nextFrame()))
    return;

  arduboy.pollButtons();

  if (arduboy.justPressed(LEFT_BUTTON) && selX > 0)
  {
    selX = selX - 1;
  }
  if (arduboy.justPressed(RIGHT_BUTTON) && selX < SIDE_LENGTH - 1)
  {
    selX = selX + 1;
  }
  if (arduboy.justPressed(UP_BUTTON) && selY > 0)
  {
    selY = selY - 1;
  }
  if (arduboy.justPressed(DOWN_BUTTON) && selY < SIDE_LENGTH - 1)
  {
    selY = selY + 1;
  }

  if (arduboy.justPressed(A_BUTTON))
  {
    squares[selX][selY] = player;
    changeTurn();
  }

  if (arduboy.justPressed(B_BUTTON))
  {
    squares[selX][selY] = EMPTY;
  }

  displayBoard();
}
