#include <stdio.h>
#define MAXLINE 1024
void main( void )
{
	FILE *fpin; // входной файл
	FILE *fpout; // выходной файл
	char line[100][MAXLINE]; // текущая строка
	char *ptr;
	int lineNum = 0;
	int massLineNum[100];
	char* lines[MAXLINE];
	char* begin;
	char* linebuf;
	int i, j;
	int buf;
    int noSwap = 1;
	fpin = fopen( "vvod.txt", "rt" ); // открыть файл для чтения
	if( fpin == NULL )
		return; // ошибка при открытии файла
	fpout = fopen("vivod.txt", "wt" ); // открыть файл для записи
	if( fpout == NULL )
		return; // ошибка при открытии файла
	while( !feof( fpin ) )// цикл до конца входного файла
	{
		i = 0;
		ptr = fgets( line[lineNum+1], MAXLINE, fpin ); // чтение строки
		if( ptr == NULL )
			break; // файл исчерпан
		lineNum++;
		while( *ptr != '\0' ) // цикл до конца строки
		{
			i++;
			ptr++; // продвигаем указатель по строке
		}
		massLineNum[lineNum] = i;
		lines[lineNum] = line[lineNum];
	};
    for (i = lineNum - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (j = 1; j <= i; j++)
        {
            if (massLineNum[j] > massLineNum[j + 1])
            {
                buf = massLineNum[j];
                massLineNum[j] = massLineNum[j + 1];
                massLineNum[j + 1] = buf;
				linebuf = lines[j];
				lines[j] = lines[j + 1];
				lines[j + 1] = linebuf;
                noSwap = 0;
            }
        };
        if (noSwap == 1)
            break;
    };
	for(i=1;i<=lineNum;i++)
	{
		fputs((lines[i]), fpout );
	};
	fclose( fpin ); // закрыть входной файл
	fclose( fpout ); // закрыть выходной файл
}