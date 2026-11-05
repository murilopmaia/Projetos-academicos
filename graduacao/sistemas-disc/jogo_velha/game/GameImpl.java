// Lógica do jogo

package game;

import java.rmi.RemoteException;
import java.util.HashSet;
import java.util.Set;

// Classe que implementa os métodos remotos definidos na interface Game
public class GameImpl implements Game{

    // Representação do tabuleiro 5x5
    private char[][] board = new char[5][5];
    // Contador de jogadas feitas (máximo 25)
    private int moves = 0; 
    // Conjunto de jogadores registrados (IDs 1 a 3)
    private Set<Integer> registeredPlayers = new HashSet<>(); 
    // Controla de quem é a vez
    private int currentTurn = 1;

    // Inicializa o tabuleiro com '.'
    public GameImpl() throws RemoteException {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                board[i][j] = '.';
    }

    // Método para fazer uma jogada
    @Override
    public synchronized boolean makeMove(int row, int col, int playerId) throws RemoteException {
        // Só permite se for a vez do jogador, a célula estiver vazia e row e col estiveram no limite 
        if (playerId != currentTurn ||  row < 0 || row >= 5 || col < 0 || col >= 5) return false;
        if (board[row][col] != '.') return false;

        // Marca a jogada com o número do jogador
        board[row][col] = (char) ('0' + playerId);
        moves++;

        // Passa a vez para o próximo jogador (1 → 2 → 3 → 1 ...)
        currentTurn = (currentTurn % 3) + 1;
        return true;
    }

     // Verifica se o jogo acabou (vitória ou empate)
    @Override
    public synchronized boolean isGameOver() {
        return checkWinner() != 0 || moves == 25;
    }

    // Verifica se algum jogador venceu
    @Override
    public synchronized int checkWinner() {
        for (int p = 1; p <= 3; p++) {
            char symbol = (char) ('0' + p);
            if (hasLine(symbol)) return p;
        }
        return 0;
    }

    // Verifica 3 símbolos consecutivos
    private boolean hasLine(char symbol) {
        // Horizontal e vertical
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                // Horizontal
                if (board[i][j] == symbol && board[i][j+1] == symbol && board[i][j+2] == symbol)
                    return true;
                // Vertical
                if (board[j][i] == symbol && board[j+1][i] == symbol && board[j+2][i] == symbol)
                    return true;
            }
        }

        // Diagonais
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Diagonal principal
                if (board[i][j] == symbol && board[i+1][j+1] == symbol && board[i+2][j+2] == symbol)
                    return true;
                // Diagonal secundária
                if (board[i][j+2] == symbol && board[i+1][j+1] == symbol && board[i+2][j] == symbol)
                    return true;
            }
        }

        return false;
    }
    
    // Registra um novo jogador, se ainda não houver 3
    @Override
    public synchronized int registerPlayer() throws RemoteException {
        for (int i = 1; i <= 3; i++) {
            if (!registeredPlayers.contains(i)) {
                registeredPlayers.add(i);
                return i;
            }
        }
        return -1; // Já temos 3 jogadores
    }

    // Verifica se os 3 jogadores já se conectaram
    @Override
    public synchronized boolean getAllPlayersConnect(){
        return registeredPlayers.size() == 3;
        
    }

    // Retorna qual jogador deve jogar no momento
    @Override
    public synchronized int getCurrentTurn() {
        return currentTurn;
    }

    // Retorna o tabuleiro como string formatada com emojis e índices
    @Override
    public synchronized String getBoardAsString() {
        StringBuilder sb = new StringBuilder();
        String[] simb = {"0️⃣", "1️⃣", "2️⃣", "3️⃣", "4️⃣"};
        int col = 0;

        sb.append("  ");
        for (String s : simb) {
            sb.append(s).append(" ");
        }
        sb.append("\n");

        for (char[] row : board) {
            sb.append(simb[col++]).append("  ");
            for (char c : row) {
                sb.append(c).append(" ");
            }
            sb.append("\n");
        }

        return sb.toString();
    }
    
}
