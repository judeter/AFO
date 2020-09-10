## Short term goals/task
Goals outlined here should be short sets of task or ideas that can be implemented within in a few weeks. The purpose of
recording them is to provide clear tangible goals/task for that period of development.

### Initial interface and dummy optimizer.

	- Outline the MINIMAL set of attributes and methods necessary for an optimizer interface and dummy 
      optimizer. The purpose is not to develop a grand over arching interface for all conceivable 
      optimization routines. Instead the goal is to identify the minimal attributes to define a dummy 
      optimizer and split those attributes into two categories, attributes general to all optimizes and 
      dummy optimizer specific attributes.
	
	- Create an abstract interface from the set of general optimizer attributes. Over time the interface can
      grow to accommodate other methods as they are developed. 
	
	- Create a "dummy" optimizer that generates uniform random numbers as a method of optimization. The 
      purpose of this "optimizer" to create a baseline routine for comparison against other legitimate 
      optimization routines.

	- Create two optimization functions in the test function library.

    - Export the developed test functions and the dummy optimizer as a static library for you in a second 
      add called Evaluation. The purpose of evaluation is to use the Optimizer on the test functions and 
      evaluate the performance of the particular optimizers on the test functions. Profiling the performance
      of the optimization routines on specific test function should be recorded to track the improvement of 
      library overtime.

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
    - Domain
    - point
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
    


