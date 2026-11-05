/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Polimorfismo;

/**
 *
 * @author Admin
 */
public class ContaCorrente extends Conta{
    
    public double limite;
    
    @Override
    public double Sacar(double pValor)
    {
        System.out.println(" Classe ContaCorrente : Método Sacar(valor)");
        this.saldo = this.saldo - pValor;
        return this.saldo;
    }  
    
    
    
}
