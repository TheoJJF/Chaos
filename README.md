# Chaos
This repository contains a collection of simulations of chaotic attractors, written in C++ and Simple and Fast Multimedia Library(SFML).

## Getting Started
### Cloning the repository
```
git clone https://github.com/TheoJJF/Chaos.git
```

### Ensuring SFML is installed
For installation and documentations, please visit the [SFML website](https://www.sfml-dev.org/).

## Chaotic Attractors
<center> <h3>Lorenz Attractor</h3> </center>
<p align="center">
    <img src="assets/lorenz.png">
</p>

<center> <h3>System</h3> </center>

$$\dfrac{dx}{dt}=\sigma(-x+y)$$

$$\dfrac{dy}{dt}=-xz+\rho x-y$$

$$\dfrac{dz}{dt}=xy-\beta z$$


<center> <h3>Parameters</h3> </center>

$$\sigma=10,\rho=28,\beta=\dfrac{8}{3}$$

<br>
<center> <h3>Halvorsen Attractor</h3> </center>

<p align="center">
    <img src="assets/halvorsen.png">
</p>

<center> <h3>System</h3> </center>

$$\dfrac{dx}{dt}=-ax-4y-4z-y^2$$

$$\dfrac{dy}{dt}=-ay-4z-4x-z^2$$

$$\dfrac{dz}{dt}=-az-4x-4y-x^2$$


<center> <h3>Parameters</h3> </center>

$$a=1.4$$

