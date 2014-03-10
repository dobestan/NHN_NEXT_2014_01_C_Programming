#include <stdio.h>

int main() {
  int money = 0;
  int coins[2][8];

  // initialize coins[0]
  coins[0][0] = 50000;
  coins[0][1] = 10000;
  coins[0][2] =  5000;
  coins[0][3] =  1000;
  coins[0][4] =   500;
  coins[0][5] =   100;
  coins[0][6] =    50;
  coins[0][7] =    10;

  printf("Enter your money : ");
  int res = scanf("%d", &money);

  // EXEPTION CHECK
  if ( res != 1 ) {
    printf("ERROR : wrong input\n");
    return -1;
  }

  for (int i = 0 ; i < sizeof(coins[0])/sizeof(coins[0][0]) ; i++) {
    coins[1][i] = money / coins[0][i];
    money = money % coins[0][i];

    printf("%5d -> %2d\n", coins[0][i], coins[1][i]);
  }
  return 0;
}
