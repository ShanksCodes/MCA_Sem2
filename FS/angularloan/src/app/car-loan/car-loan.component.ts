import { Component } from '@angular/core';

@Component({
  selector: 'app-car-loan',
  templateUrl: './car-loan.component.html',
  styleUrls: ['./car-loan.component.css']
})
export class CarLoanComponent {
  loanAmount: number = 0;
  loanTerm: number = 0;

  calculateEMI(): number {
    const interestRate = 10; // 10% per annum
    const monthlyInterestRate = interestRate / 100 / 12;
    const principal = this.loanAmount;
    const numberOfPayments = this.loanTerm;

    const emi = (principal * monthlyInterestRate * Math.pow(1 + monthlyInterestRate, numberOfPayments)) /
      (Math.pow(1 + monthlyInterestRate, numberOfPayments) - 1);

    return Number(emi.toFixed(2));
  }

}
