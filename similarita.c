#include <stdio.h>
#include <string.h>
//Per testare un input modificare le prossime 4 righe, R è la lunghezza della stringa b, C è la lunghezza della stringa a
#define C 8
#define R 7

char *a="GATTACA";
char *b="TACCA";

void printarrc(char arr[][C+1], int I, int J) {
	printf("    ");
	int i,j;
	for (i=0;i<C;i++)
		printf("%c ",a[i]);
	printf("\n");
	for (i=0;i<I;i++) {
		if (i>0) printf("%c ",b[i-1]);
		else printf("  ");
		for (j=0;j<J;j++) {
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}

void printarr(int arr[][C+1], int I, int J) {
	printf("    ");
	int i,j;
	for (i=0;i<C;i++)
		printf("%c ",a[i]);
	printf("\n");
	for (i=0;i<I;i++) {
		if (i>0) printf("%c ",b[i-1]);
		else printf("  ");
		for (j=0;j<J;j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int max(int a, int b, int c) {
	if (a>=b) {
		if (a>=c)
			return a;
		else return c;
	}
	else {
		if (b>=c)
			return b;
		else return c;
	}
}

int main (void) {
	int arr[R+1][C+1];
	char dir[R+1][C+1];
	int i,j;
	int x,y,z;

	for (i=0;i<=R;i++) {
		arr[i][0]=0;
		dir[i][0]='0';
	}
	for (i=0;i<=C;i++) {
		arr[0][i]=0;
		dir[0][i]='0';
	}

	for (i=1;i<=R;i++)
		for (j=1;j<=C;j++) {
			// printf("I= %d , J= %d\n",i,j);
			if (b[i-1]==a[j-1]) {
				x=arr[i-1][j-1]+1;
			} else x=arr[i-1][j-1];

			y=arr[i-1][j];
			z=arr[i][j-1];
			arr[i][j]=max(x,y,z);
			if (arr[i][j]==x)
				dir[i][j]='d';
			else if (arr[i][j]==y)
				dir[i][j]='1';
			else dir[i][j]='2';
			// printarr(arr,R+1,C+1);
	// printarrc(dir,R+1,C+1);
		}

	// printarr(arr,R+1,C+1);
	// printarrc(dir,R+1,C+1);

	x=R;
	y=C;
	char s[50];
	int n = 0;
	while (x > 0 && y > 0) {
		if (dir[x][y]=='d') {
			x--;
			y--;
			if (b[x]==a[y]) {
				s[n++]=b[x];
			}
		} else if (dir[x][y]=='1')
			x--;
		else y--;
	}
	printf("Soluzione: ");
	for (i=n-1;i>=0;i--)
		printf("%c",s[i]);
	printf("\n");
	
	return 0;
}
