import { Link } from 'react-router-dom';
import './HomePageLoan.css'

const Home = () => {
  return (
    <div className="form-container">
    <h1 style={{ textAlign: 'center', color: 'rgb(59, 87, 68)' }}>Loan Calculator</h1>
    <ul>
      <li>
        <Link to="/car-loan">Car Loan</Link>
      </li>
      <li>
        <Link to="/home-loan">Home Loan</Link>
      </li>
    </ul>
  </div>
  );
};

export default Home;

/*import React from 'react';
import './HomePageLoan.css'

const Home = () => {
  return (
    <div className="form-container">
      <h1 style={{ textAlign: 'center', color: 'rgb(59, 87, 68)' }}>Loan Calculator</h1>
      <ul>
        <li>Car Loan</li>
        <li>Home Loan</li>
      </ul>
    </div>
  );
};

export default Home;*/
