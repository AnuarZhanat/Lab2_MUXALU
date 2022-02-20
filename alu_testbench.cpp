// Verilator generated library/class.
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
