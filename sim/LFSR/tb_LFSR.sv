module tb_LFSR();

	reg clk, rst_n;
	wire [4:0] LFSR_out;

	LFSR dut
	(
		.clk(clk), 
		.rst_n(rst_n),
		.LFSR_out(LFSR_out)
	);

	int count = 0;

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$display("Reset in the beginning.");
		rst_n = 0; #10; rst_n = 1;

		$display("Test all the value");
		while(count != 50)
			@(posedge clk)
				count++;
		$display("The output are all correct");
		$stop;
	end
endmodule
