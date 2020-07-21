#include <stdio.h>
#include<string.h>


void main()
{
   FILE *fp;
   char c,d;
   int m_c=0,s_c=0;
   fp=(FILE *)fopen("cmttest.txt","r");
   if (fp == NULL){
        printf("Could not open file.");

    }

   while ((c=getc(fp))!=EOF)
   {
     
      if(c=='/')
         {
               if((c=getc(fp))=='/')
               {
               s_c++;
               }
         }
      
   }
   rewind(fp);
   while ((c=getc(fp))!=EOF)
   {
      
      if(c=='/')
         {
               if((c=getc(fp))=='*')
               {
                 
                  while ((c=getc(fp))!=EOF)
                    if(c=='*')
                       {
                          if((c=getc(fp)=='/'))
                          {
                        
                             m_c++;
                          }
                       }
               }
         }


   }
   printf("\nTotal single comment lines are %d",s_c);
   printf("\nTotal Multi comment lines are %d",m_c);
   
   
   fclose(fp);
   
   
   

}
