import React, { useState } from 'react';
import './Converter.css';

const MileToKilometerConverter = () => {
  const [mileValue, setMileValue] = useState('');
  const [kilometerValue, setKilometerValue] = useState('');

  const handleMileChange = (e) => {
    setMileValue(e.target.value);
  };

  const convertToKilometer = () => {
    const mile = parseFloat(mileValue);
    const kilometer = mile * 1.60934;
    setKilometerValue(kilometer.toFixed(2));
  };

  const clearFields = () => {
    setMileValue('');
    setKilometerValue('');
  };

  return (
    <div className="converter-container">
      <h2>Mile to Kilometer Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={mileValue} onChange={handleMileChange} />
        <span>Mile</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={kilometerValue} readOnly />
        <span>Kilometer</span>
      </div>
      <div className="button-group">
        <button onClick={convertToKilometer}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 Mile = 1.61 Kilometer</div>
    </div>
  );
};

export default MileToKilometerConverter;
