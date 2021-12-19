#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
   char c; 
   int check = 0;   
   FILE *fp=fopen(argv[1],"r");
   
   if(fp==NULL)
   {
      printf("Failed to open the file"); 
   }
   else
   {
       
       while(c=fgetc(fp))
       {  
          if(c==EOF) break;
          while(c != '\n'){
              c=fgetc(fp);
              printf("%c",c);
              if(c==EOF) break;
          }

          check = check + 1;
          if(check%(atoi(argv[2])) == 0 && check != 0){
          printf("\n");
           }
          
          
       }
       fclose(fp);
       printf("Press any key to Exit\n");
       getchar();
   }
}
