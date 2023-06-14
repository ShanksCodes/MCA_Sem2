import React, { useState } from 'react';
import './Converter.css';

const FahrenheitToCelsiusConverter = () => {
  const [fahrenheitValue, setFahrenheitValue] = useState('');
  const [celsiusValue, setCelsiusValue] = useState('');

  const handleFahrenheitChange = (e) => {
    setFahrenheitValue(e.target.value);
  };

  const convertToCelsius = () => {
    const fahrenheit = parseFloat(fahrenheitValue);
    const celsius = ((fahrenheit - 32) * 5) / 9;
    setCelsiusValue(celsius.toFixed(2));
  };

  const clearFields = () => {
    setFahrenheitValue('');
    setCelsiusValue('');
  };

  return (
    <div className="converter-container">
      <h2>Fahrenheit to Celsius Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={fahrenheitValue} onChange={handleFahrenheitChange} />
        <span>Fahrenheit</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={celsiusValue} readOnly />
        <span>Celsius</span>
      </div>
      <div className="button-group">
        <button onClick={convertToCelsius}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 Fahrenheit = -17.22 Celsius</div>
    </div>
  );
};

export default FahrenheitToCelsiusConverter;
