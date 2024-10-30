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

## Subtask 2. Identifying 15 unique RISC-V instructions from `Max_Min_Detector.o` Assembly Code:
