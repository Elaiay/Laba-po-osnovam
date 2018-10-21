#include <stdio.h>
#define MAXLINE 1024
void main( void )
{
	FILE *fpin; // ������� ����
	FILE *fpout; // �������� ����
	char line[100][MAXLINE]; // ������� ������
	char *ptr;
	int lineNum = 0;
	int massLineNum[100];
	char* lines[MAXLINE];
	char* begin;
	char* linebuf;
	int i, j;
	int buf;
    int noSwap = 1;
	fpin = fopen( "vvod.txt", "rt" ); // ������� ���� ��� ������
	if( fpin == NULL )
		return; // ������ ��� �������� �����
	fpout = fopen("vivod.txt", "wt" ); // ������� ���� ��� ������
	if( fpout == NULL )
		return; // ������ ��� �������� �����
	while( !feof( fpin ) )// ���� �� ����� �������� �����
	{
		i = 0;
		ptr = fgets( line[lineNum+1], MAXLINE, fpin ); // ������ ������
		if( ptr == NULL )
			break; // ���� ��������
		lineNum++;
		while( *ptr != '\0' ) // ���� �� ����� ������
		{
			i++;
			ptr++; // ���������� ��������� �� ������
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
	fclose( fpin ); // ������� ������� ����
	fclose( fpout ); // ������� �������� ����
}