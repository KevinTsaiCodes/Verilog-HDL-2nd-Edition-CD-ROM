
//Pin-to-pin delays
module M (out, a, b, c, d);
output out;
input a, b, c, d;

wire e, f;

//Specify block with path delay statements
specify
	(a => out) = 9;
	(b => out) = 9;
	(c => out) = 11;
	(d => out) = 11;
endspecify

//gate instantiations
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


