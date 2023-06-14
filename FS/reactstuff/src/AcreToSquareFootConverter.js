import React, { useState } from 'react';
import './Converter.css';

const AcreToSquareFootConverter = () => {
  const [acreValue, setAcreValue] = useState('');
  const [squareFootValue, setSquareFootValue] = useState('');

  const handleAcreChange = (e) => {
    setAcreValue(e.target.value);
  };

  const convertToSquareFoot = () => {
    const acre = parseFloat(acreValue);
    const squareFoot = acre * 43560;
    setSquareFootValue(squareFoot.toFixed(2));
  };

  const clearFields = () => {
    setAcreValue('');
    setSquareFootValue('');
  };

  return (
    <div className="converter-container">
      <h2>Acre to Square Foot Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={acreValue} onChange={handleAcreChange} />
        <span>Acre</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={squareFootValue} readOnly />
        <span>Square Foot</span>
      </div>
      <div className="button-group">
        <button onClick={convertToSquareFoot}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 Acre = 43,560 Square Foot</div>
    </div>
  );
};

export default AcreToSquareFootConverter;
