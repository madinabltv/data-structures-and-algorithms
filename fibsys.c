#include <stdio.h>

main()
{
    unsigned long  x,b,a,c;
    unsigned long long i=0,j,s=0,n=0;

    scanf("%ld", &x);
    if (x == 0) 
        printf("%c\n", '0');
    else
    { 
        while(x>0)
	{ 
	    ++i;
            c=0;
            b=1;
            j=0;
            while (c<=x)
            {  
	        if (c>0) a=c;
                else a=1;
                
                if ((c+b) <=x)
		{
                	++j;
                	c+=b;
                	b=a;
                } else break;
                 
	    }
            
	    if (i==1) 
	    {
	        s=j;
                printf("%c", '1');
	    }
            else 
	    {
	        for (n=1;n<(s-j);++n)
	            printf("%c", '0');
                s=j;
                printf("%c", '1');
            }
 
            x -=c;  
           
        }   
        
    if ( j>1)
        for ( n=0; n<(j-1); ++n)
	    printf("%c",'0');
    printf("\n");    
            
    } 

	return 0;
}
