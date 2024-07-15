// Generate a Sudoku puzzle
let arr = Array.from({ length: 9 }, () => Array(9).fill(null));

for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
        arr[i][j] = document.getElementById(i * 9 + j);
    }
}
function generateSudoku() {
    let block = Array.from({ length: 9 }, () => Array(9).fill(0));
    fillBoard(block);
    removeNumbers(block, 60); 
    initializeGrid(block);
}

function fillBoard(block) {
    solver(block, 0, 0);
}

function solver(block, i, j) {
    if (i == 9) {
        return true;
    }
    if (j == 9) {
        return solver(block, i + 1, 0);
    }
    if (block[i][j] != 0) {
        return solver(block, i, j + 1);
    }
    let numbers = shuffleArray([1, 2, 3, 4, 5, 6, 7, 8, 9]);
    for (let n of numbers) {
        if (isValid(block, i, j, n)) {
            block[i][j] = n;
            if (solver(block, i, j + 1)) {
                return true;
            }
            block[i][j] = 0;
        }
    }
    return false;
}

function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        let j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
}

function removeNumbers(block, count) {
    while (count > 0) {
        let i = Math.floor(Math.random() * 9);
        let j = Math.floor(Math.random() * 9);
        if (block[i][j] != 0) {
            block[i][j] = 0;
            count--;
        }
    }
}

function isValid(block, i, j, n) {
    for (let x = 0; x < 9; x++) {
        if (block[i][x] == n || block[x][j] == n) {
            return false;
        }
    }
    let p = i - i % 3;
    let q = j - j % 3;
    for (let x = p; x < p + 3; x++) {
        for (let y = q; y < q + 3; y++) {
            if (block[x][y] == n) {
                return false;
            }
        }
    }
    return true;
}

function initializeGrid(block) {
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            arr[i][j].innerHTML = block[i][j] ? block[i][j] : '';
        }
    }
}


// ----------------------------------------------------------

function startSolver() {
    let block1 = Array.from({ length: 9 }, () => Array(9).fill(0));
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            let value = arr[i][j].innerHTML;
            block1[i][j] = value ? parseInt(value) : 0;
        }
    }
    if (solver(block1, 0, 0)) {
        printit1(block1);
    } else {
        alert("No solution found!");
    }
}

function solver1(block1, i, j) {
    // base case 
    if (i == 9) {
        printit1(block1);
        return true;
    }
    if (j == 9) {
        return solver1(block1, i + 1, 0);
    }
    if (block1[i][j] != 0) {
        return solver1(block1, i, j + 1);
    }
    for (let n = 1; n <= 9; n++) {
        if (isValid1(block1, i, j, n)) {
            block1[i][j] = n;
            if (solver1(block1, i, j + 1)) {
                return true;
            }
            block1[i][j] = 0;
        }
    }
    return false;
}
let discoElements = document.querySelectorAll(".mini1");

function printit1(block) {
    let delay = 50; 
    let updates = [];

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            updates.push({ i, j, value: block[i][j] });
        }
    }

    function updateCell(update) {
        return new Promise((resolve) => {
            setTimeout(() => {
               
               
                
                arr[update.i][update.j].innerHTML = update.value ? update.value : '';
               
                resolve();
            }, delay);
        });
    }

    async function applyUpdates() {
        for (let update of updates) {
            await updateCell(update);
        }
    }

    applyUpdates();
}


function isValid1(block1, i, j, n) {
    for (let x = 0; x < 9; x++) {
        if (block1[i][x] == n || block1[x][j] == n) {
            return false;
        }
    }

    let p = i - i % 3;
    let q = j - j % 3;
    for (let x = p; x < p + 3; x++) {
        for (let y = q; y < q + 3; y++) {
            if (block1[x][y] == n) {
                return false;
            }
        }
    }
    return true;
}

// console.log(arr);