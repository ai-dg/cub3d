# 🕹️ cub3D - A 3D Raycasting Engine

<img src="https://github.com/user-attachments/assets/dac76719-cb38-4719-bdb4-6ce6ebfb3d75" width="500">

![Score](https://img.shields.io/badge/Score-125%25-brightgreen)  
📌 **42 School - Graphics & Raycasting Project**  

## 📝 Description
**cub3D** is a **first-person 3D raycasting engine** inspired by **Wolfenstein 3D**, built using **MiniLibX**.  
It renders a **real-time 3D maze** using raycasting techniques and includes extended **bonus features**.  
This project was developed as a **team project** with [Christophe Albor Pirame](https://github.com/CronopioSalvaje).  

## 🔥 Key Features
✅ **Real-time 3D rendering with raycasting**  
✅ **Textured walls with directional shading** (North, South, East, West)  
✅ **Dynamic lighting effects for improved realism**  
✅ **Smooth player movement and rotation (WASD & arrow keys)**  
✅ **Collision detection to prevent walking through walls**  

## 🏆 Result: **125% Score**
The project was successfully validated with a **125% score**, including all bonus features. 🎉

## 📁 Files
- `cub3d.h` → Contains function prototypes and required macros  
- `cub3d.c` → Main game loop and rendering logic  
- `Makefile` → Automates compilation (`all`, `clean`, `fclean`, `re`, `bonus`)  

## 🎮 **Gameplay & Mechanics**
1. The player starts in a **3D maze** with walls and open spaces.
2. The goal is to **explore the maze** and navigate using **raycasting-based rendering**.
3. The player can **rotate left/right** (arrow keys) and **move forward/backward** (WASD).
4. Walls are **textured and shaded** depending on their facing direction.
5. The **floor and ceiling** have configurable colors.

### 🔹 **Map Format (`.cub` files)**
A valid `.cub` map must:
- Be **rectangular**.
- Be **surrounded by walls (`1`)**.
- Contain at least one **player spawn point** (`N`, `S`, `E`, or `W`).
- Define **textures and colors** for walls, floor, and ceiling.

**Example map:**
```txt
NO ./Includes/assets/1024/wall3.xpm
SO ./Includes/assets/1024/wall4.xpm
WE ./Includes/assets/1024/wall5.xpm
EA ./Includes/assets/1024/wall6.xpm
CD ./Includes/assets/1024/Door-3-close.xpm
OD ./Includes/assets/1024/Door-3-open.xpm

SPRITE M 10 ./Includes/assets/coins/
SPRITE WALL 1 ./Includes/assets/map/wall
SPRITE DOOR 1 ./Includes/assets/map/door
SPRITE VOID 1 ./Includes/assets/map/void
SPRITE PLAYER 2 ./Includes/assets/map/player

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N01111
10110111 1110101 101111010001
10101001 1111111 111111111111
```


## 🚀 **Extended Features (Bonus)**
| Feature | Description |
|---------|-------------|
| ✅ **Wall Collisions** | Prevents passing through walls |
| ✅ **Minimap System** | Displays the map with player position |
| ✅ **Dynamic Doors** | Open and close interactive doors |
| ✅ **Animated Sprites** | Adds animated objects in the world |
| ✅ **Mouse View Rotation** | Allows smooth player rotation with the mouse |

## ⚙️ **Compilation & Usage**
### 🛠 **Compile the Program**
```sh
make
``` 

### ▶️ **Run cub3D**
```sh
./cub3D maps/map2.cub
```

### ▶️ **Move & Rotate**
- **W/A/S/D** → Move forward, left, backward, right  
- **Left/Right Arrow** → Rotate view  

## 📜 License

This project was completed as part of the **42 School** curriculum.  
It is intended for **academic purposes only** and follows the evaluation requirements set by 42.  

Unauthorized public sharing or direct copying for **grading purposes** is discouraged.  
If you wish to use or study this code, please ensure it complies with **your school's policies**.  



