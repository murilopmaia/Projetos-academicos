// Inicia o servidor

package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

import game.Game;
import game.GameImpl;

public class Server {
    public static void main(String[] args) throws Exception {
        try{
            // Instancia o objeto remoto
            GameImpl game = new GameImpl();
            Game stub = (Game) UnicastRemoteObject.exportObject(game, 1099);

            // Cria o registry na porta padrão 1099
            Registry registry = LocateRegistry.createRegistry(1099); 
            // Registra o objeto com nome lógico
            registry.rebind("GameService", stub); 

            System.out.println("Servidor pronto."); 
        } catch(Exception e){
            System.err.println("Erro no servidor:");
            e.printStackTrace();
        }
        
    }
}
