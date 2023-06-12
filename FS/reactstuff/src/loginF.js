import React, { useState } from 'react';
import './login.css';

export const Login = () => {
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const handleSubmit = (event) => {
    event.preventDefault();
    // Handle form submission logic here
  };

  return (
    <form onSubmit={handleSubmit}>
      <h1>Abhi.com</h1>
      <input
        placeholder="Enter Your Name"
        type="text"
        value={name}
        onChange={(event) => setName(event.target.value)}
      />
      <input
        placeholder="Enter Your Email"
        type="email"
        value={email}
        onChange={(event) => setEmail(event.target.value)}
      />
      <input
        placeholder="Enter Your Password"
        type="password"
        value={password}
        onChange={(event) => setPassword(event.target.value)}
      />
      <input type="submit" value="Login" />
    </form>
  );
};
