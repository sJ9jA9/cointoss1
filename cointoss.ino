//Marcus L. Sanders II
//Coin Toss Main
//8.6.2020

#include <Arduboy2.h>
#include "PerosaFont3x5.h"
#include "Coin.h"
#include "Display.h"

Arduboy2 arduboy;
PerosaFont3x5 font3x5;

void setup()
{
  arduboy.begin();
  Arduboy2::generateRandomSeed();
  arduboy.setFrameRate(60);
  arduboy.pollButtons();
}

void loop()
{
  //prevents arduboy from running too fast
  if (!arduboy.nextFrame())
    return;

  uint8_t gamestate = 0;

  arduboy.clear();

  //to change screens
  switch (gamestate)
  {
    case 0:
      //title screen
      displayTitle();
      if (arduboy.justPressed(A_BUTTON))
        gamestate = 1;
      break;
    case 1:
      //gameplay screen
      displayCoinFrames();
      displayQuestionsPrompt();
      drawScoreboard();
      displayUIBorder();
      if (arduboy.justPressed(A_BUTTON))
        gamestate = 2;
      break;
    case 2:
      //special thank you screen
      font3x5.setCursor(0, 0);
      font3x5.print("WORK IN PROGRESS");
      if (arduboy.justPressed(A_BUTTON))
        gamestate = 0;
      break;
  }

  arduboy.display();
}
