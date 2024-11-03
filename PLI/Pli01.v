////////////////////////////////////////////////////////////////////////
//
// title: testbench for tf_putp() test to write a simple value 
//
// This test writes a value to a scalar reg data type
//
////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ns
module test;

  reg r1;

  initial
    begin
      #1
      $display("\nTest Bench: executing \"$putp_test(r1);\" ");
      $display("Test Bench: expect tfarg 1 to receive 1 (hex)");
      $putp_test(r1);
      #1
      $display("Test Bench: tfarg 1 received %h (hex)", r1);

      #1 $display("\n\n--------End of Test Bench--------");
      $finish;
    end
endmodule
`ifdef silos
!sim
!err
!exit
`endif
