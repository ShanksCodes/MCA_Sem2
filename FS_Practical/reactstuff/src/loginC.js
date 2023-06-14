import React from 'react';
import './login.css';

export class Login extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      email: '',
      password: '',
      isValid: true
    };
  }

  handleInputChange = (event) => {
    this.setState({
      [event.target.name]: event.target.value,
      isValid: true
    });
  };

  handleSubmit = (event) => {
    event.preventDefault();
    const { email, password } = this.state;
    
    if (email === '' || password === '') {
      this.setState({
        isValid: false
      });
    } else {
   
      alert('Login successful');
    }
  };

  render() {
    const { email, password, isValid } = this.state;
    return (
      <form>
        <h1>Sign in</h1>

        <input
          placeholder="Enter Your Email"
          type="email"
          name="email"
          id="email"
          value={email}
          onChange={this.handleInputChange}
        />
        <input
          placeholder="Enter Your Password"
          type="password"
          name="password"
          id="password"
          value={password}
          onChange={this.handleInputChange}
        />
        <input type="submit" value="Login" onClick={this.handleSubmit} />
        {!isValid && <div className="error-message">Invalid credentials</div>}
        {isValid && <div className="success-message">Success!</div>}
      </form>
    );
  }
}


