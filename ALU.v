module ALU(input [7:0] x,
           input [7:0] y,
           input op,
           output[8:0] out);

 reg [8:0] outcase;

always @* begin
   
   	case (op)
   		1'b0 : outcase = x + y;
   		default : outcase = x - y;
   	endcase
   end

assign out = outcase;

endmodule
