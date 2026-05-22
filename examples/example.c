#include <stdio.h>

int main() {
  // Write age here
  // Write an if statement that checks if age >= 18
  // If true, print "Allowed" inside the if block
  // Write an else statement
  // Inside the else block, print "Not allowed"
  int age = 23; 

  if (age >= 18) {
    printf("Allowed\n");
  } else {
    printf("Not allowed\n");
  }

  //ternary operator
  // (condition) ? (value if true) : (value if false)
  (age >= 18) ? printf("Allowed\n") : printf("Not allowed\n");

  int choice = 1;

  // 1 = Coffee
  // 2 = Tea

  switch (choice) {
    case 1:
      printf("You ordered Coffee");
      break;

    case 2:
      printf("You ordered Tea");
      break;
    
    default:
      printf("Invalid choice");
  }


  
  return 0;
}