#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>

void copyPermission(const char* fromFile,const char* toFile){
     struct stat tmp;
     stat(fromFile,&tmp);
     chmod(toFile,tmp.st_mode);
}

int main(int argc, char **argv){
   struct dirent *dir1;    
   struct dirent *dir2; 
   int found,dst_fd,pid,n=0;
   struct stat st;
   int same = 1,num = 0,sum=1;
   char *ptr;
   int fd[2];
    int PROCESS_NUM = atoi(argv[3]);
    int pids[PROCESS_NUM];
    int pipes[PROCESS_NUM + 1][2];
    int i,s=0;
   
   //unsigned char buffer[4096];
   DIR *d=opendir(argv[1]);
   DIR *a=opendir(argv[2]);
   char* final = argv[2];
   char strDest[1024] = {0};
   int process[100];
   int pros[atoi(argv[3])];
    int numOfFork = log(strtod(argv[3],&ptr)+1.0)/log(2);
    int isParent = 1;

    int depth = 0; 
    
   
   
   
   if(d)
   {
    
     //seg
     

     
     //seg
     
      while((dir1=readdir(d)) != NULL)
       {  
       
        
       while((dir2=readdir(a)) != NULL)
       {  
        if(!strcmp(dir1->d_name,dir2->d_name)){
            found = 0;
            //printf("%s same as %s \n",dir1->d_name,dir2->d_name);
            break;
          }
          else{
              found=1; 
              //printf("%s not same %s \n",dir1->d_name,dir2->d_name);
          }
       }
       if(found){
                            
        
         stat(dir1->d_name,&st);
         if(S_ISDIR(st.st_mode)){
            continue;
            }
            else{
            
          //seg
            
          if(n < atoi(argv[3]) && isParent){
              pid = fork();
              pros[n] = getpid();
              
              //printf("PID in array %d and parent pid = %d \n", pros[n],getppid());
              n++;
              isParent = 0;    
              
       
            
           }
            if(pid > 0){
              isParent =1;
           } 
           
           //printf("\n");

            
            //seg   
            
                   if(pros[s] == getpid() && pid == 0){
                   //printf(" %d matching pid %d index %d, with 2nd pid %d\n",pros[s],pid,s,getpid());
                      s++;
                      //printf("shout out \n");
                   FILE* readfile = fopen(dir1->d_name,"r");
                   if(readfile != NULL){
                     sprintf(strDest,"%s/%s",argv[2],dir1->d_name);
                     FILE* writefile = fopen(strDest,"w");
                     if(writefile){
                       
                       char buffer[4096] = {0};
                       while(fgets(buffer,4096,readfile));
                       {
                              printf("Writting to file %s by process %d \n",dir1->d_name,getpid());
                              fputs(buffer,writefile);
                              same = 0;                            
                              
                              copyPermission(dir1->d_name,strDest);
                       }
                       fclose(writefile);
                     }
                     else{
                         printf("\n Unable to write file %s \n",strDest);
                     }
                     fclose(readfile);
                   } 
                   else
                   {
                      printf("\nFile could not be open for reading \n");
                   }
                   
                 

                   }
                   else
                   {
                     //break;
                     s++;
                     
                   }
                   
                   
                               
               //return 0;
               }

            }
            
               
               
               if(s >= atoi(argv[3])){
                      s = 0;
                   } 
                     
               rewinddir(a);
                             
            }

        
          
        // }

        // }
         
         

            
       
       
       
       
       closedir(d); 
       closedir(a);  
      }                   
         
   else
   {
       printf("Failed to open the directory");     
   }
   
   for(i=0; i<PROCESS_NUM; i++) {
        if(pid == 0) {  /* fork returns 0 in the child */
            write(fd[1], &i, 1);  /* write one byte into the pipe */
            depth += 1;
        }
    }
    close(fd[0]);
    close(fd[1]);  /* exercise for the reader to learn why this is needed */
    
    
 
   
}
