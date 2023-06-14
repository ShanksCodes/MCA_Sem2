import React, { useState } from 'react';
import './Converter.css';

const Converter = () => {
  const [meterValue, setMeterValue] = useState('');
  const [yardValue, setYardValue] = useState('');

  const handleMeterChange = (e) => {
    setMeterValue(e.target.value);
  };

  const convertToYard = () => {
    const meters = parseFloat(meterValue);
    const yards = meters * 1.09361;
    setYardValue(yards.toFixed(2));
  };

  const clearFields = () => {
    setMeterValue('');
    setYardValue('');
  };

  return (
    <div className="converter-container">
      <h2>Meter to Yard Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={meterValue} onChange={handleMeterChange} />
        <span>Meter</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={yardValue} readOnly />
        <span>Yard</span>
      </div>
      <div className="button-group">
        <button onClick={convertToYard}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 meter = 1.09 yard</div>
    </div>
  );
};

export default Converter;
