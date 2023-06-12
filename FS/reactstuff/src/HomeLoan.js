import React, { useState } from 'react';
import './HomeLoan.css';

const HomeLoan = () => {
  const [loanAmount, setLoanAmount] = useState(0);
  const [loanTerm, setLoanTerm] = useState(0);

  const calculateEMI = () => {
    const interestRate = 15; // 15% per annum
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
        <h2>Home Loan</h2>
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
        <input type="text" value="15%" readOnly /><br /><br />

        <label>EMI:</label>
        <input type="text" value={calculateEMI()} readOnly /><br /><br />
      </div>
    </div>
  );
};

export default HomeLoan;
