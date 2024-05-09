#include <stdio.h>

struct Student {
    char name[50];
    int marks;
    char class[20];
};

int main() {
  struct Student students[1];
  
  printf("Enter details of 10 students:\n");
  for (int i = 0; i < 1; ++i) {
    printf("Student %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Marks: ");
    scanf("%d", &students[i].marks);
    printf("Class: ");
    scanf("%s", students[i].class);
  }

  FILE *file = fopen("students.txt", "w");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
    
  for (int i = 0; i < 1; ++i) {
    fprintf(file, "%s %d %s\n", students[i].name, students[i].marks, students[i].class);
  }
  fclose(file);

  printf("\nContent of students.txt:\n");
  file = fopen("students.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  char name[50], class[20];
  int marks;
  while (fscanf(file, "%s %d %s", name, &marks, class) != EOF) {
    printf("Name: %s, Marks: %d, Class: %s\n", name, marks, class);
  }
  fclose(file);

  return 0;
}