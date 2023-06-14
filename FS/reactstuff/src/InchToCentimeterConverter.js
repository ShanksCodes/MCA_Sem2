import React, { useState } from 'react';
import './Converter.css';

const InchToCentimeterConverter = () => {
  const [inchValue, setInchValue] = useState('');
  const [centimeterValue, setCentimeterValue] = useState('');

  const handleInchChange = (e) => {
    setInchValue(e.target.value);
  };

  const convertToCentimeter = () => {
    const inch = parseFloat(inchValue);
    const centimeter = inch * 2.54;
    setCentimeterValue(centimeter.toFixed(2));
  };

  const clearFields = () => {
    setInchValue('');
    setCentimeterValue('');
  };

  return (
    <div className="converter-container">
      <h2>Inch to Centimeter Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={inchValue} onChange={handleInchChange} />
        <span>Inch</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={centimeterValue} readOnly />
        <span>Centimeter</span>
      </div>
      <div className="button-group">
        <button onClick={convertToCentimeter}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1 Inch = 2.54 Centimeter</div>
    </div>
  );
};

export default InchToCentimeterConverter;
