_This project has been created as part of the 42 curriculum by rfoo._

# Philosophers

## Description
`Philosophers` tasks us to create a simulation where a group of philosophers take turns to eat, sleep and think. The philosophers will sit around a table and each philosopher requires 2 forks to eat. Each simulation is subjected to the following conditions:

| Argument Name | Description |
|---------------|-------------|
| `number_of_philosophers` | Number of philosophers (and forks) in the simulation. |
| `time_to_die` | Maximum time (ms) a philosopher can go without eating before dying. |
| `time_to_eat` | Time (ms) a philosopher spends eating while holding both forks. |
| `time_to_sleep` | Time (ms) a philosopher spends sleeping after eating. |
| `number_of_times_each_philosopher_must_eat` *(optional)* | Ends the simulation once every philosopher has eaten at least this many times. |

### Philosopher Arrangement

- Philosopher **1** sits between philosopher **number_of_philosophers** and philosopher **2**.
- Every philosopher **N** sits between philosopher **N - 1** and philosopher **N + 1**, forming a circular table.

### Program Output

Each philosopher's state change is printed in the following format:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Where:

- `timestamp_in_ms` is the elapsed time (in milliseconds) since the simulation started.
- `X` is the philosopher's ID.

### Requirements

- Log messages must not overlap or interleave. Each message should be printed atomically.
- A philosopher's death must be reported within **10 ms** of the actual time of death.
- The simulation should prevent philosopher starvation whenever possible.

## Approach
We will model each philosopher as an individual thread and each fork as a shared mutex. There will be a dedicated thread to continuousely monitor the status of each philosopher to check if anyone of them has died or if all of them have reached the meal count. 

To ensure thread safety and prevent race conditions:

- Forks are protected using individual mutexes.
- Shared variables such as `simulation_start`, `simulation_end`, `last_meal_ts`, and `meal_count` are synchronized using mutexes.
- Console output is protected by a `print_mutex` to prevent overlapping messages.
- Helper functions (`safe_read` and `safe_update`) are used to provide consistent access to shared variables.

Deadlocks are avoided by alternating the order in which philosophers acquire forks:

- Odd-numbered philosophers pick up their **left** fork first.
- Even-numbered philosophers pick up their **right** fork first.


## Instructions
To compile the program, run:

```
make
```

This compiles the program as an executable `philo`.

To use:

```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```

### Examples

```
./philo 5 800 200 200

OR

./philo 5 800 200 200 7
```

To test for data race conditions:
```
valgrind --tool=helgrind ./philo 5 800 200 200 7
```

## Resources

- [Short introduction to threads (pthreads)](https://www.youtube.com/watch?v=d9s_d28yJq0)
- [What is a mutex in C? (pthread_mutex)](https://www.youtube.com/watch?v=oq29KUy29iQ)
- [valgrind(1)](https://man7.org/linux/man-pages/man1/valgrind.1.html)