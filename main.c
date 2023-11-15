#include "stdio.h"
#include "stdlib.h"
#include "data.h"
uint32_t i2cbff[MAXPIN];
int main(void)
{
  data_t *data = dataInit(0x32);
  update(data);
  for (int i = 0; i < MAXPIN; i++)
  {
    isButtonPressed(data, i);
    printf("%d", i);
    }

  int recvData = getValue(data);
  double temp = readFloat(data);
  printf("%d\n", recvData);
  printf("temp : %0.2f\n", temp);
  dataDeInit(data);

  int i = 10;
  int *pI = &i;
  printf("%d\n", i);
  *pI = 50;
  printf("%d\n", i);
  getchar();
  return 0;
}
