function factorial(num) {
    // Recursive function to calculate factorial
    if (num === 0 || num === 1) {
      return 1;
    } else {
      return num * factorial(num - 1);
    }
  }
  
  function calculateFactorialArray(inputArray) {
    // Create an empty array to store the factorials
    const outputArray = [];
  
    // Loop through each element in the input array
    for (let i = 0; i < inputArray.length; i++) {
      const num = inputArray[i];
  
      // Calculate the factorial of the current number
      const result = factorial(num);
  
      // Add the result to the output array
      outputArray.push(result);
    }
  
    // Return the output array
    return outputArray;
  }
  
  // Example usage:
  const inputArray = [1, 2, 3, 4, 5];
  const outputArray = calculateFactorialArray(inputArray);
  console.log(outputArray);
  // Output: [1, 2, 6, 24, 120]
  