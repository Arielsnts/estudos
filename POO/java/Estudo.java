package POO.java;
import java.util.Scanner;

public class Estudo {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Digite um número inteiro: ");
        int num = input.nextInt();

        int ultimo = 0, soma = 0;
        while (num != 0) {
            ultimo = num % 10;
            
            int fat = 1;
            for (int i = 1; i <= ultimo; i++) {
                fat *= i;
            }

            soma += fat;

            num /= 10;
        }

        System.out.println("Saída: " + soma);

        input.close();
    }
}
