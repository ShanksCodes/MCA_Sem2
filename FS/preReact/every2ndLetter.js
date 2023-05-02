let input = 'a b c d e f'; // Example input string
let output = '';

// Split the input string into an array of characters
const inputArray = input.split(' ');

// Loop through the array and swap every second digit character
for (let i = 0; i < inputArray.length; i += 2) {
  if (inputArray[i + 1]) { // Make sure the next character exists
    output += inputArray[i + 1] + ' ' + inputArray[i] + ' ';
  } else { // If the next character doesn't exist, add the current character to the output
    output += inputArray[i] + ' ';
  }
}

console.log('Input: ', input);
console.log('Output:', output.trim());
