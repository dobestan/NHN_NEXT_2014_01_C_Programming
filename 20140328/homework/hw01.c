#include <stdio.h>

int is_lunar_year(int year);
int get_integer_from_user_input(char * string);
int validate_date(void);
void print_validation_result(int validate_date);

int main() {
  char user_input_char = 0;
  while ( 1 ) {
    printf("---MENU---\n");
    printf("c. continue\n");
    printf("q. quit\n");

    printf("enter a menu : ");
    fflush(stdin);
    scanf("%s", &user_input_char);
    printf("\n");

    switch ( user_input_char ) {
      case 'c' :
        printf("날짜 검증을 시작합니다...\n");
        print_validation_result(validate_date());
        break;
      case 'q' :
        printf("프로그램을 종료합니다...\n");
        return 0;
      default :
        printf("오류 : c 또는 p를 입력하세요.\n");
        break;
    }
  }
}

int get_integer_from_user_input(char * string) {
  int user_input = 0;
  printf("%s", string);
  fflush(stdin);
  scanf("%d", &user_input);
  return user_input;
}

int is_lunar_year(int year) {
  int is_lunar_year = 0; // default : false

  if ( year%4 == 0 ) {
    if ( year%100 == 0 ) {
      if ( year%400 == 0 ) {
        is_lunar_year = 1;
      }
      is_lunar_year = 0;
    }
    is_lunar_year = 1;
  }

  return is_lunar_year;
}

int validate_date(void) {
  int year = 0;
  int month = 0;
  int day = 0;

  int day_of_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  int is_valid = 1; // default = true

  year = get_integer_from_user_input("YEAR ( YYYY ) = ");
  month = get_integer_from_user_input("MONTH ( MM ) = ");
  day = get_integer_from_user_input("DAY ( DD ) = ");

  day_of_month[1] += is_lunar_year(year);

  if ( month < 1 || month > 12 ) { is_valid = 0; } // validate month
  if ( day < 1 || day > day_of_month[month-1] ) { is_valid = 0; } // validate day

  return is_valid;
}

void print_validation_result(int validate_date) {
  char * msg = validate_date ? "true" : "false";
  printf("*** validation result : %s ***\n\n", msg);
  return;
}
