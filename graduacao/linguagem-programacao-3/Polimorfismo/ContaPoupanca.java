/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Polimorfismo;

/**
 *
 * @author Admin
 */
public class ContaPoupanca extends Conta{
    
    public double rendimento;
    
    @Override
    public double Sacar(double pValor)
    {
        System.out.println(" Classe ContaPoupanca : Método Sacar(valor)");
        this.saldo = this.saldo - pValor;
        this.rendimento = 0;
        return this.saldo;
    }    
    
    
}
