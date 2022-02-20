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
