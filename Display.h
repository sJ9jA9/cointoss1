//Marcus L. Sanders II
//Coin Toss Display
//8.6.2020

#ifndef DISPLAY_H
#define DISPLAY_H

#include "Bitmap.h"


//constants defining the first and last frames of coinFrames
constexpr uint8_t firstCoinFrame = 0;
//0 - 11 is the coin flipping
//12 - 14 is diffent coin faces
constexpr uint8_t lastCoinFrame = 14;

//variable for tracking the current coinFrame... well frame
uint8_t currentCoinFrame = 0;

//variable for tracking the current loop of the animation
uint8_t coinFlipLoop = 0;

//whether coinFrame should be in a animation loop or not
bool coinAnimationEnabled = false;

//coin flip animation function
void coinFlipAnimation()
{
  // If the current frame index is less than the last frame
  if (currentCoinFrame < 11)
  {
    // Increase the frame index
    ++currentCoinFrame;
  }
  // Otherwise
  else
  {
    // Reset the animation
    currentCoinFrame = firstCoinFrame;

    //increases animationLoop's value
    coinFlipLoop++;

    //once animationLoop reaches 3 it ends the animaition
    if (coinFlipLoop == 3)
      coinAnimationEnabled = false;
  }
}

void displayCoinFrames()
{
  Sprites::drawOverwrite(4, 4, coinFrames, currentCoinFrame);
}

void displayQuestionsPrompt()
{
  Sprites::drawOverwrite(67, 28, questionsPrompt, 0);
}

void drawScoreboard()
{
  Sprites::drawSelfMasked(68, 1, scoreboard, 0);
}

void displayScoreboardDot()
{
}

void displayUIBorder()
{
  Sprites::drawSelfMasked(64, 0, uiBorder, 0);
}

void displayTitle()
{
  Sprites::drawOverwrite(1, 1, gameTitle, 0);
}

#endif
