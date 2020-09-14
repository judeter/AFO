## Short term goals/task
Goals outlined here should be short sets of task or ideas that can be implemented within in a few weeks. The purpose of
recording them is to provide clear tangible goals/task for that period of development.

### Initial interface and dummy optimizer.

- ~~Outline the **MINIMAL** set of attributes and methods necessary for an optimizer interface and dummy 
  optimizer. The purpose is not to develop a grand over arching interface for all conceivable 
  optimization routines. Instead the goal is to identify the minimal attributes to define a dummy 
  optimizer and split those attributes into two categories, attributes general to all optimizes and 
  dummy optimizer specific attributes.~~
	
- ~~Create an abstract interface from the set of general optimizer attributes. Over time the interface can
  grow to accommodate other methods as they are developed.~~ 
	
- ~~Create a "dummy" optimizer that generates uniform random numbers as a method of optimization. The 
  purpose of this "optimizer" to create a baseline routine for comparison against other legitimate 
  optimization routines.~~

- Create two optimization functions in the test function library.

- Export the developed test functions and the dummy optimizer as a static library for you in a second 
  add called Evaluation. The purpose of evaluation is to use the Optimizer on the test functions and 
  evaluate the performance of the particular optimizers on the test functions. Profiling the performance
  of the optimization routines on specific test function should be recorded to track the improvement of 
  library overtime.

### Initial Python Package.

- In the end the optimizer tool box being written in c++ will be extended to a python module. The user can then choose 
  to impliment their algorithum using c++ or python.
- Possible Libraies to use to extend the c++ library to python. 
  + Python c/cpp API.
  + Boost python 
  + pybind11
- Checkout this artical (https://skebanga.github.io/embedded-python/) for using pyton implimented algorithums in c++ 
  code. This would make it esier to impliment and test an algorithums performance, then port it to cpp for perfomance
  if needed.
- End goal should be to be able to call an optimizer from python. Below is an example of code that should be able to run
  in python once the module is created.

    ```

    import afo
    import matplotlib.pyplot as plt

    optimizer = afo.optimizers.dummy(<initilization criteria>)     
    optimizer.optimize()
    
    print(optimizer)  # Prints a report of the optimizer to the screen.
    plt.plot(optimizer.optimum_points)  # Plot the the Optimum Value vs. Iteration.

    ```
    

#### Minimal Attribute and method set.
For an initial pass at an optimizer we consider a 2d optimizer. The optimize method is the virtual method that each 
subclass implementation. For now we consider that the optimize function will correctly set all of the class attributes.
This can, and most likely will change as the project grows.
 
  - Attributes 
    - Common Attributes
      - domain
      - responseFunction
      - evaluatedPoints
      - numMaxEvaluations
      - convergenceTollerance
      - currentOptimum
      - converged
    - Common Methods
    - 
    - Virtual Methods
      - optimize

  - Dummy Specific Attributes    
      - randomSeed
      - 

### Structures ???
- domain
   + xMin
   + xMax
   + yMin
   + yMax
        
- point
  + x
  + y
  + z
  + n: Integer number for when the point was evaluated?
### Attributes

       
  - Initialization Attributes
    - responceFunction: Function which the optimization method is attempting to optimize.  
    - domain: Allowed region overwhich to optimize the target function.
    - tol: A value indicating that the optimization routine has converged.
    - maxIterations: A maximum number of allowed iterations.  

  - Status Attributes
    - converged

  - initialGuess: An initial point from which to begin the optimization.
  - evaluatedPoints:
  - responceFunction:
  - currentOptimum:
    
### Methods
  - setDomain:
  - evaluateResponce:
  - proposer:
  
### Evaluation Metrics

#### Convergence Rate: 
How many iterations does it take a method to converge?

Convergence of an algorithum depends on various input. Initial point, step parameters, random seeds, etc. Compairing
two algorithums with at a single set of values 

Note for "sudo-random" algorithums one is tempted to say that it is nessisary to run multiple time to determine the 
average. This goes agains the design philllosphy that all algorithums are deterministic. Any randomness used in an
algorithum should be set with a random seed value. Like and inital starting point the average performance of an 
algorithum can be evaluated by considering various random seeds.

  


