module stimulus;
wire OUT;
reg A,B,C,D;
wire OUT1;
reg A1,B1,C1,D1;

M  my(OUT, A,B,C,D);
M1 my1(OUT1, A1,B1,C1,D1);


initial
begin
$monitor($time, 
" A=%b, B=%b, C=%b, D=%b, OUT=%b,  A1=%b, B1=%b, C1=%b, D1=%b, OUT1=%b",
	A,B,C,D, OUT, A1,B1,C1,D1, OUT1);
	A = 1; B = 1; C = 1; D= 1;
	A1 = 1; B1 = 1; C1 = 1; D1= 1;
	#5 A = 0; B = 1; C = 1; D= 1;
	A1 = 0; B1 = 1; C1 = 1; D1= 1;
	#5 A = 1; B = 0; C = 1; D= 1;
	A1 = 1; B1 = 0; C1 = 1; D1= 1;
	#5 A = 1; B = 1; C = 0; D= 1;
	A1 = 1; B1 = 1; C1 = 0; D1= 1;
	#5 A = 1; B = 1; C = 1; D= 0;
	A1 = 1; B1 = 1; C1 = 1; D1= 0;
end
endmodule


//Distributed delays in gate level modules
module M (out, a, b, c, d);
output out;
input a, b, c, d;

wire e, f;

//Distributed delay in each gate.
and #5 a1(e, a, b);
and #7 a2(f, c, d);
and #4 a3(out, e, f);
endmodule

//Distributed delays in data flow definition of a module
module M1 (out, a, b, c, d);
output out;
input a, b, c, d;

wire e, f;

//Distributed delay in each expression
assign #5 e = a & b;
assign #7 f = c & d;
assign #4 out = e & f;
endmodule



