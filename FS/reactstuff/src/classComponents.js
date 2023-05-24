import React from 'react';

export class Employee extends React.Component {

    constructor(props) {
        super(props);
        console.log(this.props);
      }

    render(){
      return <div>
        <h2>Employee Details...</h2>
        <p>
          <label>Name : <b>{this.props.Name}</b></label>
        </p>
        <Department Name={this.props.DeptName}/>
        </div>;
    }
  }
export class Department extends React.Component {

  render(){
    return <div>
      <h2>Department Details...</h2>
      <p>
        <label>Name : <b>{this.props.Name}</b></label>
      </p>
      </div>;
  }
}


export class Car extends React.Component {
    constructor(props) {
      super(props);
      this.state = {
        brand: "Ford",
        model: "Mustang",
        color: "red",
        year: 1964
      };
    }
    changeColor = () => {
      this.setState({color: "blue"});
    }
    render() {
      return (
        <div>
          <h1>My {this.state.brand}</h1>
          <p>
            It is a {this.state.color}
            {this.state.model}
            from {this.state.year}.
          </p>
          <button
            type="button"
            onClick={this.changeColor}
          >Change color</button>
        </div>
      );
    }
  }
  


