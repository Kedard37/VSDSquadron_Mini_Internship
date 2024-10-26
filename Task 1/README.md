# Task 1 Output:
## Steps to Create a C Code in C Compiler:
1. To create a C code in a linux terminal, initially change to 'Home' directory by typing the command, `cd`.
```bash
cd
```
> [!WARNING]
> Install 'Leafpad' text editor using the command, `sudo apt install leafpad`, if not yet installed, before running the next command.
2. Then open a 'Leafpad' text editor, using the command, `leafpad <file_name>.c &`.
```bash
leafpad Sum1ton.c &
```
> [!TIP]
> `&` will open the text editor in the background.

3. Type the C code in the text editor as shown below.

   ![Created C Code](https://github.com/user-attachments/assets/cc5f856b-516a-4e10-a154-325292aefda6)
   ***Figure 1. Created C Code***

## Steps to Compile a C Code in the GNU Compiler Collection (GCC):
1. Compile and run the code by typing these two commands one after the other. <br/>
   `gcc <file_name>.c` <br/>
   `./a.out`
> [!NOTE]
> * `gcc Sum1ton.c`: This command compiles the C source code file using the GNU Compiler Collection (GCC). The compiled output will be stored in an executable file named `a.out` by default. <br/>
> * `./a.out`: This command executes the compiled executable file `a.out`.
```bash
gcc Sum1ton.c
./a.out
```
2. The C code which is written can be viewed in the terminal by typing the command, `cat <file_name>.c`.
> [!NOTE]
> `cat` is a command-line utility in Unix-like operating systems (including Linux and macOS) that is used to concatenate and print files to the standard output.
```bash
cat Sum1ton.c
```

   ![Compiled C Code](https://github.com/user-attachments/assets/b1a4fa76-8b74-43ec-a888-12e84e3f1331)
   ***Figure 2. Compiled C Code in GCC***

## Steps to Generate a Assembly Code of a C Code in the RISC-V Compiler:
1. Type the following command to create a '.o' file for the created '.c' file (file with C code), in the 'Home' directory. <br/>
##### Using `-O1` Variable:
   `riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o <file_name>.o <file_name>.c`
```bash
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o Sum1ton.o Sum1ton.c
```
##### Using `-Ofast` Variable:
   `riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o <file_name>.o <file_name>.c`
```bash
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o Sum1ton.o Sum1ton.c
```
> [!NOTE]
> * `riscv64`: Specifies the RISC-V architecture, indicating that the compilation is targeting 64-bit RISC-V processors. <br/>
> * `unknown`: Denotes an unspecified target operating system, indicating that the compilation is not tied to a particular OS. <br/>
> * `elf`: Specifies the object file format, which is the standard format for executable files on many systems, including RISC-V. <br/>
> * `gcc`: The GNU Compiler Collection (GCC), a widely used compiler for various programming languages, including C. <br/>
> * `-Ofast`: This flag enables the compiler to use aggressive optimizations that may not always be strictly compliant with the C standard but can potentially improve performance. Instead, `-O1` enables basic optimizations that are generally safe and compliant with the C standard. <br/>
> * `-mabi`: Specifies the application binary interface (ABI) for the target architecture. <br/>
> * `lp64`: Indicates the Large Pointer 64-bit ABI, which means that pointers are 64 bits wide and other data types (like int and long) can be either 32 or 64 bits depending on the compiler flags. <br/>
> * `-march`: Specifies the target RISC-V processor architecture. <br/>
> * `rv64i`: Indicates the base integer instruction set, which is the core set of instructions supported by all RISC-V processors. <br/>

2. Now open a new terminal and type the following command, to view Assembly Level Code of the written C code. <br/>
   `riscv64-unknown-elf-objdump -d <file_name>.o | less`
```bash
riscv64-unknown-elf-objdump -d Sum1ton.o | less
```
   This command is used to view the 'objdump' file contents.
> [!NOTE]
> * `objdump`: The GNU Object File Disassembler, a tool used to extract information from object files. <br/>
> * `-d`: This option instructs `objdump` to perform disassembly, converting the machine code instructions in the object file into human-readable assembly code. <br/>
> * `| less`: The pipe `|` character redirects the output of objdump as input to the `less` command. `less` is a text pager that allows you to view the output in a more manageable way, providing features like scrolling, searching, and viewing multiple pages at once. <br/>

> [!IMPORTANT]
> Type `/main` to look out for all the matches of 'main'.

   ![Generated Assembly code for the C code using `-O1` variable](https://github.com/user-attachments/assets/1767b985-86a1-4bb6-96ec-7a2cc144dfef)
   ***Figure 3. Generated Assembly code for the C code using `-O1` variable*** </br>
   Here, when `-O1` variable is used, we see that the compiler takes 15 instructions to compile the C code.

   ![Generated Assembly code for the C code using `-Ofast` variable](https://github.com/user-attachments/assets/e82c6220-c96b-44c0-b95f-d7e0014a3520)
   ***Figure 4. Generated Assembly code for the C code using `-Ofast` variable*** </br>
   But, when `-Ofast` variable is used, we see that the compiler takes 12 instructions to compile the C code.
