// Módulo para a porta XOR implementada no estilo estrutural
module xor_gate(a, b, out);
 input a, b;
 output out;
 wire a_bar, b_bar, x, y;
 
 // Complemento (inverso) das entradas
 not a_inv (a_bar, a);
 not b_inv (b_bar, b);
 
 // AND gates para a implementação da XOR
 and a1 (x, a_bar, b);
 and a2 (y, a, b_bar);
 
 // OR gate para a saída da XOR
 or or1 (out, x, y);
endmodule

// Módulo do Flip-Flop D
module d_flip_flop (
 input wire clk,
 input wire rst,
 input wire d,
 output reg q
);

 always @(posedge clk or posedge rst) begin
   if (rst) begin
     q <= 1'b0; // Reseta o flip-flop
   end else begin
     q <= d;    // Atualiza o flip-flop com os dados de entrada
   end
 end

endmodule

// Módulo do Registrador de Deslocamento
module shift_register #(parameter WIDTH = 32)(
 input wire clk,
 input wire rst,
 input wire [WIDTH-1:0] data_in,
 input wire shift_enable,
 output reg [WIDTH-1:0] data_out
);

 always @(posedge clk or posedge rst) begin
   if (rst) begin
     data_out <= {WIDTH{1'b0}}; // Reseta o registrador de deslocamento
   end else begin
     if (shift_enable) begin
       data_out <= {data_in[WIDTH-1], data_out[WIDTH-1:1]}; // Desloca os dados
     end
   end
 end

endmodule

// Módulo do Cifrador de Fluxo
module stream_cipher #(parameter BITS = 64)(
 input wire clk,
 input wire rst,
 input wire [BITS-1:0] message,
 input wire [BITS/2-1:0] otp,
 output reg [BITS-1:0] ciphered_message
);

 wire [BITS-1:0] shift_register_out;

 // Instanciação do registrador de deslocamento
 shift_register #(BITS) sr (
   .clk(clk),
   .rst(rst),
   .data_in(message),
   .shift_enable(1'b1),
   .data_out(shift_register_out)
 );

 // Operação XOR para criptografia
 always @(posedge clk or posedge rst) begin
   if (rst) begin
     ciphered_message <= 0; // Reseta a mensagem cifrada
   end else begin
     // Atualiza a mensagem cifrada usando a saída do registrador de deslocamento e o OTP
     ciphered_message <= shift_register_out ^ {otp, {BITS/2{1'b0}}};
   end
 end

endmodule