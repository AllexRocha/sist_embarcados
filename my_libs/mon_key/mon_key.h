/*
  mon_key.h - library for monitoring keys and bounce handling on push buttons on Arduino
  Author: Alex José Sousa da Rocha
  Date: 26/05/2024

*/

#ifndef mon_key
#define mon_key

#include "Arduino.h"

class m_key
{
  public:
      m_key();
      static int mn_key(uint8_t button, int *PS, int *ES);

};

#endif
