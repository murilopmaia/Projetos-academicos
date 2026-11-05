// Interface remota

package game;

import java.rmi.Remote;
import java.rmi.RemoteException;

// A interface Game define os métodos que poderão ser acessados remotamente via RMI
public interface Game extends Remote {

    /*
      Tenta realizar uma jogada na posição (row, col) para o jogador com ID playerId.
      @return true se a jogada foi válida e realizada com sucesso; false caso contrário.
    */
    boolean makeMove(int row, int col, int playerId) throws RemoteException;

    /*
      Verifica se algum jogador venceu.
      @return 0 se ninguém venceu; 1, 2 ou 3 se o respectivo jogador venceu.
    */
    int checkWinner() throws RemoteException; 

    /*
      Verifica se o jogo terminou (por vitória ou empate).
      @return true se o jogo acabou; false caso contrário.
    */
    boolean isGameOver() throws RemoteException;

    /*
     Registra um novo jogador no jogo.
     @return o número do jogador (1 a 3), ou -1 se o limite de jogadores já foi atingido.
    */
    int registerPlayer() throws RemoteException;

    /*
      Verifica se os três jogadores já se conectaram.
      @return true se todos os jogadores estão conectados; false caso contrário.
    */
    boolean getAllPlayersConnect() throws RemoteException;

    /*
      Indica de quem é a vez no momento.
      @return o número do jogador atual (1 a 3).
    */
    int getCurrentTurn() throws RemoteException;

    /*
      Retorna uma representação do tabuleiro como uma String formatada,
      com emojis e índices, para exibição no cliente.
      @return o tabuleiro atual como texto.
    */
    String getBoardAsString() throws RemoteException;
}
