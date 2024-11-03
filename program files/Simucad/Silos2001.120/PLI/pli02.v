// PLI example for initializing memory

module test;
  reg [3:0] mem4[0:15];
  integer   ndx;

  initial
    begin
      // Method 1, passing each memory element at a time
      for (ndx = 0; ndx < 16; ndx = ndx + 1)
        $pli02(ndx, mem4[ndx]);

      // Display contents
      for (ndx = 0; ndx < 16; ndx = ndx + 1)
        $display("%d %d", ndx, mem4[ndx]);

      // Reset memory to Unknown.
      for (ndx = 0; ndx < 16; ndx = ndx + 1)
          mem4[ndx] = 4'bx;

      // Method 2, fill the entire memory at once
      $pli02a();

      // Display contents
      for (ndx = 0; ndx < 16; ndx = ndx + 1)
        $display("%d %b", ndx, mem4[ndx]);

      $finish;
    end
endmodule

