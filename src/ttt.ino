#include <Arduboy.h>

Arduboy arduboy;

typedef char SquareVal;

#define SIDE_LENGTH 3
#define NUM_SQUARES (SIDE_LENGTH * SIDE_LENGTH)
#define EMPTY '.'
#define CROSS 'X'
#define NOUGHT 'O'

#define THINGO 20

SquareVal squares[NUM_SQUARES];

int selector = 0;

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(15);
  for (int i = 0; i < NUM_SQUARES; i++)
  {
    squares[i] = EMPTY;
  }
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
      if (pos == selector)
      {
        arduboy.drawRect(x, y, THINGO, THINGO, WHITE);
      }
      arduboy.print(squares[pos]);
    }
  }
  arduboy.display();
}

void loop()
{
  if (!(arduboy.nextFrame()))
    return;
  displayBoard();
}
