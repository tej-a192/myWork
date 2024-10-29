import java.util.*;
import java.math.*;

class RSA {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter Message: ");
        String message = s.nextLine();
        System.out.println();

        /* Key Generation */

        // Two large primes taken
        BigInteger p = BigInteger.valueOf(15485863);
        BigInteger q = BigInteger.valueOf(32452843);

        // Modulus
        BigInteger n = p.multiply(q);    

        // 𝜙(N)
        BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));

        // Public exponent and private exponent
        int e = 5; // 1 < e < 𝜙(N) & GCD(e, 𝜙(N)) = 1
        
        BigInteger d = BigInteger.valueOf(e).modInverse(phi); // d = modularInverse(e, phi)

        System.out.println("Public Key (e, n): (" + e + ", " + n + ")");
        System.out.println("Private Key (d, n): (" + d + ", " + n + ")");

        // Convert message to BigInteger
        BigInteger msg = new BigInteger(message.getBytes());

        // Encrypt the message
        BigInteger C = msg.modPow(BigInteger.valueOf(e), n);
        System.out.println("Encrypted Message is: " + C);

        // Decrypt the message
        BigInteger M = C.modPow(d, n);
        
        // Convert back to string
        String decryptedMessage = new String(M.toByteArray());

        // Print decrypted message
        System.out.println("Decrypted Message: " + decryptedMessage);
    }
}