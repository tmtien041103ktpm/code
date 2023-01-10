#include<bits/stdc++.h>
using namespace std;
main()
{
FILE *fp; 
char ch;
if ( (fp=fopen(“test.txt”, "w")) == NULL ) 
{	cout << "Cannot open file.\n";
	exit(1);
}
do {
		     ch = getchar();	//đọc từ bàn phím
		     fputc(ch, fp);		//ghi vào file
    }while (ch != '$');
	fclose(fp);	//đóng file
}
