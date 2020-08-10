//Marcus L. Sanders II
//Coin .h
//8.8.2020

#ifndef COIN_H
#define COIN_H

class Coin
{
  private:
  //
    uint8_t coinValue;
  public:
    void Coin::flip()
    {
      coinValue = random(0, 2);
    }

    //coin value getter
    uint8_t Coin::getCoinValue()
    {
      return coinValue;
    }
};

#endif
