# Task 2A Output
## Glimpse of Task 1:
In the previous task, we went through the process of creating, compiling, and analyzing a C program in a Linux environment. 
First, we navigated to the 'Home' directory and installed a text editor (Leafpad) if it wasn't already available. 
Afterwards, we opened the editor to write a C code that calculates the sum of numbers from 1 to N, and once the code was written, it was compiled using the GNU Compiler Collection (GCC). 
After compilation, the executable file was run to confirm the program's functionality. 
We also verified the C code by displaying its content in the terminal. <br/>

Next, we explored how to generate assembly code using a RISC-V compiler for the same C program. 
The task involved compiling the C code into an object file and using the objdump tool to disassemble the object file into assembly language. 
We examined the differences in assembly instructions produced by using different optimization flags, such as `-O1` and `-Ofast`. 
We noted that the number of instructions varied based on the optimization level, with more aggressive optimizations resulting in fewer instructions.

## Steps to Compile a C Code in the RISC-V Compiler *(Spike Simulator)*:
The main objective of this task is to verify whether the C program compiled in GCC and RISC-V are same or not.<br/>
1. To compile and run the C program in RISC-V compiler, first open a new Linux terminal and navigate to the directory where the object file of the C program is stored.<br/>
2. Next, type the following command, `spike pk <file_name>.o`, to get the compiled output.
  ```bash
  spike pk Sum1ton.o
  ```
> [!NOTE]
> * `spike`: This is the RISC-V ISA simulator (also known as a RISC-V functional simulator). Spike is a tool that emulates RISC-V hardware, allowing us to test and run RISC-V programs on a simulated environment without actual hardware.
> * `pk`: This stands for "proxy kernel," which acts as a lightweight operating system for running programs in the Spike simulator. It provides basic system call services, such as file I/O and memory management, that are needed to run user programs in the simulated environment.

![Compiled C Code in RISC-V Spike Simulator](https://github.com/user-attachments/assets/ddfac69a-b4ff-402d-b6c6-49476fb0f597) <br/>
***Figure 1. Compiled C Code in Spike Simulator*** <br/>
<br/>
![Compiled C Code in GCC v/s Spike Simulator](https://github.com/user-attachments/assets/de1e4468-d26f-42bf-b888-e738490ccb5c) <br/>
***Figure 2. Compiled C Code in GCC v/s Spike Simulator*** <br/>
Upon comparing the compiled outputs from GCC (from the previous task) and Spike Simulation (from this task), we see that both the outputs are same. 
Hence, we can conclude that the generated Assembly Instructions are correct for the written C program. 

## Steps to Debug the Compilation Process in Spike Simulation:
