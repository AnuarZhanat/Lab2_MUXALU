/* verilator lint_off WIDTH */
/* verilator lint_off CASEINCOMPLETE */

module MUX(input [7:0] a1,
           input [7:0] a2,
           input [7:0] a3,
           input [7:0] a4,
           input [7:0] a5,
           input [7:0] a6,
           input [7:0] a7,
           input [7:0] a8,
           input [7:0] a9,
           input [7:0] a10,
           input [1:0] sel,
           output [7:0] out);
                      
       reg [7:0] outcase;
       
   always @ (a1 or a2 or a3 or a4 or a5 or a6 or a7 or a8 or a9 or a10 or sel) begin
   
   	case (sel)
   		4'b0000 : outcase = a1;
   		4'b0001 : outcase = a2;
   		4'b0010 : outcase = a3;
   		4'b0011 : outcase = a4;
   		4'b0100 : outcase = a5;
   		4'b0101 : outcase = a6;
   		4'b0110 : outcase = a7;
   		4'b0111 : outcase = a8;
   		4'b1000 : outcase = a9;
   		4'b1001 : outcase = a10;
   	endcase
   end
   
       assign out = outcase;
       
 endmodule 
