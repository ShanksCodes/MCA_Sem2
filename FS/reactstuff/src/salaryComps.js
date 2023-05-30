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

    if (!salary) 
     {
      alert('Please enter the salary before computing the gross salary.');
      return;
     }
    const ta = 0.2 * salary;
    const hra = 0.3 * salary;
    const da = 0.9 * salary;
    const grossSalary = parseFloat(salary) + parseFloat(ta) + parseFloat(hra) + parseFloat(da);

    this.setState({ ta, hra, da, grossSalary });
  };
 
  computeNetSalary = () => {

    
    const { salary } = this.state;
    const pt = 0.02 * salary;

    if (!salary) 
     {
      alert('Please enter the salary before computing the net salary.');
      return;
     }


    let tax = 0;

    if(salary<=300000)
     tax = 0;

    else
     {
       if(salary<=600000)
        tax = 0.05 * (salary-300000);
       else if(salary<=900000)
        tax = (0.05*300000) + 0.1*(salary-600000);
       else if(salary<=1200000)
        tax = (0.05*300000) + (0.1*300000) + 0.15*(salary-900000); 
       else
        tax = (0.5*300000) + (0.1*300000) + (0.15*300000) + 0.2*(salary- 1200000);
     }
      
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
        <h2 className= 'heading'>Salary calculator </h2><br/>
        <label className='label'>
          Employee Number:
          <input
            type="text"
            name="employeeNumber"
            className='input'
            value={employeeNumber}
            onChange={this.handleInputChange}
          /><br/>
        </label>
        <br />

        <label className='label'>
          Name:
          <input
            type="text"
            name="name"
            className='input'
            value={name}
            onChange={this.handleInputChange}
          /><br/>
        </label>
        <br />

        <label className='label'>
          Salary:
          <input
            type="number"
            name="salary"
            className='input'
            value={salary}
            onChange={this.handleInputChange}
          /><br/>
        </label>
        <br /><br/>

        <button className='button' onClick={this.computeGrossSalary}>Compute Gross Salary</button>
        <br /><br/>

        {grossSalary !== '' && (
          <div>
            <label className='result-label'>TA: <span className='result-value'>{ta}</span></label>
            <br />
            <label className='result-label'>HRA: <span className='result-value'>{hra}</span></label>
            <br />
            <label className='result-label'>DA: <span className='result-value'>{da}</span></label>
            <br />
            <label className='result-label'>Gross Salary: <span className='result-value'>{grossSalary}</span></label>
            <br />
          </div>
        )}
        <br/><br/>
        <button className='button' onClick={this.computeNetSalary}>Compute Net Salary</button>
        <br /><br/>

        {netSalary !== '' && (
          <div>
            <label className='result-label'>PT: <span className='result-value'>{pt}</span></label>
            <br />
            <label className='result-label'>Tax: <span className='result-value'>{tax}</span></label>
            <br />
            <label className='result-label'>Net Salary: <span className='result-value'>{netSalary}</span></label>
            <br />
          </div>
        )}
      </div>
    );
  }
}


