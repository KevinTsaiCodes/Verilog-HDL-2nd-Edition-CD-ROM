module test_bench;

wire out;
reg s, i1, i0;

mux mux1(out, s, i1, i0);

endmodule

module  mux (out, s, i1, i0);

output out;
input s, i1, i0;

assign out = (s) ? i1 : i0;

endmodule
