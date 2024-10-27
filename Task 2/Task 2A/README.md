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
1. To debug the instructions executed by the Spike Simulator step-by-step, we use the command, `spike -d pf <file_name>.o`.
```bash
spike -d pf Sum1ton.o
```
> [!NOTE]
> * `-d`: This flag stands for debug mode. When we use this option, Spike runs in an interactive debug mode, allowing us to step through the execution of the program, examine registers, set breakpoints, and inspect the state of the processor while the program runs.
2. Open the previously generated Assembly Code by RISC-V compiler in a new terminal to verify functionality. A screenshot of the same has been pasted below.<br/>
  ![image](https://github.com/user-attachments/assets/65dee3f9-9743-4d78-a51d-8114e657b033) <br/>
***Figure 3. Generated Assembly Code in RISC-V Compiler*** <br/>
3. Type the following commands in the Spike Debugging shell, and try to understand the execution as per your requirement. <br/>
  `until pc 0 <instruction_no.>` <br/>
  `reg 0 <register_no.>`
> [!IMPORTANT]
> * `until pc 0 <instruction_no.>` - When we issue the command until `pc 0 <instruction_no.>`, the Spike simulator will run the program continuously (without stepping through each instruction) until the PC reaches the specific instruction address (`<instruction_no.>`). Once the PC matches this address, the simulator will pause, allowing us to inspect the state of the program, registers, memory, etc., at that exact point in execution.
> * `reg 0 <register_no.>` - When we `use reg 0 <register_no.>`, Spike will display the value stored in the specified register of the core 0.
> * Press **Enter** to execute the instruction and move to next instruction.
> * Press **Q** to exit the Spike Debugging shell.



