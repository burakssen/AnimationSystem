# Animation System

## Introduction

This is an example project that I have created for animation transitioning with raylib and entt. It basically shows how to create a simple animation system that can be used to animate sprites in a game. Animations can be created by defining a set of frames and then playing them in a loop or once. The system is designed to be simple and easy to use.

## Features

- Animation system that can be used to animate sprites in a game.
- Animation can be played in a loop or once.
- Animation can be played at a specific speed.
- Animation transition can be done by defined on the fly.

## Dependencies

- raylib
- entt

`Animations should be in sprite based and should be in nx1 format. For example, if you have a sprite sheet that has 4 frames, it should be 4x1, and each animation should be in its own separate sprite sheet.`

## Installation

1. Clone the repository with recursive flag to get the submodules. `git clone --recursive https://github.com/burakssen/AnimationSystem.git`
2. Build the project with cmake. `cmake -B build -S .`
3. Compile the project. `cmake --build build -j`
4. Run the project. `./build/AnimationSystem`

## Usage

- Use `W`, `A`, `S`, `D` to move the player.
- Use `ESC` to close.
