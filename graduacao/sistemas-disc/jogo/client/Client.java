package client;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

import game.Game;

public class Client{

    // Método auxiliar para limpar o terminal usando comandos ANSI
    public static void clearConsole() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public static void main(String[] args) throws Exception {
        try{
            // Conecta-se ao objeto remoto usando o nome lógico "GameService"
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);;
            Game game = (Game) registry.lookup("GameService");
            Scanner sc = new Scanner(System.in);

            // Solicita registro do jogador
            int playerId = game.registerPlayer();
            if (playerId == -1) {
                System.out.println("⚠️  Jogo cheio! Apenas 3 jogadores permitidos.");
                return;
            }

            // Confirmação de registro
            System.out.println("✅ Você foi registrado como Jogador " + playerId);
            Thread.sleep(1000); // Pausa breve para leitura

            // Aguarda até que todos os 3 jogadores estejam conectados
            while(!game.getAllPlayersConnect());

            // Loop principal do jogo
            while (!game.isGameOver()) {
                clearConsole(); // Limpa o terminal para nova rodada

                System.out.println("🎮 Jogador " + playerId + "\n");
                System.out.println(game.getBoardAsString()); // Mostra o tabuleiro atualizado
                
                // Se não for a vez do jogador, espera e reinicia o loop
                if (game.getCurrentTurn() != playerId) {
                    System.out.println("⏳ Aguardando vez do jogador " + game.getCurrentTurn() + "...");
                    Thread.sleep(1500);
                    continue;
                }

                int row, col;

                try{
                    // Lê a posição da jogada
                    System.out.println("👉 Sua vez! Digite sua jogada:");
                    System.out.print("Linha (0-4): ");
                    row = Integer.parseInt(sc.nextLine());

                    System.out.print("Coluna (0-4): ");
                    col = Integer.parseInt(sc.nextLine());
                }
                catch(Exception ex){
                    // Trata entradas inválidas (ex: letras, valores vazios)
                    System.out.println("❌ Jogada inválida! Tente novamente.");
                    Thread.sleep(1500);
                    continue;
                }

                // Tenta fazer a jogada
                boolean success = game.makeMove(row, col, playerId);

                if (!success) {
                    // Jogada rejeitada (posição ocupada ou fora da vez)
                    System.out.println("❌ Jogada inválida! Tente novamente.");
                    Thread.sleep(1500);
                }
            }  

            // Fim do jogo: limpa tela e mostra resultado final
            clearConsole();
            System.out.println("🏁 Fim de jogo!\n");
            System.out.println(game.getBoardAsString());

            // Mostra o resultado
            int winner = game.checkWinner();
            if (winner == -1) {
                System.out.println("🤝 Empate!");
            } else if (winner == playerId) {
                System.out.println("🎉 Você venceu!");
            } else {
                System.out.println("😢 O jogador " + winner + " venceu.");
            }
        } catch(Exception e){
            System.err.println("Erro no Cliente:");
            e.printStackTrace();
        }
        
    }
}
