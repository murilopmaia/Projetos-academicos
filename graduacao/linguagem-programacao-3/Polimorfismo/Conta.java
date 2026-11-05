/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Polimorfismo;

/**
 *
 * @author Admin
 */
public class Conta implements Pix{
    
    protected double saldo;
    
    public double getSaldo()
    {
        return saldo;
    }
    
    public void setSaldo(double pSaldo)
    {
        this.saldo = pSaldo;
    }
    
    public double Sacar(double pValor)
    {
        System.out.println(" Classe Conta : Método Sacar(valor)");        
        this.saldo = this.saldo - pValor;
        return this.saldo;
    }

    public void Pagar(double pValor)
    {
        
        this.saldo = this.saldo - pValor;
        
    }
    
    public void Receber(double pValor)
    {

        this.saldo = this.saldo + pValor; 
        
    }
    
}
