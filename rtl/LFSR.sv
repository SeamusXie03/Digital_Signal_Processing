`default_nettype none
module LFSR #(parameter NUM_BITS = 5)
(
	input wire clk, // needs 1Hz
	input wire rst_n,
	output wire [NUM_BITS-1:0] LFSR_out
);
	localparam start_val = 1;

	reg [NUM_BITS-1:0] register = start_val;
	assign LFSR_out = register;

	// This is the tap location
	wire feedback_path = register[0] ^ register[2];

	// generate registers to have a LFSR
	genvar i;
	generate
		for (i = NUM_BITS-1; i >= 0; i--) begin: generate_LSFR
			if (i == NUM_BITS-1)
				always_ff @(posedge clk, negedge rst_n)
					if (~rst_n)
						register[i] <= start_val[i];
					else
						register[i] <= feedback_path;
			else 
				always_ff @(posedge clk, negedge rst_n)
					if (~rst_n)
						register[i] <= start_val[i];
					else
						register[i] <= register[i+1];
		end
	endgenerate
endmodule
`default_nettype wire
