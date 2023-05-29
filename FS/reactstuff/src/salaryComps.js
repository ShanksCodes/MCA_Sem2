import React from 'react';

export class SalaryCalculator extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      employeeNumber: '',
      name: '',
      salary: '',
      ta: '',
      hra: '',
      da: '',
      grossSalary: '',
      pt: '',
      tax: '',
      netSalary: '',
    };
  }

  handleInputChange = (event) => {
    this.setState({ [event.target.name]: event.target.value });
  };

  computeGrossSalary = () => {
    const { salary } = this.state;
    const ta = 0.2 * salary;
    const hra = 0.3 * salary;
    const da = 0.9 * salary;
    const grossSalary = salary + ta + hra + da;

    this.setState({ ta, hra, da, grossSalary });
  };

  computeNetSalary = () => {
    const { salary } = this.state;
    const pt = 0.02 * salary;
    const tax = 0.3 * salary;
    const netSalary = this.state.grossSalary - (pt + tax);

    this.setState({ pt, tax, netSalary });
  };

  render() {
    const {
      employeeNumber,
      name,
      salary,
      ta,
      hra,
      da,
      grossSalary,
      pt,
      tax,
      netSalary,
    } = this.state;

    return (
      <div className='data'>
        <label>
          Employee Number:
          <input
            type="text"
            name="employeeNumber" 
            value={employeeNumber}
            onChange={this.handleInputChange}
          /><br/>
        </label>
        <br />

        <label>
          Name:
          <input
            type="text"
            name="name"
            value={name}
            onChange={this.handleInputChange}
          /><br/>
        </label>
        <br />

        <label>
          Salary:
          <input
            type="number"
            name="salary"
            value={salary}
            onChange={this.handleInputChange}
          /><br/>
        </label>
        <br />

        <button onClick={this.computeGrossSalary}>Compute Gross Salary</button>
        <br /><br/>

        {grossSalary !== '' && (
          <div>
            <label>TA: {ta}</label>
            <br />
            <label>HRA: {hra}</label>
            <br />
            <label>DA: {da}</label>
            <br />
            <label>Gross Salary: {grossSalary}</label>
            <br />
          </div>
        )}

        <button onClick={this.computeNetSalary}>Compute Net Salary</button>
        <br />

        {netSalary !== '' && (
          <div>
            <label>PT: {pt}</label>
            <br />
            <label>Tax: {tax}</label>
            <br />
            <label>Net Salary: {netSalary}</label>
            <br />
          </div>
        )}
      </div>
    );
  }
}


