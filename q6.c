/*

    ----------------------------------------------------
    ------------ Muhammad Usman Shahid -----------------
    -------------------- 20I-1797 ----------------------
    ------------------------ T -------------------------
    ----------------------------------------------------

*/

#include <stdio.h>
#include <unistd.h>   //maintaining standards
#include <sys/wait.h> //pid_t  creation
#include <stdlib.h>   //memory allocation

void main()
{
    // variables
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;                 // for taking input from the user
    int firstResponse = 0, secondResponse = 0, thirdResponse = 0; // for storing the results by process childs
    int X = 0;                                                    // the result

    // taking the input in a , b , c from the user
    printf("\n\n \t Enter the value of a : ");
    scanf("%d", &a);

    printf(" \t Enter the value of b : ");
    scanf("%d", &b);

    printf(" \t Enter the value of c : ");
    scanf("%d", &c);

    printf(" \t Enter the value of d : ");
    scanf("%d", &d);

    printf(" \t Enter the value of e : ");
    scanf("%d", &e);

    printf(" \t Enter the value of f : ");
    scanf("%d", &f);

    // the main parent process
    // creating the first child for the parent
    pid_t firstChild = fork(); /// created the child to perform a*b

    if (firstChild >= 0) // checking whther child made or not
    {
        if (firstChild == 0)
        {
            // the first child doing a*b
            exit(a * b);
        }
        else
        {
            // parent waiting the result from the firstchild
            wait(&firstResponse);

            // to map in the range as can exit between 0 to 255 thus deviding by 255
            firstResponse /= 255;

            // making the other child processes and getting their response
            pid_t secondChild = fork(); // the second child made

            if (secondChild >= 0) // checking whther child made or not
            {
                if (secondChild == 0)
                {
                    // the first child doing c/d
                    exit(c / d);
                }
                else
                {
                    // parent waiting the result from the secondchild
                    wait(&secondResponse);

                    // to map in the range as can exit between 0 to 255 thus deviding by 255
                    secondResponse /= 255;

                    // making the other child processes and getting their response
                    pid_t thirdChild = fork(); // the third child made

                    if (thirdChild >= 0) // checking whther child made or not
                    {
                        if (thirdChild == 0)
                        {
                            // the first child doing c/d
                            exit(e - f);
                        }
                        else
                        {
                            // parent waiting the result from the thirdchild
                            wait(&thirdResponse);

                            // to map in the range as can exit between 0 to 255 thus deviding by 255
                            thirdResponse /= 255;
                        }
                    }
                    else
                    {
                        // if unable to make the child
                        printf("\n\t\t Can't make the child processes --- error \n\n");
                    }
                }
            }
            else
            {
                // if unable to make the child
                printf("\n\t\t Can't make the child processes --- error \n\n");
            }
        }

        // mow adding all the responses in final result
        X = firstResponse + secondResponse + thirdResponse;

        printf("\n\n\t The result of expression ( (a*b) + (c/d) + (e-f) ) = %d", X);
        printf("\n\n");
    }
    else
    {
        // if unable to make the child
        printf("\n\t\t Can't make the child processes --- error \n\n");
    }
}
 