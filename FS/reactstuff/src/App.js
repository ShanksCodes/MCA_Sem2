import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './Home';
import { Login } from './loginC';
import Converter from './Converter';
import KbtoMb from './KbtoMb';
import FootToInchConverter from './FootToInchConverter';
import FahrenheitToCelsiusConverter from './FahrenheitToCelsiusConverter';
import MileToKilometerConverter from './MileToKilometerConverter';
import AcreToSquareFootConverter from './AcreToSquareFootConverter';
import InchToCentimeterConverter from './InchToCentimeterConverter';
import CentimeterToInchConverter from './CentimeterToInchConverter';
import MeterToFootConverter from './MeterToFootConverter';
//import { SalaryCalculator } from './salaryCompsFunc';



const App = () => {
  return (
    <Router>
      <div className="container">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/converter" element={<Converter />} /> {/* Add the route for converter */}
          <Route path="/login" element={<Login />} /> {/* Add the route for Login */}
          <Route path="/kbtomb" element={<KbtoMb />} /> 
          <Route path="/foottoinch" element={<FootToInchConverter />} /> 
          <Route path="/fahrenheittocelsius" element={<FahrenheitToCelsiusConverter />} /> 
          <Route path="/miletokilometer" element={<MileToKilometerConverter />} /> 
          <Route path="/acretosquarefoot" element={<AcreToSquareFootConverter />} /> 
          <Route path="/inchtocm" element={<InchToCentimeterConverter />} /> 
          <Route path="/cmtoinch" element={<CentimeterToInchConverter />} /> 
          <Route path="/metertofoot" element={<MeterToFootConverter />} /> 

        </Routes>
      </div>
    </Router>
  );
};

export default App;


