import React, { useState } from 'react';
import './CarLoan.css';

const CarLoan = () => {
  const [loanAmount, setLoanAmount] = useState(0);
  const [loanTerm, setLoanTerm] = useState(0);

  const calculateEMI = () => {
    const interestRate = 10; // 10% per annum
    const monthlyInterestRate = interestRate / 100 / 12;
    const principal = loanAmount;
    const numberOfPayments = loanTerm;

    const emi =
      (principal * monthlyInterestRate * Math.pow(1 + monthlyInterestRate, numberOfPayments)) /
      (Math.pow(1 + monthlyInterestRate, numberOfPayments) - 1);

    return Number(emi.toFixed(2));
  };

  return (
    <div className="container">
      <div className="form-container">
        <h2>Car Loan</h2>
        <label>Loan Amount:</label>
        <input
          type="number"
          value={loanAmount}
          onChange={(e) => setLoanAmount(Number(e.target.value))}
        /><br /><br />

        <label>Loan Term (in months):</label>
        <input
          type="number"
          value={loanTerm}
          onChange={(e) => setLoanTerm(Number(e.target.value))}
        /><br /><br />

        <label>Interest:</label>
        <input type="text" value="10%" readOnly /><br /><br />

        <label>EMI:</label>
        <input type="text" value={calculateEMI()} readOnly /><br /><br />
      </div>
    </div>
  );
};

export default CarLoan;


/*import React from 'react';
import './CarLoan.css';


const CarLoan = () => {
  const loanAmount = 0;
  const loanTerm = 0;

  const calculateEMI = () => {
    const interestRate = 10; // 10% per annum
    const monthlyInterestRate = interestRate / 100 / 12;
    const principal = loanAmount;
    const numberOfPayments = loanTerm;

    const emi =
      (principal * monthlyInterestRate * Math.pow(1 + monthlyInterestRate, numberOfPayments)) /
      (Math.pow(1 + monthlyInterestRate, numberOfPayments) - 1);

    return Number(emi.toFixed(2));
  };

  return (
    <div className="container">
      <div className="form-container">
        <h2>Car Loan</h2>
        <label>Loan Amount:</label>
        <input type="number" value={loanAmount} onChange={() => {}} /><br /><br />

        <label>Loan Term (in months):</label>
        <input type="number" value={loanTerm} onChange={() => {}} /><br /><br />

        <label>Interest:</label>
        <input type="text" value="10%" readOnly /><br /><br />

        <label>EMI:</label>
        <input type="text" value={calculateEMI()} readOnly /><br /><br />
      </div>
    </div>
  );
};

export default CarLoan;*/
