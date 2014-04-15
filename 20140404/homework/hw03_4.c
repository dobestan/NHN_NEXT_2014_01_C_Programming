#include <stdio.h>

#define BREAD 500
#define SNACK 700
#define DRINK 400

int get_current_money(void);

void print_options(int);
void print_options_recursive(int, int, int, int);

int main() {
  print_options_recursive(get_current_money()-(BREAD + SNACK + DRINK), 1, 1, 1);
  return 0;
}

int get_current_money(void) {
  int current_money = 0;
  printf("당신이 현재 가지고 있는 돈을 입력하세요 : ");
  scanf("%d", &current_money);
  return current_money;
}

void print_options(int money) {
  for ( int i = 1 ; i <= money / BREAD ; i++ ) {
    for ( int j = 1 ; j <= (money - i * BREAD) / SNACK ; j++) {
      for ( int k = 1 ; k <= (money - i * BREAD - j * SNACK) / DRINK ; k++ ) {
        if ( money == i*BREAD + j*SNACK + k*DRINK ) printf("BREAD(%d), SNACK(%d), DRINK(%d)\n", i , j, k );
      }
    }
  }
}

void print_options_recursive(int money, int bread, int snack, int drink) {
  // Usage : print_options_recursive(get_current_money()-(BREAD + SNACK + DRINK), 1, 1, 1);

  if ( money < 0 ) return;
  if ( money == 0 ) printf("BREAD(%d), SNACK(%d), DRINK(%d)\n", bread , snack, drink );

  print_options_recursive(money - BREAD, bread+1, snack, drink);
  print_options_recursive(money - SNACK, bread, snack+1, drink);
  print_options_recursive(money - DRINK, bread, snack, drink+1);
}








