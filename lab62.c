#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
int pid;
struct timeval curTime;
printf("The PID of the proccess is: %d \n \n",getpid())
pid = fork();

if(pid == 0){
       gettimeofday(&curTime, NULL);
       int milli = curTime.tv_usec / 1000;
       char buffer [80];
       strftime(buffer, 80, "%H:%M:%S", localtime(&curTime.tv_sec));
       char currentTime[84] = "";
       sprintf(currentTime, "%s:%03d", buffer, milli);
       printf("\n current time for child proccess 1: %s \n", currentTime);
       printf("The PID of child proccess 1 is: %d \n",getpid());
       printf("The PID of Parent proccess is: %d \n \n",getppid());
}
else{
    
    pid = fork();
    if(pid == 0){
       gettimeofday(&curTime, NULL);
       int milli = curTime.tv_usec / 1000;
       char buffer [80];
       strftime(buffer, 80, "%H:%M:%S", localtime(&curTime.tv_sec));
       char currentTime[84] = "";
       sprintf(currentTime, "%s:%03d", buffer, milli);
       printf("current time for child proccess 2: %s \n", currentTime);
       printf("The PID of child proccess 2 is: %d \n",getpid());
       printf("The PID of Parent proccess is: %d \n",getppid());
    }
    system("ps -x");
  
}

}
