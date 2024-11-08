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
