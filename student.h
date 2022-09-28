#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 15
#define AMOUNT_OF_GRADES 3
#define MAX_NAME_LEN 50

typedef struct {
  int registration;
  char name[MAX_NAME_LEN];
  float grades[AMOUNT_OF_GRADES];
  int has_grade[AMOUNT_OF_GRADES];
  float average_grade;
  int has_average_grade;
} student;

student create_new_student();
void show_student_status(student *class_student, int show_title);
void show_class_status(student *classroom, int class_size);
void print_student(student *class_student);
void set_student_grade(student *new_student);
student *get_student_by_registration(student *classroom, int class_size);
student *get_student_by_name(student *classroom, int class_size);

#endif
