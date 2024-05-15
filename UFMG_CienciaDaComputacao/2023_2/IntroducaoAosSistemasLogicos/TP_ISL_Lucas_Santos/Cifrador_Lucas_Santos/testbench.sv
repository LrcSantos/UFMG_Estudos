// Módulo de teste para o cifrador
module cifra #(parameter BITS = 64);
 // Registrador de tamanho 64, contendo a palavra "estrelas" em ASCII
 reg [BITS-1:0] in = 64'b01100101_01110011_01110100_01110010_01100101_01101100_01100001_01110011;
 // Registrador de tamanho 32, contendo o OTP
  reg [BITS/2-1:0] otp = 32'b01100110_01101001_01110110_01100101;
 // Registradores e fios auxiliares, para cifrar a mensagem bit-a-bit.
 // A saída precisa ser um fio, pois a porta XOR precisa produzir seu sinal
 // em um meio que permita atribuição contínua.
 reg a, b;
 wire out;
 // Instanciação da porta XOR
 xor_gate xorg(.a(a), .b(b), .out(out));

 // Inicialização do arquivo VCD para simulação
 initial begin
   $dumpfile("dump.vcd");
   $dumpvars(1, a, b, out);
 end

 // Contador do loop for
 integer i;
 integer bits_per_group = 8; // Número de bits por grupo
 integer bits_counter = 0;  // Contador de bits no grupo

 // Inicialização do loop for para cifrar a mensagem bit-a-bit
 initial begin
   for(i = BITS-1; i >= 0; i = i - 1) begin
     a = in[i];
     b = (i >= BITS/2) ? otp[i-BITS/2] : otp[i];
     
     #1
     // Exibe o bit atual
     $write(out);

     // Contagem de bits no grupo
     bits_counter = bits_counter + 1;

     // Adiciona espaço entre grupos
     if (bits_counter == bits_per_group) begin
       $write(" ");
       bits_counter = 0;
     end
   end

   // Adiciona uma quebra de linha no final
   $write("\n");
 end
endmodule