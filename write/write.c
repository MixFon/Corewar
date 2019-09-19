#include "../include/asm.h"

void	write_big_endian(int fd, void *bits, int len_bits)
{
	while (len_bits > 0)
	{
		len_bits--;
		write(fd, (unsigned char *)bits + len_bits, 1);
	}
}

int main(void)
{
	int fd;
	char *name_cor = "Hello";
	short 	a = 0xeedd;
	short 	reg = 0x80;
	short 	dir = 0x10;
	short 	ind = 0x0;
	char	c = 0x11;
	int b = -20;
	unsigned char endian[4] = {1, 0,0, 0};
	short x;
	 

	//b = reg | dir | ind;	
	//b = 0xaaffbbcc;
	//b = 19;
	//b = *(short *) endian;
	//b = b >> 1;
	//b = 19;
	//a = ~a + 1;
	while (++b < 19)
		ft_printf("b = {%d} [%#x}\n",b, b);
	/*
	if (!(fd = open(name_cor, O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		ft_putendl("Not file");
	write_big_endian(fd, &b, (sizeof(b)));
	*/
	//write_big_endian(fd, &a, (sizeof(a)));
	//write_big_endian(fd, &c, (sizeof(c)));
	//write(fd, (unsigned char *)(&b) + 3, 1);
	//write(fd, (unsigned char *)(&b) + 2, 1);
	//write(fd, (unsigned char *)(&b) + 1, 1);
	//write(fd, (unsigned char *)(&b), 1);
	//write(fd, &a, 4);
	close(fd);
	return (0);
}
