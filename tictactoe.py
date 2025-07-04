def print_board(board):
    """Prints the current state of the Tic Tac Toe board."""
    print(" " + " | ".join(board[0]))
    print("---|---|---")
    print(" " + " | ".join(board[1]))
    print("---|---|---")
    print(" " + " | ".join(board[2]))

def check_winner(board):
    """Checks for a winner on the board."""
    # Check rows and columns
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != ' ':
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] != ' ':
            return board[0][i]
    # Check diagonals
    if board[0][0] == board[1][1] == board[2][2] != ' ':
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] != ' ':
        return board[0][2]
    return None

def is_full(board):
    """Checks if the board is full."""
    return all(cell != ' ' for row in board for cell in row)

def tic_tac_toe():
    """Runs the Tic Tac Toe game."""
    # Initialize the board
    board = [[' ' for _ in range(3)] for _ in range(3)]
    current_player = 'X'

    # Game loop
    while True:
        print_board(board)
        try:
            # Get the player's move
            row = int(input(f"Player {current_player}, enter your move (row 1-3): ")) - 1
            col = int(input(f"Player {current_player}, enter your move (column 1-3): ")) - 1
            if board[row][col] != ' ':
                print("That cell is already occupied. Try again.")
                continue
            # Place the move on the board
            board[row][col] = current_player
        except (ValueError, IndexError):
            print("Invalid input. Please enter numbers between 1 and 3.")
            continue
        
        # Check for a winner
        winner = check_winner(board)
        if winner:
            print_board(board)
            print(f"Player {winner} wins!")
            break
        # Check for a tie
        if is_full(board):
            print_board(board)
            print("It's a tie!")
            break
        # Switch players
        current_player = 'O' if current_player == 'X' else 'X'

# Run the game
tic_tac_toe()


