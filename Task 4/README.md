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
> $dumpfile("KedarD_rv32i.vcd");
> $dumpvars(0, KedarD_rv32i_tb);
> ```

3. Run the following command, `iverilog -o output_name design_file.v testbench_file.v`, to compile the design and generate a simulation executable.
``` bash
iverilog -o KedarD_rv32i KedarD_rv32i.v KedarD_rv32i_TB.v
```
4. To run the generated simulation executable, use the command, `vvp output_name`.
``` bash
vvp KedarD_rv32i
```
5. View the waveform in GTKWave by running the command, `gtkwave output_name.vcd`.
``` bash
gtkwave KedarD_rv32i.vcd
```
6. In GTKWave, use the interface to view signals, zoom, and analyze the simulation results.

## Waveform Analysis of RISC-V Core Instruction Set:
### The Differences between Standard RISC-V ISA and the Instruction Set used in the reference repository:  
| **Inst. No.** |  **Instruction**  |  **Standard RISC-V ISA OP Code**  |  **Hardcoded ISA OP Code**  |  
| :----: |  :----  |  :----:  |  :----:  |  
| 1 |  `add r6, r2, r1`  |  `32'h00110333`  |  `32'h02208300`  |  
| 2 |  `sub r7, r1, r2`  |  `32'h402083b3` |  `32'h02209380`  |  
| 3 |  `and r8, r1, r3`  |  `32'h0030f433`  |  `32'h0230a400`  |  
| 4 |  `or r9, r2, r5`  |  `32'h005164b3`  |  `32'h02513480`  |  
| 5 |  `xor r10, r1, r4`  |  `32'h0040c533`  |  `32'h0240c500`  |  
| 6 |  `slt r1, r2, r4`  |  `32'h0045a0b3`  |  `32'h02415580`  |  
| 7 |  `addi r12, r4, 5`  |  `32'h004120b3`  |  `32'h00520600`  |  
| 8 |  `beq r0, r0, 15`  |  `32'h00000f63`  |  `32'h00f00002`  |
| 9 |  `sw r3, r1, 2`  |  `32'h0030a123`  |  `32'h00209181`  |  
| 10 |  `lw r13, r1, 2`  |  `32'h0020a683` |  `32'h00208681`  |  
| 11 |  `srl r16, r14, r2`  |  `32'h0030a123`  |  `32'h00271803`  |
| 12 |  `sll r15, r1, r2`  |  `32'h002097b3`  |  `32'h00208783`  |   

#### **Instruction 1.** `add r6, r2, r1` </br>
![ADD](https://github.com/user-attachments/assets/6fdac1d4-b422-4ad0-a931-c266280e6236) </br>
***Figure 1. ADD Instruction*** </br>
- **ADD**: Adds two registers and stores the result in the destination register. 
- **Operation**: `ADD:EX_MEM_ALUOUT <= ID_EX_A + ID_EX_B;` 
- **32-bit OP Code**: (`02208300`)<sub>16</sub> 
- **ID_EX_A**: (1)<sub>10</sub>  
- **ID_EX_B**: (2)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (3)<sub>10</sub> 
- **Procedure**: (1)<sub>10</sub>  + (2)<sub>10</sub>  = (3)<sub>10</sub> 

#### **Instruction 2.** `sub r7, r1, r2` </br>
![SUB](https://github.com/user-attachments/assets/1f1a1318-f379-4ebd-9b4e-b01072205833) </br>
***Figure 2. SUB Instruction*** </br>
- **SUB**: Subtracts the second register from the first and stores the result in the destination register.
- **Operation**: `SUB:EX_MEM_ALUOUT <= ID_EX_A - ID_EX_B;` 
- **32-bit OP Code**: (`02209380`)<sub>16</sub> 
- **ID_EX_A**: (1)<sub>10</sub>  
- **ID_EX_B**: (2)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (-1)<sub>10</sub> 
- **Procedure**: (1)<sub>10</sub>  - (2)<sub>10</sub>  = (-1)<sub>10</sub> 

#### **Instruction 3.** `and r8, r1, r3` </br>
![AND](https://github.com/user-attachments/assets/2f1726f5-7283-46ef-98f6-ae92ab506534) </br>
***Figure 3. AND Instruction*** </br>
- **AND**: Performs a bitwise AND on two registers and stores the result in the destination register.
- **Operation**: `AND:EX_MEM_ALUOUT <= ID_EX_A & ID_EX_B;` 
- **32-bit OP Code**: (`0230A400`)<sub>16</sub> 
- **ID_EX_A**: (1)<sub>10</sub>  
- **ID_EX_B**: (3)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (1)<sub>10</sub> 
- **Procedure**: (1)<sub>10</sub>  & (3)<sub>10</sub>  = (0001)<sub>2</sub> & (0011)<sub>2</sub> = (0001)<sub>2</sub> = (1)<sub>10</sub>

#### **Instruction 4.** `or r9, r2, r5` </br>
![OR](https://github.com/user-attachments/assets/7014a244-9719-4087-98f0-eebc91beb9cb) </br>
***Figure 4. OR Instruction*** </br>
- **OR**: Performs a bitwise OR on two registers and stores the result in the destination register.
- **Operation**: `OR :EX_MEM_ALUOUT <= ID_EX_A | ID_EX_B;` 
- **32-bit OP Code**: (`02513480`)<sub>16</sub> 
- **ID_EX_A**: (2)<sub>10</sub>  
- **ID_EX_B**: (5)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (7)<sub>10</sub> 
- **Procedure**: (2)<sub>10</sub>  | (5)<sub>10</sub>  = (0010)<sub>2</sub> | (0101)<sub>2</sub> = (0111)<sub>2</sub> = (7)<sub>10</sub>

#### **Instruction 5.** `xor r10, r1, r4` </br>
![XOR](https://github.com/user-attachments/assets/e225d901-fca9-4735-897a-9fe422ec7832) </br>
***Figure 5. XOR Instruction*** </br>
- **XOR**: Performs a bitwise XOR on two registers and stores the result in the destination register.
- **Operation**: `XOR:EX_MEM_ALUOUT <= ID_EX_A ^ ID_EX_B;` 
- **32-bit OP Code**: (`0240C500`)<sub>16</sub> 
- **ID_EX_A**: (1)<sub>10</sub>  
- **ID_EX_B**: (4)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (5)<sub>10</sub> 
- **Procedure**: (1)<sub>10</sub>  ^ (4)<sub>10</sub>  = (0001)<sub>2</sub> ^ (0100)<sub>2</sub> = (0101)<sub>2</sub> = (5)<sub>10</sub>

#### **Instruction 6.** `slt r1, r2, r4` </br>
![SLT](https://github.com/user-attachments/assets/767c100a-b365-4e40-9541-4931fbb6a4f1) </br>
***Figure 6. SLT Instruction*** </br>
- **SLT**: Sets the destination register to 1 if the first register is less than the second; otherwise, it sets it to 0.
- **Operation**: `SLT:EX_MEM_ALUOUT <= (ID_EX_A < ID_EX_B) ? 32'd1 : 32'd0;` 
- **32-bit OP Code**: (`02415580`)<sub>16</sub> 
- **ID_EX_A**: (2)<sub>10</sub>  
- **ID_EX_B**: (4)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (1)<sub>10</sub> 
- **Procedure**: (2)<sub>10</sub> < (4)<sub>10</sub>  = `True`= (1)<sub>2</sub>

#### **Instruction 7.** `addi r12, r4, 5` </br>
![ADDI](https://github.com/user-attachments/assets/1cdb5d04-ad6d-46df-bb84-b20ead2e66e3) </br>
***Figure 7. ADDI Instruction*** </br>
- **ADDI**: Adds an immediate value to a register and stores the result in the destination register.
- **Operation**: `ADDI:EX_MEM_ALUOUT <= ID_EX_A + ID_EX_IMMEDIATE;` 
- **32-bit OP Code**: (`00520600`)<sub>16</sub> 
- **ID_EX_A**: (4)<sub>10</sub>  
- **ID_EX_IMMEDIATE**: (5)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (9)<sub>10</sub> 
- **Procedure**: (4)<sub>10</sub> + (5)<sub>10</sub>  = (9)<sub>10</sub>

#### **Instruction 8.** `sw r3, r1, 2` </br>
![SW](https://github.com/user-attachments/assets/1894283b-b19c-4507-8b30-988a91f121a2) </br>
***Figure 8. SW Instruction*** </br>
- **SW**: Stores the word in a register to a memory address calculated from a base register and an immediate offset.
- **Operation**: `SW  :EX_MEM_ALUOUT <= ID_EX_IR[24:20] + ID_EX_IR[19:15];` 
- **32-bit OP Code**: (`00209181`)<sub>16</sub> 
- **ID_EX_IR[24:20]**: (00010)<sub>2</sub>  
- **ID_EX_IR[19:15]**: (00001)<sub>2</sub>  
- **EX_MEM_ALUOUT**: (00011)<sub>2</sub> = (3)<sub>10</sub>
- **Procedure**: (00010)<sub>2</sub> + (00001)<sub>2</sub> = (2)<sub>10</sub> + (1)<sub>10</sub>  = (00011)<sub>2</sub> = (3)<sub>10</sub>

#### **Instruction 9.** `sll r15, r1, r2` </br>
![SLL](https://github.com/user-attachments/assets/b9c2e08b-cc01-423e-acf8-32efdc6f593a) </br>
***Figure 9. SLL Instruction*** </br>
- **SLL**: Shifts the bits in the first register left by the number of positions specified in the second register, storing the result in the destination register.
- **Operation**: `SLL:EX_MEM_ALUOUT <= ID_EX_A << ID_EX_B;` 
- **32-bit OP Code**: (`00208783`)<sub>16</sub> 
- **ID_EX_A**: (1)<sub>10</sub>  
- **ID_EX_B**: (2)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (4)<sub>10</sub>
- **Procedure**: (1)<sub>10</sub> << (2)<sub>10</sub> = (0001)<sub>2</sub> << (2)<sub>10</sub>  = (0100)<sub>2</sub> = (4)<sub>10</sub>

#### **Instruction 10.** `beq r0, r0, 15` </br>
![BEQ](https://github.com/user-attachments/assets/10e1ad5e-b95e-4be8-8356-f89dfacf36e0) </br>
***Figure 10. BEQ Instruction*** </br>
- **BEQ**: Branch if equal; jumps to a specified instruction if two registers are equal.
- **Operation**: `EX_MEM_ALUOUT <= ID_EX_NPC + ID_EX_IMMEDIATE;` 
- **32-bit OP Code**: (`00F00002`)<sub>16</sub> 
- **ID_EX_NPC**: (10)<sub>10</sub>  
- **ID_EX_IMMEDIATE**: (15)<sub>10</sub>  
- **EX_MEM_ALUOUT**: (25)<sub>10</sub>
- **Procedure**: (10)<sub>10</sub> + (15)<sub>10</sub> = (25)<sub>10</sub>

> [!NOTE]
> - **BNE**: Branch if not equal; jumps to a specified instruction if two registers are not equal.
>    - **Operation**: `EX_MEM_ALUOUT <= ID_EX_NPC+ID_EX_IMMEDIATE;` 
>    - **32-bit OP Code**: (`01409002`)<sub>16</sub> 
> - **LW**: Load word; loads a 32-bit word from memory into a register.
>    - **Operation**: `LW  :EX_MEM_ALUOUT <= ID_EX_A + ID_EX_IMMEDIATE;` 
>    - **32-bit OP Code**: (`00208681`)<sub>16</sub> 
> - **SRL**: Shift right logical; shifts the bits in a register to the right by a specified amount, filling with zeros.
>    - **Operation**: `SRL:EX_MEM_ALUOUT <= ID_EX_A >> ID_EX_B;` 
>    - **32-bit OP Code**: (`00271803`)<sub>16</sub> 
