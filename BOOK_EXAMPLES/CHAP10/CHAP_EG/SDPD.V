//Conditional Path Delays
module M (out, a, b, c, d);
output out;
input a, b, c, d;

wire e, f;

//Conditional pin-to-pin timing
specify

//different pin-to-pin timing based on state of signal a.
if (a) (a => out) = 9;
if (~a) (a => out) = 10;

//Conditional expression contains two signals b , c.
//If b & c is true, delay = 9, 
//otherwise delay = 13.
if (b & c) (b => out) = 9;
if (~(b & c)) (b => out) = 13;

//Use concatenation operator
if ({c,d} == 2'b01) 
				(c,d *> out) = 11;
if ({c,d} != 2'b01) 
				(c,d *> out) = 13;

endspecify

and a1(e, a, b);
and a2(f, c, d);
and a3(out, e, f);
endmodule

module stimulus;
wire OUT;
reg A,B,C,D;
 

M  my(OUT, A,B,C,D);
 

initial
begin
$monitor($time, 
" A=%b, B=%b, C=%b, D=%b, OUT=%b ",
	A,B,C,D, OUT);
	A = 1; B = 1; C = 1; D= 1;
	 
	#5 A = 0; B = 1; C = 1; D= 1;
	 
	#5 A = 1; B = 0; C = 1; D= 1;
	 
	#5 A = 1; B = 1; C = 1; D= 1;
	 
	#5 A = 1; B = 1; C = 1; D= 0;
	 
end
endmodule


