If we run with just 1 thread we get a baseline for comparison against other threads. Then when we run with 2 threads we get to see the interactions per second doubles. Then when we look at 3 threads the amount increases by 3 times. This pattern continues. The amount of work that can be done is equal to n where n is the number of threads used. This however is not nearly as interesting as the time that it takes to do this work. With 8 threads we can do 8 times the amount of work, but the amount of time it takes to do that work is nearly the same as the amount of time it takes to do just 1 thread worth of work. With this said as I increase the number of threads the time to complete the program increases. While the amount of work that can be done increases at a linear ammount the time it takes to complete the program also increases. I do not know by how much this increase is.