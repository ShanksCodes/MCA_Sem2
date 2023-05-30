module.exports = {foo1,foo2}; // const {foo1} = require(...)
exports.foo1= function(){}  //require
export foo1 = ....  //import
export {foo 1 as default, foo2, foo3}


create components in react. It should take employe number, name and salary through input, and a button called "compute gross salary". On clicking this button, 3 new input fields(read only) will pop up which will dioplay ta(20% of salary), hra(30% of salary), and da(90% of salary) and another input field(read only) which displays gross salary, which is a total of salary+ta+hra+da. I
In the next line we have a button called "compute net salary". Clicking it will sprout up two input fields(read only) called pt and tax. on clicking pt, it will display 2% of salary. On clicking tax, it will display 30% of salary. in the next line we have net salary button, which will pop up and show the result of gross salaray-(pt+tax). Do this in react using appropriate class components, states, functional components etc. Assume that I am a beginner in react and doing this for practice, so dont make it too complicated but it should work as stated




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
        tax = (0.05*300000) + (0.1*300000) + 0.2*(salary-1200000); 
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
        <br /><br/>

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
        <br/><br/>
        <button onClick={this.computeNetSalary}>Compute Net Salary</button>
        <br /><br/>

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


