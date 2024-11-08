# Task 4 Output:
> [!IMPORTANT]
> Please note that designing the RISC-V Architecture and creating its Testbench are not within the scope of this research internship. Therefore, I have utilized the existing RTL Description and Testbench for the RISC-V Architecture, **with minor modifications**, which has already been developed by Vinay Rayapati and Kunal Ghosh. </br>
> *The reference GitHub repository is: [iiitb_rv32i](https://github.com/vinayrayapati/rv32i/).*

## Steps to Install & Run a RTL Design on Icarus Verilog using GTK Wave:
1. To install, open the terminal and type the command, `sudo apt install iverilog gtkwave`.
 ``` bash
 sudo apt install iverilog gtkwave
 ```
2. Create a project directory and add the Verilog source files (.v files) and testbench (.v or .sv file), uisng `gedit` or `touch` commands.
> [!CAUTION]
> In the testbench include the directives to write to a .vcd file, `$dumpfile("output_name.vcd");` and `$dumpvars(0, testbench_module);`.
> ```bash
> $dumpfile("KD_rv32i.vcd");
> $dumpvars(0, KD_rv32i_tb);
> ```

3. Run the following command, `iverilog -o output_name design_file.v testbench_file.v`, to compile the design and generate a simulation executable.
``` bash
iverilog -o KD_rv32i KD_rv32i.v KD_rv32i_tb.v
```
4. To run the generated simulation executable, use the command, `vvp output_name`.
``` bash
vvp KD_rv32i
```
5. View the waveform in GTKWave by running the command, `gtkwave output_name.vcd`.
``` bash
gtkwave KD_rv32i.vcd
```
6. In GTKWave, use the interface to view signals, zoom, and analyze the simulation results.

## Waveform Analysis of RISC-V Core Instruction Set:
### The Differences between Standard RISC-V ISA and the Instruction Set used in the reference repository:  
|  **Instruction**  |  **Standard RISC-V ISA OP Code**  |  **Hardcoded ISA OP Code**  |  
|  :----  |  :----:  |  :----:  |  
|  `add r6, r2, r1`  |  `32'h00110333`  |  `32'h02208300`  |  
|  `sub r7, r1, r2`  |  `32'h402083b3` |  `32'h02209380`  |  
|  `and r8, r1, r3`  |  `32'h0030f433`  |  `32'h0230a400`  |  
|  `or r9, r2, r5`  |  `32'h005164b3`  |  `32'h02513480`  |  
|  `xor r10, r1, r4`  |  `32'h0040c533`  |  `32'h0240c500`  |  
|  `slt r1, r2, r4`  |  `32'h0045a0b3`  |  `32'h02415580`  |  
|  `addi r12, r4, 5`  |  `32'h004120b3`  |  `32'h00520600`  |  
|  `beq r0, r0, 15`  |  `32'h00000f63`  |  `32'h00f00002`  |  
|  `sw r3, r1, 2`  |  `32'h0030a123`  |  `32'h00209181`  |  
|  `lw r13, r1, 2`  |  `32'h0020a683` |  `32'h00208681`  |  
|  `srl r16, r14, r2`  |  `32'h0030a123`  |  `32'h00271803`  |
|  `sll r15, r1, r2`  |  `32'h002097b3`  |  `32'h00208783`  |   
