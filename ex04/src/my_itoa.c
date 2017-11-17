#include <stdlib.h>
#include <stdio.h>

char* my_itoa(int nmb){
  int base=10;
  int max_length=12;
  char* str=(char*)malloc(max_length);
  if(nmb==0){
    *str='0';
    *(str+1)='\0';
    return str;
  }
  int positive=(nmb < 0 ? -1 : 1);
  nmb=nmb*positive;
  int i=0;
  do{
    *(str+(i++))='0'+nmb%base;
    nmb/=base;
  }while(nmb);
  char* res=(char*)malloc(max_length);
  int j = 0;
  if(positive < 0){
   *res='-';
   j++;
  }
  *(res + (i--)) = '\0';
  for(;i>=0;i--,j++){
   *(res + j)=*(str + i);
  }
  free(str);
  return res;
}