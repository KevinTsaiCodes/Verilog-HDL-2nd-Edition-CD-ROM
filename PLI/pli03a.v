`timescale 1ps / 1ps

module mymodel(in, out);
  input in;
  output out;

  reg out_;
  assign out = out_;

  /*
   * $mymodel is a simple buffer with delay.
   */
  initial $mymodel(in, out_);
endmodule
