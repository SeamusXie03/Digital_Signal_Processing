`default_nettype none
module doublesync #(parameter N = 1)
(
	input wire clk,
	input wire reset,
	input wire [N-1:0] indata,
	output wire [N-1:0] outdata
);

	reg [N-1:0] reg1, reg2;
	
	always @(posedge clk or negedge reset)
	begin
		 if (!reset)
		 begin
		 	reg1 <= {N{1'b0}};
			reg2 <= {N{1'b0}};
		 end else 
		 begin
		 	reg1 <= indata;
			reg2 <= reg1;
		 end
	end
	
	assign outdata = reg2;
endmodule
`default_nettype wire
