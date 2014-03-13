int get_age() {
  int age = 0;
  printf("Enter your age : ");
  scanf("%d", &age);
  return age;
}

void print_age(int age) {
  printf("Your age is ... %d\n", age);
  return;
}
