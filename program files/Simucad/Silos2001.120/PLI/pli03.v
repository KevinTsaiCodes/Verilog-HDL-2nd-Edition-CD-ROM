//	This example illustrates how to use a C model instead of a behavioral module.
//      Possible uses would be to protect intellectual property or write models in C
//	that would be awkward to write in HDL code.

`timescale 1ns / 1ps

module testbench;

  reg in;

  cut test(in, t1, out);

  initial
    fork
      #0 in = 0;
      #1 in = 1;
      #2 in = 0;
      #3 in = 1;
      #4 $finish;
    join

  initial 
    begin
      $timeformat(-9, 3, "ns", 8);
      $monitor("%t %b %b %b", $time, in, t1, out);
    end

endmodule

module cut(in, t1, out);
  input in;
  output t1;
  output out;

  mymodel i1(in, t1),
          i2(t1, out);
endmodule

