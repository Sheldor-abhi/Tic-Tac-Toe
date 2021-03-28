#include <iostream>
using namespace std;
struct moves
{
    int pos, score;
};

struct TicTacToe
{
    char player, computer, board[9];
    TicTacToe()
    {
        for (int i = 0; i < 9; i++)
        {
            board[i] = ' ';
        }
    }

    bool win()
    {
        if ((board[0] == board[1] && board[1] == board[2] && board[0] != ' ') || (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') || (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') || (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') || (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') || (board[2] == board[5] && board[5] == board[8] && board[2] != ' ') || (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') || (board[2] == board[4] && board[4] == board[6] && board[2] != ' '))
        {
            return true;
        }
        else
            return false;
    }

    bool tie()
    {
        if (win())
            return false;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                return false;
            }
        }
        return true;
    }

    void player_moves()
    {
        while (true)
        {
            cout << "Enter an empty space!" << endl;
            int moves;
            cin >> moves;
            if (board[moves - 1] != ' ')
            {
                cout << "This spot is filled\n";
                continue;
            }
            if (moves > 0 && moves < 10)
            {
                board[moves - 1] = player;
                break;
            }
        }
    }

    void computer_moves()
    {
        moves best_moves = minimax();
        board[best_moves.pos] = computer;
    }

    moves minimax(bool maximizing_player = true)
    {
        moves best_moves;
        if (win())
        {
            if (maximizing_player)
            {
                best_moves.score = -1;
            }
            else
            {
                best_moves.score = 1;
            }
            return best_moves;
        }
        else if (tie())
        {
            best_moves.score = 0;
            return best_moves;
        }

        best_moves.score = maximizing_player ? -2 : 2;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                board[i] = maximizing_player ? computer : player;
                moves board_state = minimax(!maximizing_player);
                if (maximizing_player)
                {
                    if (board_state.score > best_moves.score)
                    {
                        best_moves.score = board_state.score;
                        best_moves.pos = i;
                    }
                }
                else
                {
                    if (board_state.score < best_moves.score)
                    {
                        best_moves.score = board_state.score;
                        best_moves.pos = i;
                    }
                }
                board[i] = ' ';
            }
        }
        return best_moves;
    }

    void play()
    {
        while (true)
        {
            cout << "Which symbol (X or O, X goes first)? ";
            cin >> player;
            if (player == 'X' || player == 'O')
            {
                break;
            }
        }
        computer = player == 'X' ? 'O' : 'X';
        if (player == 'O')
        {
            computer_moves();
        }
        print();
        while (true)
        {
            player_moves();
            print();
            if (win())
            {
                cout << "Player wins!\n";
                return;
            }
            else if (tie())
            {
                cout << "Tie!\n";
                return;
            }
            cout << "Computer is making a moves...\n";
            computer_moves();
            print();
            if (win())
            {
                cout << "Computer wins!\n";
                return;
            }
            else if (tie())
            {
                cout << "Tie!\n";
                return;
            }
        }
    }

    void print()
    {
        // cout << "   |   |" << endl;
        // cout << " " << board[0] << " | " << board[1] << " | " + board[2] << endl;
        // cout << "   |   |" << endl;
        // cout << "-----------" << endl;
        // cout << " " << board[3] << " | " << board[4] << " | " + board[5] << endl;
        // cout << "   |   |" << endl;
        // cout << "-----------" << endl;
        // cout << " " << board[6] << " | " << board[7] << " | " + board[8] << endl;
        // cout << "   |   |" << endl;
        // cout << "\n";
        cout << "\n";
        cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "---------" << endl;
        cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "---------" << endl;
        cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
        cout << "\n";
    }
};
int main()
{
    TicTacToe game;
    game.play();
}
