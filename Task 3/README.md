# Task 3 Output:
## Subtask 1. Listing the RISC-V Instruction Types [R, I, S, B, U, J]:
![RISC-V Instruction Types](https://github.com/user-attachments/assets/9d0cf4e8-4a7c-4c0c-bc32-505818c5a9e5) <br/>
***Figure 1. RISC-V Instruction Types*** <br/>
*Source: RISC-V, Specifications, Volume 1, Unprivileged Specification version 20240411, Page 24* <br/>

The above figure shows the instruction formats for various RISC-V instruction types. Each of them are described in detail below:

---

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

---

These formats show how different instruction types in RISC-V are encoded. They balance simplicity, flexibility, and compactness, making the architecture suitable for various types of operations.

## Subtask 2. Identifying 15 unique RISC-V instructions from `Max_Min_Detector.o` Assembly Code along with the 32-Bit Instruction Code:
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

## Subtask 3 & 4. Identifying Exact 32-bit Instruction Code in the Instruction Type format for above unique instructions and uploading it:
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
