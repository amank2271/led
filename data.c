#include "data.h"
#define OFF 0
#define ON 1
struct data_tag
{
  int addr;
  int prevstate : 1;
  int currentstate : 1;
  uint8_t inT;
  uint8_t swiTch;
  uint32_t dataBuffer[MAXPIN];
  uint32_t lastButtonState[MAXPIN];
  union data_union
  {
    float temp;
  } u;
};

data_t *dataInit(int address)
{
  data_t *pConfig = malloc(sizeof(data_t));
  pConfig->addr = address;
  return pConfig;
}

uint32_t isButtonPressed(data_t *pConfig, int buttonId)
{
  if (pConfig->lastButtonState[buttonId] == OFF)
  {
    if (pConfig->dataBuffer[buttonId] != ON)
    {
      pConfig->lastButtonState[buttonId] = ON;
    }
  }
  return pConfig->lastButtonState;
}
void update(data_t *pConfig)
{
  for (int i = 0; i < MAXPIN; i++)
  {
    pConfig->lastButtonState[i] = 0;
  }
}

int getValue(data_t *pConfig)
{
  return pConfig->addr;
}

double readFloat(data_t *pConfig)
{
  return pConfig->u.temp / 1.75;
}

void dataDeInit(data_t *pConfig)
{
  free(pConfig);
}