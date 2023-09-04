#include <elf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void check_elf(unsigned char *e_ident);
void close_elf(int elf);
void print_magic(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);

/**
 * check_elf - Checks if the file it's an ELF file
 * @e_ident: Pointer to an array string containing ELF magic num
 * Description: if the file is not an ELF file (exit code 98)
 */
void check_elf(unsigned char *e_ident)
{
	int n;

	for (n = 0; n < 4; n++)
	{
		if (e_ident[index] != 127 &&
				e_ident[n] != 'E' &&
				e_ident[n] != 'L' &&
				e_ident[n] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_class - Prints the class of an ELF header file
 * @e_ident: Pointer to an array string containing ELF magic num
 */
void print_class(unsigned char *e_ident)
{
	
