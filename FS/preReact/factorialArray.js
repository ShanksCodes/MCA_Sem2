function factorial(num) {
    // Recursive Function to calculate factorial
    if (num === 0 || num === 1) {
      return 1;
    } else {
      return num * factorial(num - 1);
    }

  }
  
  function calculateFactorialArray(inputArray) {
    // Create Empty Array to store the Array
    const outputArray = [];
  
    // Loop through each element in the input array
    for (let i = 0; i < inputArray.length; i++) {
      const num = inputArray[i];
  
      // Calculate the factorial of the current number
      const result = factorial(num);
  
      // Add the result to the output array
      outputArray.push(result);
    }
  

    //Return the Out put array
    return outputArray;
  }
  
  const inputArray = [5, 6, 5, 4, 5];
  const outputArray = calculateFactorialArray(inputArray);
  console.log(outputArray);
  
  