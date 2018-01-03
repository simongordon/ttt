#include <Arduboy.h>

Arduboy arduboy;

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

  if (arduboy.pressed(LEFT_BUTTON))
  {
    selX = selX - 1;
  }
  if (arduboy.pressed(RIGHT_BUTTON))
  {
    selX = selX + 1;
  }
  if (arduboy.pressed(UP_BUTTON))
  {
    selY = selY - 1;
  }
  if (arduboy.pressed(DOWN_BUTTON))
  {
    selY = selY + 1;
  }

  displayBoard();
}
