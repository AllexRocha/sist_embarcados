/*
  mon_key.cpp
*/

#include "Arduino.h"
#include "mon_key.h"

m_key::m_key()
{

}

int m_key::mn_key(uint8_t button, int *PS, int *ES){


    if (button){
      if(!(*PS)){
        *ES = 1;
        _delay_ms(20);
        *PS = 1;
      }
    } else{
        if (*PS){
        _delay_ms(20);
        *PS = 0;
        }
    }

    return *ES;
}

