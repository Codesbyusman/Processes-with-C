/*

    ----------------------------------------------------
    ------------ Muhammad Usman Shahid -----------------
    -------------------- 20I-1797 ----------------------
    ------------------------ T -------------------------
    ----------------------------------------------------

*/

#include <stdio.h>
#include <unistd.h> //maintaining standards
#include <sys/wait.h>
#include <sys/types.h> //pid_t  creation
#include <stdlib.h>    //memory allocation
#include <errno.h>
#include <string.h>

void main(int argc, char *agrv[], char *env[])
{

    char *arg1;
    char *arg2;
    char *arg3; // for storing the 3 paths required

   printf("\n\t\t The environmental variables by c file \n\n");

    // checking for the whole enc=vironmental variables and will then print the needed using substring
    for (int i = 0; env[i] != NULL; i++)
    {
        // checking for the variables and then printing and saving accordingly
        if (strstr(env[i], "PATH=/") || strstr(env[i], "USER=") || strstr(env[i], "TERM=x"))
        {
            printf("\n%s", env[i]); // pinting the variables

            // saving variables
            if (strstr(env[i], "PATH=/"))
            {
                arg1 = env[i]; // saving the path
                // strcpy(arg1, env[i]);
                
            }
            else if (strstr(env[i], "USER="))
            {
                arg2 = env[i]; // saving the user
            }
            else if (strstr(env[i], "TERM=x"))
            {
                arg3 = env[i]; // saving the term
            }
        }
    }


   

    printf("\n\n");



    //for passing in the execve
    char * vectorArg[] = {"script.sh", arg1, arg2, arg3 , NULL};

    //passing the os2022 and canging the value of user and path and will see changed in script file
    char * vectorEnv[] = { "OS2022=5ma32zw","USER=MuhammadUsman", "PATH=/bin/usman", NULL};

    execve("./q8.sh",vectorArg, vectorEnv ); 

}
 