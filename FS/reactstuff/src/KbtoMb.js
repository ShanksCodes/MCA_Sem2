import React, { useState } from 'react';
import './Converter.css';

const KbtoMb = () => {
  const [kiloValue, setKiloValue] = useState('');
  const [megaValue, setMegaValue] = useState('');

  const handleKiloChange = (e) => {
    setKiloValue(e.target.value);
  };

  const convertToMega = () => {
    const kilos = parseFloat(kiloValue);
    const megas = kilos / 1024;
    setMegaValue(megas.toFixed(2));
  };

  const clearFields = () => {
    setKiloValue('');
    setMegaValue('');
  };

  return (
    <div className="converter-container">
      <h2>Kilobyte to Megabyte Converter</h2>
      <div className="input-group">
        <label>From:</label>
        <input type="number" value={kiloValue} onChange={handleKiloChange} />
        <span>Kilobyte</span>
      </div>
      <div className="input-group">
        <label>To:</label>
        <input type="text" value={megaValue} readOnly />
        <span>Megabyte</span>
      </div>
      <div className="button-group">
        <button onClick={convertToMega}>Convert</button>
        <button onClick={clearFields}>Clear</button>
      </div>
      <div className="result-text">Result: 1024 Kilobyte = 1 Megabyte</div>
    </div>
  );
};

export default KbtoMb;
