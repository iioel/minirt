# miniRT

miniRT is a minimal Raytracer for simple geometrical shapes, each with their own lighting system. Their properties and position are described in an .rt file.

## Make and Run

1. Clone the Repository
```
git clone git@github.com:iioel/minirt.git
```
2. Compile the program inside the cloned directory with make
```
cd miniRT && make
```
3. Run the program with a .rt file
```
./miniRT test.rt
```

## Key Bindings

|   **Cam movement** | Key |
| -------------------|-----|
| move right         |  D  |
| move left          |  A  |
| move forward       |  W  |
| move backward      |  S  |
| look right         |  →  |
| look left          |  ←  |
| look up            |  ↑  |
| look down          |  ↓  |

Select an object with **[Mouse Left Click]** to modify him.

|  **object Modify** | Key |
| -------------------|-----|
| move right         |  D  |
| move left          |  A  |
| move forward       |  W  |
| move backward      |  S  |
| move up            |space|
| move down          |shift|
| vector mod         |  V  |

To increase the diameter of a sphere or cylinder: use **[Mouse Right Click]** the delta of x between press and release


