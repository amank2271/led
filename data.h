#ifndef __DATA_H
#define __DATA_H
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#define MAXPIN 10

typedef struct data_tag data_t;

data_t *dataInit(int i);
void update(data_t *pConfig);
int getValue(data_t *pConfig);
double readFloat(data_t *pConfig);
uint32_t isButtonPressed(data_t *pConfig, int buttonId);
void dataDeInit(data_t *pConfig);

#endif