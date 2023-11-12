`default_nettype none
module signal_display 
(
	input wire [11:0] sine, 
	input wire [11:0] cos, 
	input wire [11:0] saw, 
	input wire [11:0] squ,
	input wire [11:0] ASK, 
	input wire [11:0] BPSK, 
	input wire [11:0] FSK,
	input wire [11:0] LFSR,
	input wire [1:0] modulation_selector,
	input wire [1:0] signal_selector,
	output reg [11:0] selected_modulation,
	output reg [11:0] selected_signal
);
	always_comb
		case(modulation_selector)
			2'd0: selected_modulation = ASK;
			2'd1: selected_modulation = FSK;
			2'd2: selected_modulation = BPSK;
			2'd3: selected_modulation = LFSR;
		endcase

	always_comb
		case(signal_selector)
			2'd0: selected_signal = sine;
			2'd1: selected_signal = cos;
			2'd2: selected_signal = saw;
			2'd3: selected_signal = squ;
		endcase
endmodule
`default_nettype wire
