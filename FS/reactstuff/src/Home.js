import React from 'react';
import { Link } from 'react-router-dom';
import './Home.css';

const Home = () => {
  return (
    <div className="form-container">
      <h1 style={{ textAlign: 'center', color: 'rgb(59, 87, 68)' }}>Full Stack Practical</h1>
      <ul>
        <li>
          <Link to="/login">Login</Link>
        </li>
        <li>
          <Link to="/Converter">Meter to Yard Converter</Link>
        </li>
        <li>
          <Link to="/kbtomb">Kilobyte to Megabyte Converter</Link>
        </li>
        <li>
          <Link to="/foottoinch">Foot to Inch Converter</Link>
        </li>
        <li>
          <Link to="/fahrenheittocelsius">Fahrenheit to Celsius Converter</Link>
        </li>
        <li>
          <Link to="/miletokilometer">Miles to Kilometer Converter</Link>
        </li>
        <li>
          <Link to="/acretosquarefoot">Acre to Square Foot Converter</Link>
        </li>
        <li>
          <Link to="/inchtocm">Inch to Centimeter Converter</Link>
        </li>
        <li>
          <Link to="/cmtoinch">Centimeter to Inch Converter</Link>
        </li>
        <li>
          <Link to="/metertofoot">Meter to Foot Converter</Link>
        </li>
      </ul>
    </div>
  );
};

export default Home;
