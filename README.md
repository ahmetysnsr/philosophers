*This project has been created as part of the 42 curriculum by asari.*

## Description
**Philosophers** is a solution to the classic "Dining Philosophers" problem. This project involves learning the basics of threading a process, managing shared resources (forks), and using **mutexes** to prevent data races.

The simulation consists of a cycle where philosophers take turns eating, sleeping, and thinking to stay alive. If a philosopher cannot eat within a certain time frame, they die of starvation, and the simulation ends.

## Technical Features
- **Multi-threading:** Each philosopher runs on a separate thread created using `pthread_create`.
- **Mutex Management:** Forks and shared data, such as the death flag and meal times, are protected by mutexes to ensure thread safety.
- **Deadlock Prevention:** An asymmetric fork-taking strategy (even/odd rule) is implemented to prevent circular wait conditions and potential deadlocks.
- **Performance Optimization:** A dedicated `stop_lock` is used for the `stop_flag` to decouple status checks from slow I/O operations like printing, preventing timing issues and unnecessary simulation delays.

## Instructions

### Compilation
To compile the project, navigate to the root directory and run:

make

This will generate the `philo` executable using the flags `-Wall -Wextra -Werror -pthread`.

### Execution
Run the program with the following arguments:

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

**Example:**
./philo 5 800 200 200

* **number_of_philosophers**: The total number of philosophers and forks.
* **time_to_die**: Time in milliseconds before a philosopher dies of hunger.
* **time_to_eat**: Time it takes for a philosopher to eat.
* **time_to_sleep**: Time a philosopher spends sleeping.
* **[must_eat]**: (Optional) The simulation stops if all philosophers eat this many times.

## Resources
* **The Linux Programming Interface**: Reference for system calls and thread management.
* **POSIX Threads Documentation**: Official documentation for `pthread` library functions.
