use std::io;
struct Board {
    is_occupied: bool,
    box_value: char,
}
fn main() {
    let mut turn = true;
    let mut board = get_initial_board();

    loop {
        print_board(&board);
        if turn {
            println!("X's turn");
        } else {
            println!("O's turn");
        }
        println!("Enter the box number (1-9) : ");
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");
        let input: usize = match input.trim().parse() {
            Err(_) => {
                println!("Invalid input! Try again");
                continue;
            }
            Ok(num) => num,
        };
        if (input < 1 || input > 9) || is_place_taken(&board, input) {
            println!("Invalid move! Try again");
            continue;
        }
        let row: usize = (input - 1) / 3;
        let col: usize = (input - 1) % 3;
        board[row][col].is_occupied = true;
        board[row][col].box_value = if turn { 'X' } else { '0' };
        turn = !turn;
        let winner = check_win(&board);
        if winner.is_some() {
            println!("{} wins!", winner.unwrap());
            print_board(&board);
            break;
        }
        if check_game_over(&board) {
            println!("Draw!");
            print_board(&board);
            break;
        }
    }
}
fn get_initial_board() -> [[Board; 3]; 3] {
    std::array::from_fn(|i| {
        std::array::from_fn(|j| Board {
            is_occupied: false,
            box_value: (b'1' + (i * 3 + j) as u8) as char,
        })
    })
}
fn print_board(board: &[[Board; 3]; 3]) {
    println!("-------------");
    for i in 0..3 {
        print!("|");
        for j in 0..3 {
            print!(" {} ", board[i][j].box_value);
            if j < 2 {
                print!("|");
            }
        }
        println!("|");
        println!("-------------");
    }
}
fn is_place_taken(board: &[[Board; 3]; 3], index: usize) -> bool {
    let row: usize = (index - 1) / 3;
    let col: usize = (index - 1) % 3;
    board[row][col].is_occupied
}
fn check_win(board: &[[Board; 3]; 3]) -> Option<char> {
    let win_conditions: [[(usize, usize); 3]; 8] = [
        [(0, 0), (0, 1), (0, 2)],
        [(1, 0), (1, 1), (1, 2)],
        [(2, 0), (2, 1), (2, 2)],
        [(0, 0), (1, 0), (2, 0)],
        [(0, 1), (1, 1), (2, 1)],
        [(0, 2), (1, 2), (2, 2)],
        [(0, 0), (1, 1), (2, 2)],
        [(0, 2), (1, 1), (2, 0)],
    ];
    for c in win_conditions {
        let [(r1, c1), (r2, c2), (r3, c3)] = c;
        if board[r1][c1].box_value == board[r2][c2].box_value
            && board[r2][c2].box_value == board[r3][c3].box_value
        {
            return Some(board[r1][c1].box_value);
        }
    }
    None
}
fn check_game_over(board: &[[Board; 3]; 3]) -> bool {
    for i in 0..3 {
        for j in 0..3 {
            if !board[i][j].is_occupied {
                return false;
            }
        }
    }
    true
}
