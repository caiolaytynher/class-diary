#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_table_division() {
  int line_size = 100;
  for (int i = 0; i < line_size; i++)
    printf("=");

  printf("\n");
}

void get_student_name(char *name) {
  char input_name[MAX_NAME_LEN];

  fgetc(stdin);
  fgets(input_name, MAX_NAME_LEN, stdin);
  input_name[strlen(input_name) - 1] = 0;

  strcpy(name, input_name);
}

void register_new_student(student *new_student) {
  int registration;

  printf("New student registration:\n");
  printf("Registration number: ");
  scanf("%d", &registration);
  new_student->registration = registration;

  printf("Name: ");
  get_student_name(new_student->name);

  for (int i = 0; i < AMOUNT_OF_GRADES; i++)
    new_student->has_grade[i] = 0;

  new_student->next = NULL;
}

void deallocate_class(student *classroom) {
  while (classroom != NULL) {
    student *tmp = classroom->next;
    free(classroom);
    classroom = tmp;
  }
}

void show_student_status(student *class_student, int show_title) {
  if (show_title) {
    print_table_division();
    printf("Registration\tName\t\tGrade1\tGrade2\tGrade3\tAverage\tStatus\n");
    print_table_division();
  }

  printf("%d\t%s\t", class_student->registration, class_student->name);

  for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
    if (class_student->has_grade[i])
      printf("%.1f\t", class_student->grades[i]);
    else
      printf("NaN\t");
  }

  if (class_student->has_average_grade) {
    printf("%.1f\t", class_student->average_grade);

    if (class_student->average_grade >= 7)
      printf("Passed by average\n");
    else if (class_student->average_grade >= 5)
      printf("Passed by final exam\n");
    else
      printf("Failed\n");
  } else
    printf("NaN\tHas grades missing\n");

  print_table_division();
}

void show_class_status(student *classroom) {
  float total_grade[AMOUNT_OF_GRADES];
  for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
    total_grade[i] = 0.0f;
  }

  int amount_of_grade[AMOUNT_OF_GRADES];
  for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
    amount_of_grade[i] = 0;
  }

  float total_average_grade = 0.0f;
  int amount_of_average_grade = 0;

  for (student *s = classroom; s != NULL; s = s->next) {
    if (s == classroom)
      show_student_status(s, 1);
    else
      show_student_status(s, 0);

    for (int j = 0; j < AMOUNT_OF_GRADES; j++) {
      if (s->has_grade[j]) {
        total_grade[j] += s->grades[j];
        amount_of_grade[j]++;
      }
    }

    if (s->has_average_grade) {
      total_average_grade += s->average_grade;
      amount_of_average_grade++;
    }
  }

  printf("Class average grade\t\t");
  for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
    if (amount_of_grade[i] == 0)
      printf("NaN\t");
    else
      printf("%.1f\t", total_grade[i] / amount_of_grade[i]);
  }

  if (amount_of_average_grade == 0)
    printf("NaN\n");
  else
    printf("%.1f\n", total_average_grade / amount_of_average_grade);

  print_table_division();
}

void print_student(student *class_student) {
  printf("Registration: %d\n", class_student->registration);
  printf("Name: %s\n", class_student->name);

  for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
    if (class_student->has_grade[i])
      printf("Grade %d: %.2f\n", i + 1, class_student->grades[i]);
  }

  if (class_student->has_average_grade)
    printf("Average grade: %.2f\n", class_student->average_grade);
}

void set_student_grade(student *class_student) {
  int grade_position;
  float grade_value;

  printf("Which grade do you wanna register?: ");
  while (1) {
    scanf("%d", &grade_position);
    if (grade_position > 0 && grade_position < 4)
      break;

    printf("Not a valid grade number, there is only 3 grades. ");
    printf("Please try again.\n");
  }

  while (1) {
    printf("Grade %d value: ", grade_position);
    scanf("%f", &grade_value);

    if (grade_value >= 0 && grade_value <= 10)
      break;

    printf("The grades must be between 0.0 and 10.0. ");
    printf("Please try again.\n");
  }

  class_student->grades[grade_position - 1] = grade_value;
  class_student->has_grade[grade_position - 1] = 1;

  int has_all_grades = 1;
  for (int i = 0; i < AMOUNT_OF_GRADES; i++) {
    if (!class_student->has_grade[i])
      has_all_grades = 0;
  }

  if (has_all_grades) {
    float sum = 0.0f;
    for (int i = 0; i < AMOUNT_OF_GRADES; i++)
      sum += class_student->grades[i];

    class_student->average_grade = sum / 3;
    class_student->has_average_grade = 1;
  }
}

student *get_student_by_registration(student *classroom) {
  int registration;
  printf("Registration: ");
  scanf("%d", &registration);
  for (student *s = classroom; s != NULL; s = s->next) {
    if (s->registration == registration)
      return s;
  }

  return NULL;
}

student *get_student_by_name(student *classroom) {
  char name[MAX_NAME_LEN];
  printf("Name: ");
  get_student_name(name);
  for (student *s = classroom; s != NULL; s = s->next) {
    if (strcmp(s->name, name) == 0)
      return s;
  }

  return NULL;
}
