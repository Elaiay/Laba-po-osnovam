#include <stdio.h>

#define NO 0
#define YES 1



void process_line( char buff[], char prfx[] );

void main( void )

{
char prfx[1000];
char line[1000];
printf("Enter prifix: ");
fgets(prfx,sizeof(prfx),stdin);
printf("Enter line:" );
fgets(line,sizeof(line),stdin);
process_line( line, prfx );
puts( line );
getchar();

}

void process_line( char buff[], char prfx[] )

{

char c;
int flag;
int found;
char *begin, *end, *buff_ptr, *prfx_ptr;
char *start;
flag = NO;
found = NO;
begin = buff;
end = buff;
start = buff;
buff_ptr = buff;
prfx_ptr = prfx;
do
{
	c = *buff_ptr;
	if ( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' )
	{
		start = begin;
		while(( *prfx_ptr != '\0' ) && ( *prfx_ptr != ' ')){
			if ( *start == *prfx_ptr )
				found = YES;
			else
			{
				found = NO;
				break;
			}
		start++;
		prfx++;
		}
		prfx_ptr = prfx;
		if ( flag == YES )
		{
			// найден первый разделитель после слова
			end = buff_ptr - 1; // запомнить позицию конца слова
			if ( found == YES)
			{
				// удаление слова
				char *src = end + 1;
				char *dst = begin;
				while( (*dst++ = *src++ ) != '\0' );
				buff_ptr = begin;
			}
		}
		flag = NO;
	}
	else
	{
		// найдена буква
		if ( flag == NO )
			begin = buff_ptr; // запомнить позицию начала слова
		flag = YES;
	}
	buff_ptr++;
}

while ( c != '\0' );

}
