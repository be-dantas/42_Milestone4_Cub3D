# Milestone4 Cub3D

This project is part of the [42](https://42.fr) curriculum and aims to create a **simple 3D graphics engine**, inspired by Wolfenstein 3D, using **raycasting** and the **MiniLibX** library.

The project involves strict parsing, applied mathematics, and real-time graphical rendering, while respecting precise configuration rules and user interaction requirements.

---

## 🎯 Project Objective  

- Render a 3D maze from a `.cub` configuration file.
- Use **raycasting (DDA)** to simulate depth.
- Implement player movement, rotation, and interaction.
- Display different wall textures depending on the wall orientation (N, S, E, W).
- Properly handle keyboard and window events.

---

## 🔧 Main Rules  

- Mandatory use of **MiniLibX**.
- The program must receive a `.cub` file as its argument.
- The `.cub` file must contain:
  - Texture paths (NO, SO, WE, EA).
  - Floor color (F) and ceiling color (C).
  - A valid map, fully enclosed by walls.
- The map must be the last element in the file.
- Required controls:
  - `W A S D` → movement
  - `← →` → camera rotation
  - `ESC` or clicking the window `X` → clean program exit

---

## 🚀 My Solution  

### 📂 Parsing and Validation  

1. **Input validation**
   - I check that the program receives exactly 2 arguments.
   - I verify that the second argument is a valid and existing `.cub` file.

2. **Reading the `.cub` file**
   - I use `get_next_line` to read the file line by line.
   - Each line is analyzed and used to fill the `game` struct.
   - The order of elements does not matter, as long as:
     - they are separated by empty lines;
     - the map is the last element.

3. **Data processing**
   - Colors:
     - Convert `R,G,B` values to `int`.
     - Validate the `[0,255]` range.
     - Convert the result to hexadecimal before storing.
   - Textures:
     - Verify that the file exists.
     - Extract and store the correct path.
   - Any invalid element causes the program to exit with an error.

4. **Final validation**
   - Check that all required elements are present.
   - Validate the map:
     - allowed characters;
     - fully enclosed by walls;
     - a single player starting position.
   - Store the player’s initial `(x, y)` position.

---

### 🖼️ Graphics Initialization  

5. **Texture loading**
   - Fill each texture struct.
   - Verify that the `.xpm` files have valid size and content.
   - On error, all allocated memory is freed and the program exits.

6. **MiniLibX initialization**
   - Only after all validations:
     - initialize the mlx connection;
     - create the window;
     - create the image.

---

## 🎮 Game Loop and Raycasting  

7. **Execution start**
   - The visual part of the project begins when calling `game_keyboard` in `main`.

8. **Events and updates**
   - I use `mlx_hook` and `mlx_loop_hook` to capture keyboard actions.
   - Player actions update the player struct inside the `action` function.

9. **Frame Update (Project Core)**
   - `frame_update` is responsible for the entire rendering cycle.
   - It runs continuously while the game is active.
   - Implements **DDA (Digital Differential Analysis)**.

10. **Rendering**
   - At each frame:
     - the floor and ceiling are drawn;
     - the `put_pixel_player` function is called.

11. **Raycasting**
   - `put_pixel_player`:
     - creates the player’s point of view;
     - casts rays within a **60° FOV**;
     - processes **1000 rays per frame**;
     - detects wall collisions;
     - identifies the wall face (N, S, E, W);
     - applies the correct texture to each ray.

12. **Image update**
   - The image is created, displayed, destroyed, and recreated at each iteration,
     ensuring continuous scene updates.

---

## 🛠️ How to use  

Compile:
```bash
make
````
```bash
./cub3D maps/map.cub
````
