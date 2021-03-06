#ifndef _ELF64_H
#define _ELF64_H

#include<sys/sched.h>
#define EI_NIDENT 16

typedef uint64_t Elf64_Addr;
typedef uint16_t Elf64_Half;
typedef uint64_t Elf64_Lword;
typedef uint64_t Elf64_Off;
typedef uint32_t Elf64_Sword;
typedef uint64_t Elf64_Sxword;
typedef uint32_t Elf64_Word;
typedef uint64_t Elf64_Xword;

typedef struct {
  unsigned char e_ident[EI_NIDENT];
  Elf64_Half    e_type;
  Elf64_Half    e_machine;
  Elf64_Word    e_version;
  Elf64_Addr    e_entry;
  Elf64_Off     e_phoff;
  Elf64_Off     e_shoff;
  Elf64_Word    e_flags;
  Elf64_Half    e_ehsize;
  Elf64_Half    e_phentsize;
  Elf64_Half    e_phnum;
  Elf64_Half    e_shentsize;
  Elf64_Half    e_shnum;
  Elf64_Half    e_shstrndx;
} Elf64_Ehdr;

typedef struct {
  Elf64_Word    p_type;
  Elf64_Word    p_flags;
  Elf64_Off     p_offset;
  Elf64_Addr    p_vaddr;
  Elf64_Addr    p_paddr;
  Elf64_Xword   p_filesz;
  Elf64_Xword   p_memsz;
  Elf64_Xword   p_align;
} Elf64_Phdr;

//p_type of phdr
#define PT_NULL 0 //unused program header
#define PT_LOAD  1 //segment to be loaded from file
#define PT_DYNAMIC 2 //dynamic linking info
#define PT_INTERP 3 
#define PT_NOTE 4
#define PT_SHLIB 5
#define PT_PHDR 6

//Segment Flags
#define PF_P  0x1 //present
#define PF_W  0x2 //write 
#define PF_U  0x4 //user 

void* find_file(char *filename);

//uint64_t find_file(char *filename);
struct task_struct* elf_file_load(struct task_struct *process, char *filename);
#endif
