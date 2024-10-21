### Steps inferred in Task 1 Videos:
#### Steps to Create a C Code in C Compiler:
1. To create a C code in a linux terminal, initially change to 'Home' directory by typing the command, `cd`.
2. Then open a 'LeafPad' text editor, using the command, `leafpad <file_name>.c &`.
3. A text editor will open in background and type the code in it as shown below.

   ![WhatsApp Image 2024-10-21 at 16 41 08_e4eaac07](https://github.com/user-attachments/assets/cc5f856b-516a-4e10-a154-325292aefda6)

#### Steps to Compile a C Code in C Compiler:
1. Compile and run the code by typing these two commands one after the other. <br/>
   `gcc <file_name>.c` <br/>
   `./a.out`
2. The C code which is written can be viewed in the terminal by typing the command, `cat <file_name>.c`.

   ![WhatsApp Image 2024-10-21 at 16 42 46_e8e312fa](https://github.com/user-attachments/assets/b1a4fa76-8b74-43ec-a888-12e84e3f1331)

#### Steps to Compile a C Code in RISC-V Compiler:
1. Type the following command to create a '.o' file for the created '.c' file (file with C code), in the 'Home' directory. <br/>
   `riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o <file_name>.o <file_name>.c`
2. Now open a new terminal and type the following command, to view Assembly Level Code of the written C code. <br/>
   `riscv64-unknown-elf-objdump -d <file_name>.o | less` <br/>
   This command is used to view the 'objdump' file contents.
   
   ![WhatsApp Image 2024-10-21 at 16 50 34_58286f8b](https://github.com/user-attachments/assets/e82c6220-c96b-44c0-b95f-d7e0014a3520)
