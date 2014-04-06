#include <stdio.h>

#define bread 500
#define snack 700
#define drink 400

int get_current_money(void);
void print_options(int);

int main() {
  print_options(get_current_money());
  return 0;
}

int get_current_money(void) {
  int current_money = 0;
  printf("당신이 현재 가지고 있는 돈을 입력하세요 : ");
  scanf("%d", &current_money);
  return current_money;
}

void print_options(int money) {
  for ( int i = 1 ; i <= money / bread ; i++ ) {
    for ( int j = 1 ; j <= (money - i * bread) / snack ; j++) {
      for ( int k = 1 ; k <= (money - i * bread - j * snack) / drink ; k++ ) {
        if ( money == i*bread + j*snack + k*drink ) printf("BREAD(%d), SNACK(%d), DRINK(%d)\n", i , j, k );
      }
    }
  }
}
