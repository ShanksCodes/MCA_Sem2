import React, { useState } from 'react';
import './Converter.css';

const CentimeterToInchConverter = () => {
  const [centimeterValue, setCentimeterValue] = useState('');
  const [inchValue, setInchValue] = useState('');

  const handleCentimeterChange = (e) => {
    setCentimeterValue(e.target.value);
  };

  const convertToInch = () => {
    const centimeter = parseFloat(centimeterValue);
    const inch = centimeter / 2.54;
    setInchValue(inch.toFixed(2));
  };

  const clearFields = () => {
    setCentimeterValue('');
    setInchValue('');
  };

  return (
    <div className="converter-container">
      <h2>Centimeter to Inch Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={centimeterValue} onChange={handleCentimeterChange} />
        <span>Centimeter</span>
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
      <div className="result-text">Result: 1 Centimeter = 0.39 Inch</div>
    </div>
  );
};

export default CentimeterToInchConverter;
