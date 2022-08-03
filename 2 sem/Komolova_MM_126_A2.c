#include <string.h>
#include <stdio.h>
int main(void)
{
 char s[257];
 int i,m=0,ln,k=0;
 printf("Stroka:\n");
 fgets(s, 257, stdin);
ln=strlen(s);
for(i=0; i<ln; ++i)
    if(s[i] == ':')
    {k = i+1;
    break;
    }
for(i=k; i<ln; ++i)
    if(s[i] == ':')
        {m = i;
        break;
        }
if (m > k) for (i=k; i<m; ++i) putc(s[i], stdout);
return 0;
}
