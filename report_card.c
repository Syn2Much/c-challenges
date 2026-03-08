//  Challenge: Student Grade Tracker                                                                                                         
                                                                                                                                            
//  You have a list of 6 students. Each student has a name, an array of 3 test scores (integers), and a letter grade.                        

//   1. Calculate each student's average score from their 3 tests
//   2. Assign a letter grade based on the average:
//     - 90+ = 'A'
//     - 80-89 = 'B'
//     - 70-79 = 'C'
//     - 60-69 = 'D'
//     - Below 60 = 'F'
//   3. Print a report showing each student's name, their 3 scores, average, and letter grade like:
//   Jake Miller | Scores: 92, 85, 88 | Avg: 88.33 | Grade: B
//   4. Find and print the student with the highest average and the student with the lowest average
//   5. Print the class average (average of all student averages)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct 
{
    char name[200];
    int scores[3];
    char grade;
} Student;

double getAverage(Student *student);
char calculateGrade(double average);
void printReport(Student students[], int count);

int main() {
    Student students_list[] = {
        {"Sam Hyde", {92, 80, 54}},
        {"Jake Miller", {85, 90, 88}},
        {"Emily Carter", {78, 82, 80}},
        {"Marcus Lee", {95, 91, 94}},
        {"Daniel Brooks", {88, 84, 86}},
        {"Sofia Ramirez", {67, 72, 70}}
    };

    int count = sizeof(students_list) / sizeof(students_list[0]);

    printReport(students_list, count);

    // find highest & lowest average
    int maxIdx = 0, minIdx = 0;
    for (int i = 1; i < count; i++) {
        if (getAverage(&students_list[i]) > getAverage(&students_list[maxIdx])) maxIdx = i;
        if (getAverage(&students_list[i]) < getAverage(&students_list[minIdx])) minIdx = i;
    }

    printf("\nHighest: %s (%.2f)\n", students_list[maxIdx].name, getAverage(&students_list[maxIdx]));
    printf("Lowest: %s (%.2f)\n", students_list[minIdx].name, getAverage(&students_list[minIdx]));

    // class average
    double classAvg = 0;
    for (int i = 0; i < count; i++) {
        classAvg += getAverage(&students_list[i]);
    }
    classAvg /= count;
    printf("Class Average: %.2f\n", classAvg);

    return 0;
}

double getAverage(Student *student) {
    int count = sizeof(student->scores) / sizeof(student->scores[0]);
    int holder = 0;
    for (int i = 0; i < count; i++) {
        holder += student->scores[i];
    }
    return (double)holder / count;
}

char calculateGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

void printReport(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        double avg = getAverage(&students[i]);
        students[i].grade = calculateGrade(avg);
        printf("%s | Scores: %d, %d, %d | Avg: %.2f | Grade: %c\n",
            students[i].name,
            students[i].scores[0], students[i].scores[1], students[i].scores[2],
            avg, students[i].grade);
    }
}
