#include <stdio.h>

int fastRead_int() {
 register int c = getchar_unlocked();
 int x, neg;
 x =  neg = 0;
 for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

 if(c=='-') {
  neg = 1;
  c = getchar_unlocked();
 }

 for(; c>47 && c<58 ; c = getchar_unlocked()) {
  x = (x<<1) + (x<<3) + c - 48;
 }

 if(neg)
  x = -x;
 return x;
}

void fastRead_string(char *str, char delim) {
 register char c = 0;
 register int i = 0;

 while (c < 33)
  c = getchar_unlocked();

 while (c != delim) {
  str[i] = c;
  c = getchar_unlocked();
  i = i + 1;
 }

 str[i] = '\0';
}

inline void printint(long long n) {
	if(n == 0)
	{
		putchar_unlocked('0');
		putchar_unlocked('\n');
	}
	else if(n == -1)
	{
		putchar_unlocked('-');
		putchar_unlocked('1');
		putchar_unlocked('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			putchar_unlocked(buf[++i]);
	}
}

inline void printString(char *str,int size) {
    int i ;
    for( i = 0; i < size; i++)
        putchar_unlocked(str[i]);
}

int main(){
 int n;
 char s[100];

 n = fastRead_int();
 printf("%d\n", n);

 fastRead_string(s, '\n');
 printf("%s\n", s);
 return 0;
}
