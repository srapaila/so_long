# So Long

**so_long** is a simple 2D game developed as part of the 42 curriculum. It’s a maze-like game where the player navigates through a map to reach a goal while collecting items and avoiding obstacles. This project uses the **MinilibX** library to handle graphics and user input.

---

## 🧩 Game Description

- **Objective**: The goal of the game is to collect all the collectibles and reach the exit.
- **Map**: The map is represented by a grid of characters, where different symbols represent walls, paths, collectibles, and the exit.
- **Player Movement**: The player can move using the arrow keys and must navigate through the map while avoiding walls and collecting items.

---

## 🚀 Features

- **Player Movement**: Move up, down, left, and right within the grid.
- **Collectibles**: Collect all items scattered around the map.
- **Exit**: Reach the exit after collecting all items.
- **Map Validation**: The map is validated to ensure it is solvable before starting the game.
- **Graphics**: The game uses **MinilibX** to render the 2D graphics of the game world, including the player, walls, and items.

---

## 🔧 Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/srapaila/so_long.git
    cd so_long
    ```

2. Install **MinilibX** (if not already installed):

    MinilibX is a graphics library provided by the 42 curriculum. Follow the instructions in the [MinilibX repository](https://github.com/42Paris/minilibx-linux) to install it.

3. Compile the project:

    ```bash
    make
    ```

4. Run the game:

    ```bash
    ./so_long maps/map1.ber
    ```

- **map.ber**: The map file in `.ber` format containing the game layout.

---

## 🧪 Example

Here’s an example of how to run the game with a sample map file:

```bash
./so_long maps/map1.ber
