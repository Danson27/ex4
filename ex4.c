
/******************
Name: Dan Sonnenblick
ID: 345287882
Assignment: ex4
*******************/
#include <stdio.h>
#include <string.h>

#define COLUMN 5
#define ROW 5
void printMenu();
int task1_robot_paths(int c, int r);
float task2_human_pyramid(float arr[][ROW], float set[][COLUMN], int c, int r);
int task3_parenthesis_validator(int starter);
int getTerm(int ch);
void clearBuffer();
void task4_queens_battle();
void task5_crossword_generator();



int main() {
    int choice;

    printMenu();
    scanf("%d", &choice);
    while(choice != 6) {
        switch(choice) {
            case 1: {
                int sum = 0;
                int column, row;
                printf("Please enter the coordinates of the robot (column, row): \n");
                scanf("%d %d", &column, &row);
                if (column < 0 || row < 0)
                    printf("The total number of paths the robot can take to reach home is: 0\n");
                sum += task1_robot_paths(column, row);
                printf("The total number of paths the robot can take to reach home is: %d \n", sum);
                break;
            }


            case 2: {
                float weights[ROW][COLUMN] = {0};
                printf("Please enter the weights of the cheerleaders:\n");
                for (int r = 0; r < ROW; r++) {
                    for (int c = 0; c <= r; c++) {
                        scanf("%f", &weights[r][c]);
                        if (weights[r][c] < 0) {
                            printf("Negative weights are not supported. \n");
                            break;
                        }
                    }
                }


                float set [ROW][COLUMN] = {0};

                for (int c = 0; c <= COLUMN; c++) {
                    task2_human_pyramid(weights, set, ROW-1, c);
                }


                for (int r = 0; r < ROW; r++) {
                    for (int c = 0; c <= r; c++) {
                        printf("%.2f ", set[r][c]);
                    }
                    printf("\n");
                }
                break;
            }



            case 3: {
                char ch;
                printf("Please enter a term for validation: \n");
                clearBuffer();
                scanf("%c", &ch);
                if (getTerm(ch))
                    printf("The parentheses are balanced correctly. \n");
                else
                    printf("The parentheses are not balanced correctly. \n");
                break;
            }
            case 4: {
                task4_queens_battle();
                break;
            }
            case 5: {
                task5_crossword_generator();
                break;
            }
            case 6: {
                printf("Goodbye!\n");
                break;
            }
            default:
                printf("Please choose a task number from the list.\n");
        }
        printMenu();
        scanf("%d", &choice);
    }
}


int task1_robot_paths(int c, int r)
{
   int sum = 0;
   if (c ==0 || r == 0)
       return 1;
   sum += (task1_robot_paths (c-1, r) + task1_robot_paths (c, r-1));
   return sum;


}


float task2_human_pyramid(float arr[ROW][COLUMN], float set[][COLUMN], int row, int col) {
    if (row == 0 && col == 0)
        return set[0][0] = arr[0][0];
    if (col < 0 || col > row)
        return 0;

    if (set[row][col] != 0)
        return set[row][col];
    float left = task2_human_pyramid(arr, set, row - 1, col - 1)/2;
    float right = task2_human_pyramid(arr, set, row - 1, col)/2;
    set[row][col] = arr[row][col]+left+right;
    return set[row][col];
}


int getTerm(int ch) {
    if (ch == '\n')
        return 1;
    if (ch == '('
        || ch == '['
        || ch == '<'
        || ch == '{') {
        if (!task3_parenthesis_validator(ch))
            return 0;
        }
    if (ch == ')'
        || ch == ']'
        || ch == '>'
        || ch == '}') {
        return 0;
        }
    /*ch = getchar();
    if (ch == '\n')
        return 0;
    getTerm(ch);*/
    return getTerm(getchar());
}
int task3_parenthesis_validator(int starter) {
    int closer = getchar();
    printf("starter = %d closer = %d\n", starter, closer);
    if (closer == '\n')
        return 0;
    if (closer == '(' || closer == '[' || closer == '{' || closer == '<') {
        if (!task3_parenthesis_validator(closer))
        return 0;
    }
    if (closer == ')' || closer == ']' || closer == '}' || closer == '>') {
        if ((starter == '(' && closer == ')') ||
            (starter == '[' && closer == ']') ||
            (starter == '<' && closer == '>') ||
            (starter == '{' && closer == '}')) {
            return 1;
            }
        printf("Mismatch: starter = %c closer = %c\n", starter, closer);
        return 0; // Invalid match
    }
    return task3_parenthesis_validator(starter);
}



void task4_queens_battle()
{
   // Todo
}


void task5_crossword_generator()
{
   // Todo
}

void clearBuffer() {
    while (getchar() != '\n');
}
void printMenu() {
    printf("Choose an option:\n"
              "1. Robot Paths\n"
              "2. The Human Pyramid\n"
              "3. Parenthesis Validation\n"
              "4. Queens Battle\n"
              "5. Crossword Generator\n"
              "6. Exit\n");
}




