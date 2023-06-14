import React, { useState } from 'react';
import './Converter.css';

const MeterToFootConverter = () => {
  const [meterValue, setMeterValue] = useState('');
  const [footValue, setFootValue] = useState('');

  const handleMeterChange = (e) => {
    setMeterValue(e.target.value);
  };

  const convertToFoot = () => {
    const meter = parseFloat(meterValue);
    const foot = meter * 3.28084;
    setFootValue(foot.toFixed(2));
  };

  const clearFields = () => {
    setMeterValue('');
    setFootValue('');
  };

  return (
    <div className="converter-container">
      <h2>Meter to Foot Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={meterValue} onChange={handleMeterChange} />
        <span>Meter</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={footValue} readOnly />
        <span>Foot</span>
      </div>
      <div className="button-group">
        <button onClick={convertToFoot}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 Meter = 3.28 Foot</div>
    </div>
  );
};

export default MeterToFootConverter;
