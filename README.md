# Core3D


**Core3D** is a lightweight, extensible **3D graphics library** built from scratch in modern **C++**. It gives developers **full control** over the rendering pipeline without the constraints of traditional game engines. Built for flexibility, performance, and learning.

---

## 📦 Build Instructions

### ✅ Prerequisites

- **CMake** `3.16+`
- **C++17** or newer
- **OpenGL** drivers
- **GLFW** (for OpenGL examples)
- **X11** (Linux only)

---

### 🐧 Build (Linux/macOS/WS)

```bash
git clone https://github.com/DevByEagle/Core3D.git
cd Core3D
mkdir build && cd build
cmake ..
make -j$(nproc)
```

---

### 🪟 Build (Windows)

```bash
git clone https://github.com/DevByEagle/Core3D.git
cd Core3D
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022"
```