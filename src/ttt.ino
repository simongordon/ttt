#include <Arduboy.h>

Arduboy arduboy;

typedef char SQUARE_VAL;

#define NUM_SQUARES 9
#define EMPTY ' '
#define CROSS 'X'
#define NOUGHT 'O'

int squares[NUM_SQUARES];

int selector = 0;

void setup()
{
  arduboy.begin();
  arduboy.clear();
  for (int i = 0; i < NUM_SQUARES; i++)
  {
    squares[i] = EMPTY;
  }
}

void loop()
{
}
