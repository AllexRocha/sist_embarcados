/*
  mon_key.h
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