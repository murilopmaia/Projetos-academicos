/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Polimorfismo;

/**
 *
 * @author Admin
 */
public class Principal {
 
    public static void main(String args[])
    {
        Conta[] contas = new Conta[5];
    
        contas[0] = new Conta();
        contas[1] = new ContaCorrente();
        contas[2] = new ContaPoupanca();
        contas[3] = new Conta(); 
        contas[4] = new ContaCorrente(); 
        
        for(Conta aux : contas)
        {
            aux.Sacar(100);
        }      
    }
    
    Pix a = new ContaCorrente();
    

    
    
    
}
