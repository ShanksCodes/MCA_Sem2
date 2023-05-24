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
          <h1>My {this.state.brand}</h1><h1>{this.props.brand}</h1>
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



class App extends React.Component {
  render() {
    return <h1>{this.props.data}</h1>;
  }
}

export class Propsexample extends React.Component {
  constructor(props) {
    super(props);
    this.state = { change: true };
  }

  render() {
    return (
      <div>
        <button
          onClick={() => {
            this.setState({ change: !this.state.change });
          }}
        >
          Click Here!
        </button>
        {this.state.change ? (
          <App data="Hello World" />
        ) : (
          <App data="My name is Abhi" />
        )}
      </div>
    );
  }
}




