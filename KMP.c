#include<stdio.h>
#include<string.h>
char txt[100],pat[100];
int M ,N ,lps[100],j=0,i=0;
void Array()
{
  int len = 0, i;
  lps[0] = 0;
  i = 1;
  while(i < M)
  {
   if(pat[i] == pat[len])
   {
   len++;
   lps[i] = len;
   i++;
   }
   else
   {
   if( len != 0 )
     len = lps[len-1];
   else
   {
     lps[i] = 0;
     i++;
   }
   }
  }
}
void KMPsearch()
{
  int j=0,i=0;
  M = strlen(pat);
  N = strlen(txt);
  Array();
  while(i < N)
  {
  if(pat[j] == txt[i])
  {
    j++;
    i++;
  }
  if (j == M)
  {
    printf("Found pattern at index %d \n", i-j);
    j = lps[j-1];
  }
  else if(pat[j] != txt[i])
  {
    if(j != 0)
   j = lps[j-1];
    else
   i = i+1;
  }
  }
}
int main()
{
 printf("\n ENTER THE TEXT    : ");
 gets(txt);
 printf("\n ENTER THE PATTERN : ");
 gets(pat);
 KMPsearch();
 return 0;
}
