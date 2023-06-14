import { Component } from '@angular/core';

@Component({
  selector: 'app-salary-calculator',
  templateUrl: './salary-calculator.component.html',
  styleUrls: ['./salary-calculator.component.css']
})
export class SalaryCalculatorComponent {
  employeeNumber: string = '';
  name: string = '';
  salary: number | null = null;
  ta: number | null = null;
  hra: number | null = null;
  da: number | null = null;
  grossSalary: number | null = null;
  pt: number | null = null;
  tax: number | null = null;
  netSalary: number | null = null;

  handleInputChange(event: any) {
    const { name, value } = event.target;
    switch (name) {
      case 'employeeNumber':
        this.employeeNumber = value;
        break;
      case 'name':
        this.name = value;
        break;
      case 'salary':
        this.salary = +value;
        break;
      default:
        break;
    }
  }

  computeGrossSalary() {
    if (!this.salary) {
      alert('Please enter the salary before computing the gross salary.');
      return;
    }
    const ta = 0.2 * this.salary;
    const hra = 0.3 * this.salary;
    const da = 0.9 * this.salary;
    const grossSalary = this.salary + ta + hra + da;

    this.ta = ta;
    this.hra = hra;
    this.da = da;
    this.grossSalary = grossSalary;
  }

  computeNetSalary() {
    if (!this.salary) {
      alert('Please enter the salary before computing the net salary.');
      return;
    }
  
    if (!this.grossSalary) {
      alert('Please compute the gross salary before computing the net salary.');
      return;
    }
  
    const pt = 0.02 * this.salary;
    let tax = 0;
  
    if (this.salary <= 300000) {
      tax = 0;
    } else if (this.salary <= 600000) {
      tax = 0.05 * (this.salary - 300000);
    } else if (this.salary <= 900000) {
      tax = 0.05 * 300000 + 0.1 * (this.salary - 600000);
    } else if (this.salary <= 1200000) {
      tax = 0.05 * 300000 + 0.1 * 300000 + 0.15 * (this.salary - 900000);
    } else {
      tax = 0.5 * 300000 + 0.1 * 300000 + 0.15 * 300000 + 0.2 * (this.salary - 1200000);
    }
  
    const netSalary = this.grossSalary - (pt + tax);
  
    this.pt = pt;
    this.tax = tax;
    this.netSalary = netSalary;
  }
  
}
