function countDigits(num) {
    const digitCounts = Array(10).fill(0); // Initialize an array of 10 zeros to store the frequency of each digit
    while (num > 0) {
      const digit = num % 10; // Extract the rightmost digit
      digitCounts[digit]++; // Increment the frequency of the corresponding digit
      num = Math.floor(num / 10); // Remove the rightmost digit
    }
    return digitCounts;
  }
  
  // Example usage:
  const number = 123456789012345;
  const digitCounts = countDigits(number);
  for (let i = 0; i < digitCounts.length; i++) {
    console.log(`Digit ${i} occurs ${digitCounts[i]} times`);
  }
  