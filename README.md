# Philosophers

`philosophers` is a 42 curriculum project that simulates the Dining Philosophers problem in C with POSIX threads and mutexes. The goal is to manage concurrency safely while keeping the simulation accurate enough to detect starvation, death, and completion conditions.

## Overview

Each philosopher runs in its own thread. Forks are shared mutex-protected resources, and a dedicated monitor thread watches the table to decide when the simulation must stop.

The implementation focuses on:

- thread-safe shared state
- deadlock avoidance through fork ordering
- accurate timing in milliseconds
- safe shutdown and resource cleanup
- minimal lock contention around logging and stop conditions

## Project structure

```text
philo/
├── main.c
├── philo.h
├── init_functions/
├── philo_actions/
├── routines/
└── utils/
```

The code is organized by responsibility:

- `init_functions/` initializes the table, forks, philosophers, and thread start-up
- `philo_actions/` contains the eat, sleep, think, and fork-handling actions
- `routines/` contains the philosopher routine and the monitor routine
- `utils/` contains timing, parsing, printing, validation, and cleanup helpers

## How it works

The program receives the simulation parameters, validates them, builds the shared table, starts the philosopher threads, and launches a monitor thread.

The monitor checks whether:

- any philosopher has exceeded `time_to_die`
- every philosopher has reached the optional meal target

When one of those conditions is met, the simulation stops and all allocated resources are released.

## Synchronization model

This implementation uses mutexes to keep the simulation safe:

- one mutex per fork
- a write mutex for status output
- a stop mutex for the shared stop flag
- a per-philosopher mutex for meal-time access

An asymmetric fork-taking strategy is used so philosophers do not all try to lock forks in the same order. That reduces the chance of circular waiting and deadlock.

## Build

```bash
make
```

Common targets:

```bash
make clean
make fclean
make re
```

## Run

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

Arguments:

| Argument | Meaning |
|---|---|
| `number_of_philosophers` | Number of philosophers and forks |
| `time_to_die` | Maximum time in milliseconds before a philosopher dies without eating |
| `time_to_eat` | Time spent eating |
| `time_to_sleep` | Time spent sleeping |
| `number_of_times_each_philosopher_must_eat` | Optional stop condition when all philosophers reach the target |

## Notes

- The program prints each state transition safely through a shared output lock.
- Timing is measured in milliseconds.
- Cleanup frees mutexes, forks, philosophers, and shared allocations before exit.
- Invalid arguments are rejected before the simulation starts.
