module KedarD_rv32i_tb;

reg clk,RN;
wire [31:0]WB_OUT,NPC;

KedarD_rv32i rv32(clk,RN,NPC,WB_OUT);


always #1 clk=!clk;

initial begin 
RN  = 1'b1;
clk = 1'b1;

$dumpfile ("KedarD_rv32i.vcd"); //by default vcd
$dumpvars (0, KedarD_rv32i_tb);
  
  #3 RN = 1'b0;
  
  #47 $finish;

end
endmodule
