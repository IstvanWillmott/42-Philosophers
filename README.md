# Philosophers
One or more philosophers sit at a table. <br>
A large bowl of spaghetti sits at the middle of the table. <br>
Each philosopher has only 1 fork, but requires 2 to eat. <br>
<br>
The philosophers alternatively eat, think, or sleep. <br>
While they are eating, they are not thinking nor sleeping; <br>
while thinking, they are not eating nor sleeping; <br>
and, of course, while sleeping, they are not eating nor thinking. <br>
<br>
To eat, each philosopher takes their own fork and their neighbours fork. <br>
When they are finished eating, they put their forks back on the table. <br>
<br>
Every philosopher needs to eat and should never starve. <br>
Philosophers don't speak to each other. <br>
Philosophers don't know if another philosopher is about to die. <br>

# How To Run
Copy and make repository. <br>
`./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>` <br>

Examples: <br>
<br>
`./philo 1 800 200 200` - Philosopher should not eat and should die. <br>
`./philo 5 800 200 200` - No Philosopher should die. <br>
`./philo 5 800 200 200 7` - No Philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times. <br>
`./philo 4 410 200 200` - No Philosopher should die. <br>
`./philo 4 310 200 100` - One Philosopher should die. 