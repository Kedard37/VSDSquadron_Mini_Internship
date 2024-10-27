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
1. To debug the instructions executed by the Spike Simulator step-by-step, we use the command, `spike -d pk <file_name>.o`.
```bash
spike -d pk Sum1ton.o
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

![Debug 1](https://github.com/user-attachments/assets/9d2c10f3-1d38-4549-a85a-6d1d4c536214) <br/>
***Figure 4. Debug 1*** <br/>
In this image, we see the Spike simulator running in debug mode with the program `Sum1ton.o`. The command `until pc 0 100b0` is issued, which instructs the simulator to run until the program counter (PC) reaches address `0x100b0`. The we the contents of two registers: `a2` and `a0` using the `reg 0` command. Initially, `a2` holds the value `0x0`, and `a0` holds the value `0x1`. The simulator steps through the program, executing two instructions (`lui a2, 0x1` and `lui a0, 0x21`), which load immediate values into the registers. After the instructions execute, `a2` contains `0x1000`, and `a0` contains `0x21000`, showing how the values in these registers change during execution.
> [!NOTE]
> `lui` stands for **Load Upper Immediate**, which is an instruction in the RISC-V instruction set. It is used to load a immediate value into the upper 52 bits of a register, while the lower 12 bits are set to 0.

![Debug 2](https://github.com/user-attachments/assets/943f67e1-d9f9-47cc-b9d6-274a639a04e2) <br/>
***Figure 5. Debug 2*** <br/>
In the image, the Spike simulator is running `Sum1ton.o` in debug mode, and after halting at PC `0x100b8`, the stack pointer (`sp`) initially holds `0x0000003ffffffb50` and register `a2` holds `0x0000000000001000`. The program then executes two **addi** (add immediate) instructions: the first, `addi sp, sp, -16`, decreases the stack pointer by (16)<sub>decimal</sub> = (10)<sub>hexadecimal</sub>, resulting in `0x0000003ffffffb40`, while the second, `addi a2, a2, 954`, increases the value of register `a2` by (954)<sub>decimal</sub> = (3ba)<sub>hexadecimal</sub>, updating it to `0x0000000000013ba`. This demonstrates how the program updates these registers as part of its execution flow.
> [!NOTE]
> `addi` stands for **Add Immediate**, an instruction in the RISC-V instruction set that performs an addition between a register and an immediate (a constant value) and stores the result back into a register.

![image](https://github.com/user-attachments/assets/3313ea88-82a5-4819-91e9-84ed789ad1a0) <br/>
***Figure 6. Debug 3*** <br/>
In this image, the Spike simulator is running the `Sum1ton.o` program in debug mode, pausing at PC `0x100c0`. Initially, register `a1` holds `0x0000003ffffffb58` and `a0` holds `0x0000000000021000`. The first instruction executed is `li a1, 100`, which loads the value (100)<sub>decimal</sub> = (64)<sub>hexadecimal</sub> into register `a1`, updating it to `0x0000000000000064`. The second instruction, `addi a0, a0, 384`, adds the immediate value (384)<sub>decimal</sub> = (180)<sub>hexadecimal</sub> to the current value of `a0`, resulting in `0x0000000000021180`. This demonstrates how the program updates the values in these registers through simple arithmetic and load operations.
> [!NOTE]
> `li` stands for **Load Immediate**, which is a pseudo-instruction used to load a constant (immediate value) into a register.

Similarly, other instructions in the Assembly code can be debugged in the same fashion.
