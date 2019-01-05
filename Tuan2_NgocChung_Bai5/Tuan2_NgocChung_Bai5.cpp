#include <iostream>
#include <conio.h>

void run();
void printMap();
void initMap();
void move(int dx, int dy);
void update();
void changeDirection(char key);
void clearScreen();
void generateFood();

char getMapValue(int value);

// KICH THUOC MAP
const int mapwidth = 20;
const int mapheight = 20;

const int size = mapwidth * mapheight;

// CAC GIA TRI CHO MAP
int map[size];

// CHI TIET DAU RAN
int headxpos;
int headypos;
int direction;

// LUONG THUC AN CUA CON RAN
int food = 3;

// XAC DINH XEM GAME CO DANG CHAY KHONG
bool running;

int main()
{
    run();
    return 0;
}

// CHUC NANG 
void run()
{
    // KHOI TAO MAP
    initMap();
    running = true;
    while (running) {
        // NEU 1 PHIM DUOC NHAN
        if (kbhit()) {
            // THAY DOI HUONG DUOC XAC DINH BANG CACH NHAN PHIM
            changeDirection(getch());
        }
        // UPDATE MAP
        update();

        // XOA MAN HINH
        clearScreen();

        // IN MAP
        printMap();

        // CHO 0,5s
        _sleep(500);
    }

    // IN KET QUA 
    std::cout << "\t\t!!!THUA!" << std::endl << "\t\tDIEM: " << food;

    std::cin.ignore();
}

// THAY DOI HUONG RAN TU DAU VAO
void changeDirection(char key) {
    /*
      W
    A + D
      S

      1
    4 + 2
      3
    */
    switch (key) {
    case 'w':
        if (direction != 2) direction = 0;
        break;
    case 'd':
        if (direction != 3) direction = 1;
        break;
    case 's':
        if (direction != 4) direction = 2;
        break;
    case 'a':
        if (direction != 5) direction = 3;
        break;
    }
}

// DI CHUYEN DAU RAN DEN VI TRI MOI
void move(int dx, int dy) {
    // XAC DINH VI TRI DAU MOI
    int newx = headxpos + dx;
    int newy = headypos + dy;

    // KIEM TRA NEU CO THUC AN TAI DIA DIEM
    if (map[newx + newy * mapwidth] == -2) {
        // TANG CHIEU DAI CO THE
        food++;

        // TAO THUC AN MOI TREN MAP
        generateFood();
    }

    // KIEM TRA VI TRI
    else if (map[newx + newy * mapwidth] != 0) {
        running = false;
    }

    // DI CHUYEN DEN VI TRI MOI
    headxpos = newx;
    headypos = newy;
    map[headxpos + headypos * mapwidth] = food + 1;

}

// XOA MAN HINH
void clearScreen() {
    // XOA MAN HINH
    system("cls");
}

// TAO THUC AN MOI TREN MAP
void generateFood() {
    int x = 0;
    int y = 0;
    do {
        // TAO CAC GIA TRI X VA Y NGAU NHIEN TRONG MAP
        x = rand() % (mapwidth - 2) + 1;
        y = rand() % (mapheight - 2) + 1;

    
    } while (map[x + y * mapwidth] != 0);

    // DAT THUC AN MOI
    map[x + y * mapwidth] = -2;
}

// Updates MAP
void update() {
    // DI CHUYEN THEO HUONG CHI DINH
    switch (direction) {
    case 0: move(-1, 0);
        break;
    case 1: move(0, 1);
        break;
    case 2: move(1, 0);
        break;
    case 3: move(0, -1);
        break;
    }

    // GIAM GIA TRI RAN TREN BAN DO DI 1
    for (int i = 0; i < size; i++) {
        if (map[i] > 0) map[i]--;
    }
}

// KHOI TAO MAP
void initMap()
{
    // DAT VI TRI BAN DAU O GIUA MAP
    headxpos = mapwidth / 2;
    headypos = mapheight / 2;
    map[headxpos + headypos * mapwidth] = 1;

    // DAT TUONG TREN VA TUONG DUOI
    for (int x = 0; x < mapwidth; ++x) {
        map[x] = -1;
        map[x + (mapheight - 1) * mapwidth] = -1;
    }

    // NOI BEN TRAI VA BEN PHAI
    for (int y = 0; y < mapheight; y++) {
        map[0 + y * mapwidth] = -1;
        map[(mapwidth - 1) + y * mapwidth] = -1;
    }

    // TAO THUC AN DAU TIEN
    generateFood();
}

// IN MAP LEN BAN DIEU KHIEN
void printMap()
{
    for (int x = 0; x < mapwidth; ++x) {
        for (int y = 0; y < mapheight; ++y) {
            // IN GIA TRI TAI VI TRI X, Y HIEN TAI
            std::cout << getMapValue(map[x + y * mapwidth]);
        }
        // KET THUC DONG CHO GIA TRI X TIEP THEO
        std::cout << std::endl;
    }
}

// TRA VE KY TU DO HOA DE HIEN THI TU GIA TRI BAN DO
char getMapValue(int value)
{
    // TRA LAI 1 PHAN CUA CO THE RAN
    if (value > 0) return 'o';

    switch (value) {
        // Return TUONG
    case -1: return 'X';
        // Return THUC AN
    case -2: return 'O';
    }
}
