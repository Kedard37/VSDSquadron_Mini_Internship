# VSDSquadron Mini Internship
This repository includes the files related to VSDSquadron Mini Research Internship Program - 20th October 2024 Cohort. 

### Intern: Kedar Desai
### College: B.M.S. College of Engineering, Bengaluru
### LinkedIn: https://www.linkedin.com/in/kedardesai372004
### Course Instructor: Kunal Ghosh

---

<details>
<summary><h2>Task: 1. Uploading Snapshot of Compiled C Code in GCC and RISC-V Objdmp</h2></summary>
  
#### Recording-1: https://1drv.ms/v/s!Ai4WW_jutengioJdZ78uhSPF1aH--w?e=FOv6oe
- [x] Create GitHub repo.
- [x] Install RISC-V toolchain using VDI shared over whatsapp group.
- [x] Refer to [C based Lab video](https://1drv.ms/v/s!Ai4WW_jutenghrYpUsL_MLKJDSLVyg?e=gdA9TW) and [RISC-V based lab video](https://1drv.ms/v/s!Ai4WW_jutengg7dbp9XlZXjJmxogBw?e=ycX4fO). 
- [x] Complete exact steps on your machine. 
- [x] Upload snapshot of compiled C code and RISC-V Objdmp on your GitHub repo.

## Task 1 Output:
   ![Created C Code](https://github.com/user-attachments/assets/cc5f856b-516a-4e10-a154-325292aefda6)
   ***Figure 1. Created C Code***

   ![Compiled C Code](https://github.com/user-attachments/assets/b1a4fa76-8b74-43ec-a888-12e84e3f1331)
   ***Figure 2. Compiled C Code in GCC***

   ![Generated Assembly code for the C code using `-O1` variable](https://github.com/user-attachments/assets/1767b985-86a1-4bb6-96ec-7a2cc144dfef)
   ***Figure 3. Generated Assembly code for the C code using `-O1` variable*** </br>
   Here, when `-O1` variable is used, we see that the compiler takes 15 instructions to compile the C code.

   ![Generated Assembly code for the C code using `-Ofast` variable](https://github.com/user-attachments/assets/e82c6220-c96b-44c0-b95f-d7e0014a3520)
   ***Figure 4. Generated Assembly code for the C code using `-Ofast` variable*** </br>
   But, when `-Ofast` variable is used, we see that the compiler takes 12 instructions to compile the C code.
   
</details>

### Visit [Task 1](https://github.com/Kedard37/VSDSquadron_Mini_Internship/tree/main/Task%201) directory to get the codes, linux commands & more information about this task!

---

<details>
<summary><h2>Task: 2. Simulation Analysis using SPIKE and Building a Simple Application & Compiling it</h2></summary>
  
#### Recording-2: https://1drv.ms/v/s!Ai4WW_jutengioNNuMgM-OzvVic2Qw?e=qyDLQx

<details>
<summary><h3>Task: 2A. Simulation Analysis using SPIKE</h3></summary>
  
- [x] [SPIKE Simulation](https://1drv.ms/v/s!Ai4WW_jutengg7dmZwxQmBY-JEGihg?e=A4ASgZ) and observation with -O1 and -Ofast.
- [x] Upload snapshot of compiled C Code, RISC-V Objdmp with above options on your GitHub repo.

## Task 2A Output:
![Compiled C Code in RISC-V Spike Simulator](https://github.com/user-attachments/assets/ddfac69a-b4ff-402d-b6c6-49476fb0f597) <br/>
***Figure 1. Compiled C Code in Spike Simulator*** <br/>

![Compiled C Code in GCC v/s Spike Simulator](https://github.com/user-attachments/assets/de1e4468-d26f-42bf-b888-e738490ccb5c) <br/>
***Figure 2. Compiled C Code in GCC v/s Spike Simulator*** <br/>
Upon comparing the compiled outputs from GCC (from the previous task) and Spike Simulation (from this task), we see that both the outputs are same. 
Hence, we can conclude that the generated Assembly Instructions are correct for the written C program. 

## Debugging the Compilation Process in Spike Simulation:
  ![image](https://github.com/user-attachments/assets/65dee3f9-9743-4d78-a51d-8114e657b033) <br/>
***Figure 3. Generated Assembly Code in RISC-V Compiler*** <br/>

![Debug 1](https://github.com/user-attachments/assets/9d2c10f3-1d38-4549-a85a-6d1d4c536214) <br/>
***Figure 4. Debug 1*** <br/>
In this image, we see the Spike simulator running in debug mode with the program `Sum1ton.o`. The command `until pc 0 100b0` is issued, which instructs the simulator to run until the program counter (PC) reaches address `0x100b0`. The we the contents of two registers: `a2` and `a0` using the `reg 0` command. Initially, `a2` holds the value `0x0`, and `a0` holds the value `0x1`. The simulator steps through the program, executing two instructions (`lui a2, 0x1` and `lui a0, 0x21`), which load immediate values into the registers. After the instructions execute, `a2` contains `0x1000`, and `a0` contains `0x21000`, showing how the values in these registers change during execution.

![Debug 2](https://github.com/user-attachments/assets/943f67e1-d9f9-47cc-b9d6-274a639a04e2) <br/>
***Figure 5. Debug 2*** <br/>
In the image, the Spike simulator is running `Sum1ton.o` in debug mode, and after halting at PC `0x100b8`, the stack pointer (`sp`) initially holds `0x0000003ffffffb50` and register `a2` holds `0x0000000000001000`. The program then executes two **addi** (add immediate) instructions: the first, `addi sp, sp, -16`, decreases the stack pointer by (16)<sub>decimal</sub> = (10)<sub>hexadecimal</sub>, resulting in `0x0000003ffffffb40`, while the second, `addi a2, a2, 954`, increases the value of register `a2` by (954)<sub>decimal</sub> = (3ba)<sub>hexadecimal</sub>, updating it to `0x0000000000013ba`. This demonstrates how the program updates these registers as part of its execution flow.

![image](https://github.com/user-attachments/assets/3313ea88-82a5-4819-91e9-84ed789ad1a0) <br/>
***Figure 6. Debug 3*** <br/>
In this image, the Spike simulator is running the `Sum1ton.o` program in debug mode, pausing at PC `0x100c0`. Initially, register `a1` holds `0x0000003ffffffb58` and `a0` holds `0x0000000000021000`. The first instruction executed is `li a1, 100`, which loads the value (100)<sub>decimal</sub> = (64)<sub>hexadecimal</sub> into register `a1`, updating it to `0x0000000000000064`. The second instruction, `addi a0, a0, 384`, adds the immediate value (384)<sub>decimal</sub> = (180)<sub>hexadecimal</sub> to the current value of `a0`, resulting in `0x0000000000021180`. This demonstrates how the program updates the values in these registers through simple arithmetic and load operations. <br/>

Similarly, other instructions in the Assembly code can be debugged in the same fashion.
</details>

<details>
<summary><h3>Task: 2B. Building a Simple Application & Compiling the same</h3></summary>
  
- [x] Write a simple C program for any simple application and compile with RISC-V GCC/SPIKE.

## Task 2B Output:
## Digital Design Application:
### Maximum & Minimum Number Detector:
The **Maximum & Minimum Number Detector** is a digital design application that identifies the largest and smallest numbers from a given set of inputs. 
This application is crucial in systems where real-time data processing is needed, such as sensor data analysis, decision-making circuits, or optimization algorithms. 
By comparing multiple inputs, the design detects and outputs both the maximum and minimum values, providing an essential function in data filtering, control systems, and digital signal processing.

#### 1. Writing a C Program to Find Maximum & Minimum of 5 User given Numerical Inputs:
![Create_a_C_Program](https://github.com/user-attachments/assets/1d144a1f-25ee-44e4-bd2d-67c7ac1cf36e) </br>
***Figure 1. Creating a C Program***

#### 2. Compiling the Written C Program using GCC(GNU Compiler Collection):
![Compiled_C_Code_in_GCC](https://github.com/user-attachments/assets/b11b1e2b-8cd8-4075-8712-a281b2c76d25) </br>
***Figure 2. Compiled C Code in GCC***

#### 3. Generating the Assembly Code for the written C Program using RISC-V Compiler:
![Generated_Assembly_code_in_RISC_V_Compiler](https://github.com/user-attachments/assets/a76f6e84-d9b7-4457-baac-85cc3968a8ef) <br/>
***Figure 3. Generated Assembly Code in RISC_V Compiler***

#### 4. Compiling & Verifying the Written C Program using Spike Simulator:
![Compiled_C_Code_in_Spike_Simulator](https://github.com/user-attachments/assets/8de29c45-6d5b-4a38-9d30-0d718d5a18e0) <br/>
***Figure 4. Compiled C Code in Spike Simulator***
### Thus, the outputs compiled by GCC and the Spike Simulator are the same! 
### Hence, Verified!
#### 5. View the Written C Program on the Terminal (OPTIONAL):
![View_the_C_Program](https://github.com/user-attachments/assets/6f91d05d-d847-4342-8c04-b38d196a9fb3) <br/>
***Figure 5. View the C Program***
</details>

</details>

### Visit [Task 2](https://github.com/Kedard37/VSDSquadron_Mini_Internship/tree/main/Task%202) directory to get the codes, linux commands & more information about this task!

---

<details>
<summary><h2>Task: 3. Analysis and Encoding of RISC-V Instruction Set for Application Code</h2></summary>
  
#### Recording-3: https://1drv.ms/v/s!Ai4WW_jutengioVXeULLeI8yaBEUpQ?e=UShN0M
- [x] List various RISC-V instruction type (R, I, S, B, U, J) after going through [RISC-V software documentation](https://riscv.org/technical/specifications/).
- [x] Identify 15 unique RISC-V instructions from riscv-objdmp of your application code.
- [x] Identify exact 32-bit instruction code in the instruction type format for 15 unique instructions.
- [x] Upload the 32-bit pattern on Github.

## Task 3 Output:
<details>
<summary><h3>Subtask: 1. Listing the RISC-V Instruction Types [R, I, S, B, U, J]</h3></summary>
  
![RISC-V Instruction Types](https://github.com/user-attachments/assets/9d0cf4e8-4a7c-4c0c-bc32-505818c5a9e5) <br/>
***Figure 1. RISC-V Instruction Types*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 24* <br/>

The above figure shows the instruction formats for various RISC-V instruction types. Each of them are described in detail below:

### 1. **R-Type (Register-Type) Instruction:**
![R-Type Instruction](https://github.com/user-attachments/assets/d9a8ba3e-30c5-4e6a-8b0f-e18e670384ec)  <br/>
***Figure 2. R-Type Instruction*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 23* <br/>
   * **Fields:**
     - `funct7` (bits 31-25): Used to differentiate between similar instructions. Often used for encoding the operation, such as shift amount or sign extension.
     - `rs2` (bits 24-20): Source register 2.
     - `rs1` (bits 19-15): Source register 1.
     - `funct3` (bits 14-12): Specifies the operation to be performed (e.g., add, subtract, etc.).
     - `rd` (bits 11-7): Destination register.
     - `opcode` (bits 6-0): Specifies the type of instruction (e.g., arithmetic, logical).
   * **Usage:** R-Type instructions perform register-to-register operations like arithmetic (ADD, SUB), logical (AND, OR), and shifts (SLL, SRL).
### 2. **I-Type (Immediate-Type) Instruction:**
![I-Type Instruction](https://github.com/user-attachments/assets/eba6cec5-ac04-4270-aef3-ebb9b3d26d95)  <br/>
***Figure 3. I-Type Instruction*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 23* <br/>
   - **Fields:**
     - `imm[11:0]` (bits 31-20): Immediate value (12-bit signed) that is directly used as an operand.
     - `rs1` (bits 19-15): Source register.
     - `funct3` (bits 14-12): Specifies the operation (e.g., load, add immediate, etc.).
     - `rd` (bits 11-7): Destination register.
     - `opcode` (bits 6-0): Specifies the type of instruction.
   - **Usage:** I-Type instructions are typically used for operations that involve an immediate value, such as `ADDI` (add immediate), load instructions (`LW`), and some system calls.
### 3. **S-Type (Store-Type) Instruction:**
![S-Type Instruction](https://github.com/user-attachments/assets/b7fb90f9-939e-40b9-be68-04f2a7cf845a) <br/>
***Figure 4. S-Type Instruction*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 23* <br/>
   * **Fields:**
     - `imm[11:5]` (bits 31-25): Upper 7 bits of the immediate value.
     - `rs2` (bits 24-20): Source register 2 (data to be stored).
     - `rs1` (bits 19-15): Source register 1 (base address).
     - `funct3` (bits 14-12): Specifies the operation (e.g., store byte, store word).
     - `imm[4:0]` (bits 11-7): Lower 5 bits of the immediate value.
     - `opcode` (bits 6-0): Specifies the type of instruction.
   * **Usage:** S-Type instructions are used for store operations, where the value in `rs2` is stored in memory at the address computed by adding the immediate value to `rs1`. Example: `SW` (store word).
### 4. **B-Type (Branch-Type) Instruction:**
![B-Type Instruction](https://github.com/user-attachments/assets/4242a6ba-dfeb-4b2a-8540-31ffb27ea258) <br/>
***Figure 5. B-Type Instruction*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 24* <br/>
   * **Fields:**
     - `imm[12]` (bit 31): 12th bit of the immediate value.
     - `imm[10:5]` (bits 30-25): Bits 10 through 5 of the immediate value.
     - `rs2` (bits 24-20): Source register 2 (used for comparison).
     - `rs1` (bits 19-15): Source register 1 (used for comparison).
     - `funct3` (bits 14-12): Specifies the condition for the branch (e.g., equal, less than).
     - `imm[4:1]` (bits 11-8): Bits 4 through 1 of the immediate value.
     - `imm[11]` (bit 7): 11th bit of the immediate value.
     - `opcode` (bits 6-0): Specifies the type of instruction.
   * **Usage:** B-Type instructions are used for conditional branching based on comparisons between `rs1` and `rs2`. Examples include `BEQ` (branch if equal) and `BNE` (branch if not equal).
### 5. **U-Type (Upper Immediate-Type) Instruction:**
![U-Type Instruction](https://github.com/user-attachments/assets/2698be73-4dd0-4939-9f10-abc44edf4d94) <br/>
***Figure 6. U-Type Instruction*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 23* <br/>
   * **Fields:**
     - `imm[31:12]` (bits 31-12): 20-bit immediate value.
     - `rd` (bits 11-7): Destination register.
     - `opcode` (bits 6-0): Specifies the type of instruction.
   * **Usage:** U-Type instructions are used to load a 20-bit immediate value into the upper 20 bits of a register. Example: `LUI` (load upper immediate).
### 6. **J-Type (Jump-Type) Instruction:**
![J-Type Instruction](https://github.com/user-attachments/assets/20827770-67f4-4f3f-a139-445805a16f55) <br/>
***Figure 7. J-Type Instruction*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 24* <br/>
   * **Fields:**
     - `imm[20]` (bit 31): 20th bit of the immediate value.
     - `imm[10:1]` (bits 30-21): Bits 10 through 1 of the immediate value.
     - `imm[11]` (bit 20): 11th bit of the immediate value.
     - `imm[19:12]` (bits 19-12): Bits 19 through 12 of the immediate value.
     - `rd` (bits 11-7): Destination register (used to store the return address).
     - `opcode` (bits 6-0): Specifies the type of instruction.
   * **Usage:** J-Type instructions are used for jump operations, such as `JAL` (jump and link), where the program jumps to a specific address and stores the return address in the destination register.

These formats show how different instruction types in RISC-V are encoded. They balance simplicity, flexibility, and compactness, making the architecture suitable for various types of operations.
</details>

<details>
<summary><h3>Subtask: 2. Identifying 15 unique RISC-V instructions from `Max_Min_Detector.o` Assembly Code along with the 32-Bit Instruction Code</h3></summary>
  
| Instruction No. | RISC_V Instruction | 32-Bit Instruction Code |
| :---: | :--- | :---: |
| 1.  | `lui     a0, 0x2b`       | `0002b537` | 
| 2.  | `addi    a0, a0, -544`   | `de050513` | 
| 3.  | `sd      s3, 40(sp)`     | `03313423` | 
| 4.  | `jal     ra, 10634`      | `55c000ef` | 
| 5.  | `li      s2, 5`          | `00500913` | 
| 6.  | `addiw   s0, s0, 1`      | `0014041b` |
| 7.  | `mv      a1, s0`         | `00040593` |
| 8.  | `bne     s0, s2, 100ec`  | `ff2410e3` |
| 9.  | `lw      a4, 8(sp)`      | `00812703` |
| 10. | `blt     a4, a2, 101dc`  | `0cc74063` |
| 11. | `sext.w  a5, a4`         | `0007079b` |
| 12. | `ld      s0, 64(sp)`     | `04013403` |
| 13. | `j       10174`          | `fcdff06f` |
| 14. | `ret`                    | `00008067` |
| 15. | `xor     a8, a1, a4`     | `0040C433` |
</details>

<details>
<summary><h3>Subtask: 3 & 4. Identifying Exact 32-bit Instruction Code in the Instruction Type format for above unique instructions and uploading it</h3></summary>
  
Here is the instruction breakdown for the given RISC-V instructions in the Instruction Type format:
#### 1. `lui a0, 0x2b`
- **Type**: U-Type
- **Opcode (LUI)**: `0110111` (7 bits)
- **rd (a0)**: x10 = `01010` (5 bits)
- **Immediate (0x2b)**: `00000000000000101011` (upper 20 bits)
- **32-bit instruction**: (`00000000000000101011 01011 0110111`)<sub>2</sub> = (`0002b537`)<sub>16</sub>
  
#### 2. `addi a0, a0, -544`
- **Type**: I-Type
- **Opcode (ADDI)**: `0010011` (7 bits)
- **rd (a0)**: x10 = `01010` (5 bits)
- **rs1 (a0)**: x10 = `01010` (5 bits)
- **funct3**: `000` (3 bits)
- **Immediate (-544)**: `110111100000` (12 bits, two's complement for -544)
- **32-bit instruction**: (`110111100000 01010 000 01010 0010011`)<sub>2</sub> = (`de050513`)<sub>16</sub>

#### 3. `sd s3, 40(sp)`
- **Type**: S-Type
- **Opcode (SD)**: `0100011` (7 bits)
- **rs1 (sp)**: x2 = `00010` (5 bits)
- **rs2 (s3)**: x19 = `10011` (5 bits)
- **funct3**: `011` (3 bits)
- **Immediate (40)**: `000000101000` (split into imm[11:5] and imm[4:0])
  - imm[11:5]: `0000001`
  - imm[4:0]: `01000`
- **32-bit instruction**: (`0000001 10011 00010 011 01000 0100011`)<sub>2</sub> = (`03313423`)<sub>16</sub>

#### 4. `jal ra, 10634`
- **Type**: J-Type
- **Opcode (JAL)**: `1101111` (7 bits)
- **rd (ra)**: x1 = `00001` (5 bits)
- **Immediate (10634)**: `010101110000` (split into imm[20|10:1|11|19:12])
  - imm[20] = `0`
  - imm[10:1] = `1010101110`
  - imm[11] = `0`
  - imm[19:12] = `00000000`
- **32-bit instruction**: (`0 1010101110 0 00000000 00001 1101111`)<sub>2</sub> = (`55c000ef`)<sub>16</sub>

#### 5. `li s2, 5`
- **Type**: I-Type
- **Opcode (ADDI)**: `0010011` (7 bits)
- **rd (s2)**: x18 = `10010` (5 bits)
- **rs1 (x0)**: x0 = `00000` (5 bits)
- **funct3**: `000` (3 bits)
- **Immediate (5)**: `000000000101` (12 bits)
- **32-bit instruction**: (`000000000101 00000 000 10010 0010011`)<sub>2</sub> = (`00500913`)<sub>16</sub>

#### 6. `addiw s0, s0, 1`
- **Type**: I-Type
- **Opcode (ADDIW)**: `0011011` (7 bits)
- **rd (s0)**: x8 = `01000` (5 bits)
- **rs1 (s0)**: x8 = `01000` (5 bits)
- **funct3**: `000` (3 bits)
- **Immediate (1)**: `000000000001` (12 bits)
- **32-bit instruction**: (`000000000001 01000 000 01000 0011011`)<sub>2</sub> = (`0014041b`)<sub>16</sub>

#### 7. `mv a1, s0`
- **Type**: I-Type
- **Opcode (ADDI)**: `0010011` (7 bits)
- **rd (a1)**: x11 = `01011` (5 bits)
- **rs1 (s0)**: x8 = `01000` (5 bits)
- **funct3**: `000` (3 bits)
- **Immediate (0)**: `000000000000` (12 bits)
- **32-bit instruction**: (`000000000000 01000 000 01011 0010011`)<sub>2</sub> = (`00040593`)<sub>16</sub>

#### 8. `bne s0, s2, 100ec`
- **Type**: B-Type
- **Opcode (BNE)**: `1100011` (7 bits)
- **rs1 (s0)**: x8 = `01000` (5 bits)
- **rs2 (s2)**: x18 = `10010` (5 bits)
- **funct3**: `001` (3 bits)
- **Immediate (100ec)**: `111111100100` (split into imm[12|10:5|4:1|11])
  - imm[12] = `1`
  - imm[10:5] = `111111`
  - imm[4:1] = `0000`
  - imm[11] = `1`
- **32-bit instruction**: (`1 111111 10010 01000 001 0000 1 1100011`)<sub>2</sub> = (`ff2410e3`)<sub>16</sub>

#### 9. `lw a4, 8(sp)`
- **Type**: I-Type
- **Opcode (LW)**: `0000011` (7 bits)
- **rd (a4)**: x14 = `01110` (5 bits)
- **rs1 (sp)**: x2 = `00010` (5 bits)
- **funct3**: `010` (3 bits)
- **Immediate (8)**: `000000000100` (12 bits)
- **32-bit instruction**: (`000000001000 00010 010 01110 0000011`)<sub>2</sub> = (`00812703`)<sub>16</sub>

#### 10. `blt a4, a2, 101dc`
- **Type**: B-Type
- **Opcode (BLT)**: `1100011` (7 bits)
- **rs1 (a4)**: x14 = `01110` (5 bits)
- **rs2 (a2)**: x12 = `01100` (5 bits)
- **funct3**: `100` (3 bits)
- **Immediate (101dc)**: `000110011000` (split into imm[12|10:5|4:1|11])
  - imm[12] = `0`
  - imm[10:5] = `000110`
  - imm[4:1] = `0000`
  - imm[11] = `0`
- **32-bit instruction**: (`0 000110 01100 01110 100 0000 0 1100011`)<sub>2</sub> = (`0cc74063`)<sub>16</sub>

#### 11. `sext.w a5, a4`
- **Type**: R-Type
- **Opcode (SLLIW)**: `0011011` (7 bits)
- **rd (a5)**: x15 = `01111` (5 bits)
- **rs1 (a4)**: x14 = `01110` (5 bits)
- **funct3**: `000` (3 bits)
- **rs2**: `00000` (5 bits)
- **funct7**: `0000000` (7 bits)
- **32-bit instruction**: (`0000000 00000 01110 000 01111 0011011`)<sub>2</sub> = (`0007079b`)<sub>16</sub>

#### 12. `ld s0, 64(sp)`
- **Type**: I-Type
- **Opcode (LD)**: `0000011` (7 bits)
- **rd (s0)**: x8 = `01000` (5 bits)
- **rs1 (sp)**: x2 = `00010` (5 bits)
- **funct3**: `011` (3 bits)
- **Immediate (64)**: `000000010000` (12 bits)
- **32-bit instruction**: (`000001000000 00010 011 01000 0000011`)<sub>2</sub> = (`04013403`)<sub>16</sub>

#### 13. `j 10174`
- **Type**: J-Type
- **Opcode (JAL)**: `1101111` (7 bits)
- **rd (x0)**: x0 = `00000` (5 bits)
- **Immediate (10174)**: `111111110100` (split into imm[20|10:1|11|19:12])
  - imm[20] = `1`
  - imm[10:1] = `1111100110`
  - imm[11] = `1`
  - imm[19:12] = `11111111`
- **32-bit instruction**: (`1 1111100110 1 11111111 00000 1101111`)<sub>2</sub> = (`fcdff06f`)<sub>16</sub>

#### 14. `ret`
- **Type**: I-Type
- **Opcode (JALR)**: `1100111` (7 bits)
- **rd (x0)**: x0 = `00000` (5 bits)
- **rs1 (ra)**: x1 = `00001` (5 bits)
- **funct3**: `000` (3 bits)
- **Immediate (0)**: `000000000000` (12 bits)
- **32-bit instruction**: (`000000000000 00001 000 00000 1100111`)<sub>2</sub> = (`00008067`)<sub>16</sub>

#### 15. `xor a8, a1, a4`
- **Type**: R-Type
- **Opcode (XOR)**: `0110011` (7 bits)
- **rd (a8)**: x8 = `01000` (5 bits)
- **rs1 (a1)**: x1 = `00001` (5 bits)
- **rs2 (a4)**: x4 = `00100` (5 bits)
- **funct3**: `100` (3 bits)
- **funct7**: `0000000` (7 bits)
- **32-bit instruction**: (`0000000 00100 00001 100 01000 0110011`)<sub>2</sub> = (`0040C433`)<sub>16</sub>
</details>

</details>

### Visit [Task 3](https://github.com/Kedard37/VSDSquadron_Mini_Internship/tree/main/Task%203) directory to get more information about this task!

---

<details>
<summary><h2>Task: 4. Functional Simulation and Waveform Analysis of RISC-V Core Using Verilog Netlist</h2></summary>

#### Recording-4: https://1drv.ms/v/s!Ai4WW_jutengiocZFrhHrTi2EYFAqA?e=nn2Xee
- [x] Use this [RISC-V Core Verilog netlist](https://github.com/vinayrayapati/rv32i/blob/main/iiitb_rv32i.v) and [testbench](https://github.com/vinayrayapati/rv32i/blob/main/iiitb_rv32i_tb.v) for functional simulation experiment.
- [x] Upload waveform snapshots for the commands on your GitHub.
- [x] Reference GitHub repo is [here](https://github.com/vinayrayapati/rv32i/).

## Task 4 Output:
**IMPORTANT!**
> Please note that designing the RISC-V Architecture and creating its Testbench are not within the scope of this research internship. Therefore, I have utilized the existing RTL Description and Testbench for the RISC-V Architecture, **with minor modifications**, which has already been developed by Vinay Rayapati and Kunal Ghosh. </br>
> *The reference GitHub repository is: [iiitb_rv32i](https://github.com/vinayrayapati/rv32i/).*

### Waveform Analysis of RISC-V Core Instruction Set:
#### The Differences between Standard RISC-V ISA and the Instruction Set used in the reference repository:  
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

**NOTES!**
> - **BNE**: Branch if not equal; jumps to a specified instruction if two registers are not equal.
>    - **Operation**: `EX_MEM_ALUOUT <= ID_EX_NPC+ID_EX_IMMEDIATE;` 
>    - **32-bit OP Code**: (`01409002`)<sub>16</sub> 
> - **LW**: Load word; loads a 32-bit word from memory into a register.
>    - **Operation**: `LW  :EX_MEM_ALUOUT <= ID_EX_A + ID_EX_IMMEDIATE;` 
>    - **32-bit OP Code**: (`00208681`)<sub>16</sub> 
> - **SRL**: Shift right logical; shifts the bits in a register to the right by a specified amount, filling with zeros.
>    - **Operation**: `SRL:EX_MEM_ALUOUT <= ID_EX_A >> ID_EX_B;` 
>    - **32-bit OP Code**: (`00271803`)<sub>16</sub>

</details>

### Visit [Task 4](https://github.com/Kedard37/VSDSquadron_Mini_Internship/tree/main/Task%204) directory to get the codes, linux commands to run a simulation on iverilog & more information about this task!

---

<details>
<summary><h2>Task: 5. Designing an Application to implement on the VSDSquadron Mini Board</h2></summary>

#### Recording-5: https://1drv.ms/v/s!Ai4WW_jutengioh8MuA8BX0hiGfEmQ?e=N4GmAb
- [x] Update the repo with Project Name, Overview, Components Required to build your Application, Circuit Connection, Pinout Diagram and Table for Pin Connection.

# Task 5 Output:
## Project Name:
### Implementation of a Decade Up & Down Counter using VSDSquadron Mini Board.

## Overview:
The **Decade Up & Down Counter** project showcases a digital counting system designed to increment or decrement through a sequence of ten states, ranging from 0 to 9. This counter is built to count either up or down based on a control input, making it versatile for various applications where sequential counting is required. At the heart of the system is a flip-flop-based architecture or a dedicated counter IC, which tracks the current count and modifies it according to the user's input for up or down counting. Here, we are using a RISC-V based processor to execute the same.

The counter continuously cycles through the ten states in a loop, resetting to 0 after reaching 9 when counting up or transitioning back to 9 from 0 when counting down. This cyclical counting feature makes the Decade Up/Down Counter ideal for applications in digital clocks, timers, frequency division, and other counting-based circuits. The project demonstrates precise, reliable counting and offers users a flexible, programmable solution for tasks that require accurate sequential control in digital systems.

## Components Required:
1. VSDSquadron Mini Board - CH32V003x RISC-V based Microprocessors (Qty. 1)
2. 7 Segment Display - Common Cathode - SUN056CC (Qty. 1)
3. 3 Terminal Slide Switch (Qty. 1)
4. 1KΩ Resistor (Qty. 1)
5. Breadboard - Small (Qty. 1)
6. Jumper Wires (Qty. As per your Requirement)
7. Power Bank - To Power the Circuit (Qty. 1) - Any other Power Sources can be used

## Circuit Connections:
![Decade Up & Down Counter Circuit Diagram](https://github.com/user-attachments/assets/ac190bbe-9002-4a09-bed6-e941a6fd632f) </br>
***Figure 1. Decade Up & Down Counter Circuit Diagram***

The circuit integrates a **7-segment display** with the **VSDSquadron Mini** microcontroller to display numbers from 0 to 9, forming a MOD-10 counter. Each segment of the 7-segment display (labeled A to G) is connected to specific digital pins on the VSDSquadron Mini. The segment pins is connected as follows: segment ***'A'*** to **PD1**, ***'B'*** to **PD2**, ***'C'*** to **PD3**, ***'D'*** to **PD4**, ***'E'*** to **PD5**, ***'F'*** to **PD6**, ***'G'*** to **PD7** and ***'DP'*** to **GND** on the microcontroller. Current-limiting resistor is added in series with each segment pin to protect the LEDs in the display. The common ground pin of the 7-segment display is connected to the **GND** pin of the microcontroller, and the display is powered by the **5V** supply from the VSDSquadron Mini.

A **3-terminal switch** is also used to toggle between up-counting and down-counting modes. The common terminal of the switch is connected to **PD0**, while the other two terminals are connected to **GND** and **5V** on the microcontroller. This configuration allows the microcontroller to read the switch’s state and determine the counting direction. When the switch connects **PD0** to **GND**, the microcontroller interprets it as an down-count command; when **PD0** is connected to **5V**, it counts up. The microcontroller reads these signals, incrementing the count for up mode and decrementing it for down mode, providing dynamic control over the counting direction.

## Pinout Diagram:
![Decade Up & Down Counter Pinout Diagram](https://github.com/user-attachments/assets/15ac4125-31ae-45e2-9a2e-f479514142b4) </br>
***Figure 2. Decade Up & Down Counter Pinout Diagram***

## Table for Pin Connection:
| VSDSquadron Mini Board | 7 Segment Display (Common Cathode) |
| :----: | :----: |
| PD1 | **A** - Pin 7 |
| PD2 | **B** - Pin 6 |
| PD3 | **C** - Pin 4 |
| PD4 | **D** - Pin 2 |
| PD5 | **E** - Pin 1 |
| PD6 | **F** - Pin 9 |
| PD7 | **G** - Pin 10 |
| GND | **DP** - Pin 5 |
| GND | **GND** - Pin 3, 8 |

| VSDSquadron Mini Board | 3 Terminal Slide Switch |
| :----: | :----: |
| 5V | Terminal 1 |
| PD0 | Common Terminal |
| GND | Terminal 2 |

</details>

### Visit [Task 5](https://github.com/Kedard37/VSDSquadron_Mini_Internship/tree/main/Task%205) directory to check out for Circuit and Pinout Diagrams!

---
