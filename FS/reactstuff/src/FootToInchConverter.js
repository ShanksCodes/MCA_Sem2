import React, { useState } from 'react';
import './Converter.css';

const FootToInchConverter = () => {
  const [footValue, setFootValue] = useState('');
  const [inchValue, setInchValue] = useState('');

  const handleFootChange = (e) => {
    setFootValue(e.target.value);
  };

  const convertToInch = () => {
    const feet = parseFloat(footValue);
    const inches = feet * 12;
    setInchValue(inches.toFixed(2));
  };

  const clearFields = () => {
    setFootValue('');
    setInchValue('');
  };

  return (
    <div className="converter-container">
      <h2>Foot to Inch Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={footValue} onChange={handleFootChange} />
        <span>Foot</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={inchValue} readOnly />
        <span>Inch</span>
      </div>
      <div className="button-group">
        <button onClick={convertToInch}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 Foot = 12 Inch</div>
    </div>
  );
};

export default FootToInchConverter;
