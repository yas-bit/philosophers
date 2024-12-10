# Philosophers

In this project, students explore the fundamentals of multithreading, synchronization, and resource management using mutexes. The simulation is based on the dining philosophers problem, where philosophers sit at a table, alternating between eating, thinking, and sleeping, while ensuring they avoid starvation. By utilizing threads and mutexes, students learn how to synchronize the philosophers' actions and create a deadlock-free system.

## Table of Contents

- [Description](#Description)
- [Installation](#Installation)
- [Usage](#Usage)
- [Mandatory Requirements](#Mandatory-Requirements)
- [Technologies Used](#Technologies-Used)

## Description

The **Philosophers** project involves simulating the dining philosophers problem using threads and mutexes. The goal is to ensure that philosophers can alternate between eating, thinking, and sleeping without causing deadlocks or starvation. The program must manage multiple philosophers, each with their own forks (protected by mutexes), and the simulation continues until a philosopher dies from starvation.

### Key Features  

- **Threads**: Each philosopher is represented by a separate thread, allowing for parallel execution.  
- **Mutexes**: Forks are shared resources, and mutexes are used to prevent deadlock when philosophers pick up and put down forks.  

### Simulation Rules:

- Each philosopher alternates between **eating**, **thinking**, and **sleeping**.
- A philosopher can only eat when they have both their left and right forks.
- If a philosopher doesn’t start eating within a specified time (`time_to_die`), they die of starvation.
- The simulation ends when all philosophers have eaten the required number of times or when a philosopher dies.

## Installation

To get started, clone the repository:

```
git clone https://github.com/yas-bit/philosophers.git
cd philosophers
```

Then compile the project using the provided Makefile:

```
make
```

This will generate the executable philo.

## Usage

After compiling the project, run the simulation by executing:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Where:

- `number_of_philosophers`: The number of philosophers (and forks) in the simulation.
- `time_to_die`: The time in milliseconds that a philosopher can go without eating before they die.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: The time in milliseconds a philosopher sleeps.
- `number_of_times_each_philosopher_must_eat` (optional): The number of times each philosopher must eat before the simulation ends. If not provided, the simulation ends when any philosopher dies.

### Example Command:

```
./philo 6 700 200 200 4
```

This will run the simulation with 6 philosophers, where each philosopher must eat 4 times. The simulation will stop when any philosopher dies after 700 milliseconds without eating, and each philosopher takes 200 milliseconds to eat and sleep.

## Mandatory Requirements

The program should be written in C and respect to the following rules:

- **Threads**: Each philosopher is represented by a separate thread.
- **Mutexes**: Mutexes should be used to protect the state of the forks and prevent race conditions.

## Philosopher Actions:

- A philosopher picks up the left and right forks before eating.
- A philosopher puts down both forks after eating.
- Philosophers alternate between thinking, eating, and sleeping.

## Input Arguments:

- `number_of_philosophers`: The number of philosophers (and forks) in the simulation.
- `time_to_die`: The time in milliseconds a philosopher can go without eating before they die.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: The time in milliseconds a philosopher sleeps.
- `number_of_times_each_philosopher_must_eat` (optional): The number of times each philosopher must eat before the simulation stops. If not provided, the simulation stops when any philosopher dies.

## State Logging:

Each philosopher’s state change should be logged with timestamps in the following format:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## Technologies Used:
- **C programming language**: For implementing the simulation logic.
- **pthread library**: For managing threads and mutexes to handle synchronization and avoid race conditions.
- **Makefile**: For automating the build process and compiling the project.