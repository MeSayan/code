#include <stdio.h>
int main() {
	union Data {
		int i_;
		float f_;
		unsigned char str[20];
	}data;
	
	printf("size = %d\n",sizeof(data));
	data.i_ = 10;
	data.f_ = 220.5;
	printf("data.i_ = %d\n",data.i_);
	
	return 0;
}
