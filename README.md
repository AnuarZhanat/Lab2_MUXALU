# Lab2_MUXALU

The YouTube video link: https://youtu.be/eO44ESdgk_s

## Part1.a
The module was created by:
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
 
## Part1.b
 The test bench implemented by:
 
// Verilator generated library/class.
#include "VMUX.h"

// Verilator libraries.
#include "verilated.h"
#include "verilated_vcd_c.h"

// C++ libraries.
#include <iostream>

int main()
{
  VMUX* design_under_test = new VMUX();
  
  Verilated::traceEverOn(true);
  VerilatedVcdC *tfp = new VerilatedVcdC;
  design_under_test->trace(tfp, 99);
  tfp->open("mux.vcd");
  
  int cases = 0; 
  
  while (cases < 100000) {
  
    // Value generator.
    int input[10];
    for (int k = 0; k < 10; k++)
      input[k] = (rand() % 256);
    int select = rand() % 10;

    // Feed data to DUT.
    design_under_test->a1 = input[0];
    design_under_test->a2 = input[1];
    design_under_test->a3 = input[2];
    design_under_test->a4 = input[3];
    design_under_test->a5 = input[4];
    design_under_test->a6 = input[5];
    design_under_test->a7 = input[6];
    design_under_test->a8 = input[7];
    design_under_test->a9 = input[8];
    design_under_test->a10 = input[9];
    design_under_test->sel = select;

    // Model the behavior of the DUT.
    int expected_out = input[select];

    // Simulate/evaluate/progress time.
    cases++;
    design_under_test->eval();
    tfp->dump(cases);

    // Compare results.
    int out = (int)design_under_test->out;
    bool success = (out == expected_out);

    if (!success)
    {
      std::cout << "Test failed :(" << std::endl;
    }
    else
    {
      std::cout << "Test passed!" << std::endl;
    }
  }

  tfp->close();

  return 0;
}

## Part2.a
  The alu was created by:
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
  
  
  
## Part2.b
The test bench was implemented:
  / Verilator generated library/class.
#include "VALU.h"

// Verilator libraries.
#include "verilated.h"
#include "verilated_vcd_c.h"

// C++ libraries.
#include <iostream>

int main()
{
    VALU* design_under_test = new VALU();
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    design_under_test->trace(tfp, 99);
    tfp->open("alu.vcd");

 int cases = 0; 
  
  while (cases < 100000) {
        // Value generator.
        int x = rand() % 256;
        int y = rand() % 256;
        int op = rand() % 2;

        // Feed data to DUT.
        design_under_test->x = x & 0b11111111;
        design_under_test->y = y & 0b11111111;
        design_under_test->op = op;

        // Model the behavior of the DUT.
        int expected_result = 0b111111111 & ((op == 0) ? (x + y) : (x - y));

        // Simulate/evaluate/progress time.
        cases++;
        design_under_test->eval();
        tfp->dump(cases);

        // Compare results.
        int out = (int)design_under_test->out;

        bool success = (out == expected_result);

        if (!success)
        {
            std::cout << "Test failed :(" << std::endl;
        }
        else
    	{
      	    std::cout << "Test passed!" << std::endl;
   	}	
    }

    tfp->close();

    return 0;
}

  
  
