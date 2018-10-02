#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512
int see_more();
void do_more( FILE * fp );
int main(int ac, char **av)
{
	FILE * fp;
	if( ac == 1 ) {
		do_more(stdin);
	} 
	else {
		while(--ac);
		if((fp = fopen(*++av,"r")) != NULL)
		{
			do_more(fp);
			fclose( fp );
		}
		else
			exit(1);
		return 0;
	}

	
	return 0;
}

void do_more( FILE * fp )
{
	char line[LINELEN];
	int num_of_line = 0;
	int reply;
	while( fgets( line,LINELEN,fp ) ) {
		if( num_of_line == PAGELEN ) {
			reply = see_more();
			if ( reply == 0 ) {
				break;
			}
			num_of_line -= reply; 
		}
		if( fputs( line,stdout ) == EOF ) {
			exit(1); 
		}
		num_of_line++;
	}
}

int see_more()
{
	int c;
	printf("             ");
	while((c=getchar()) != EOF ) {
		if( c == 'q')
		return 0;
		if(c==' ')
		return PAGELEN;
		if(c=='\n')
		return 1;
	}
	return 0;
}
