import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './HomePageLoan';
import HomeLoan from './HomeLoan';
import CarLoan from './CarLoan';
import { Login } from './loginF';
import './AppLoan.css';
import { SalaryCalculator } from './salaryCompsFunc';

const App = () => {
  return (
    <Router>
      <div className="container">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/car-loan" element={<CarLoan />} />
          <Route path="/home-loan" element={<HomeLoan />} />
          <Route path="/tax-calculator" element={<SalaryCalculator />} /> {/* Add the route for TaxCalculator */}
          <Route path="/login" element={<Login />} /> {/* Add the route for Login */}
        </Routes>
      </div>
    </Router>
  );
};

export default App;




/*import React from 'react';
import { BrowserRouter as Router, Routes, Route} from 'react-router-dom';
import Home from './HomePageLoan';
import HomeLoan from './HomeLoan';
import CarLoan from './CarLoan';
import './AppLoan.css';

const App = () => {
  return (
    <Router>
      <div className="container">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/car-loan" element={<CarLoan />} />
          <Route path="/home-loan" element={<HomeLoan />} />
        </Routes>
      </div>
    </Router>
  );
};

export default App;*/

/*import React from 'react';
import { BrowserRouter as Router, Routes, Route, Link } from 'react-router-dom';
import Home from './HomePageLoan';
import HomeLoan from './HomeLoan';
import CarLoan from './CarLoan';
import './AppLoan.css';

const App = () => {
  return (
    <Router>
      <div className="form-container">
        <h1 style={{ textAlign: 'center', color: 'rgb(59, 87, 68)' }}>Loan Calculator</h1>
        <ul>
          <li>
            <Link to="/car-loan">Car Loan</Link>
          </li>
          <li>
            <Link to="/home-loan">Home Loan</Link>
          </li>
        </ul>
      </div>
      <div className="container">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/car-loan" element={<CarLoan />} />
          <Route path="/home-loan" element={<HomeLoan />} />
        </Routes>
      </div>
    </Router>
  );
};

export default App;*/

/*import React from 'react';
import { BrowserRouter as Router, Routes, Route, Link, } from 'react-router-dom';
import Home from './HomePageLoan';
import HomeLoan from './HomeLoan';
import CarLoan from './CarLoan';
import './AppLoan.css';


const App = () => {
  return (
    <Router>
      <div className="form-container">
        <h1 style={{ textAlign: 'center', color: 'rgb(59, 87, 68)' }}>Loan Calculator</h1>
        <ul>
          <li>
            <Link to="/car-loan">Car Loan</Link>
          </li>
          <li>
            <Link to="/home-loan">Home Loan</Link>
          </li>
        </ul>
      </div>
      <div className="container">
        <Routes>
          <Route path="/" element={Home} />
          <Route path="/car-loan" element={CarLoan} />
          <Route path="/home-loan" element={HomeLoan} />
        </Routes>
      </div>
    </Router>

  );
};

export default App;*/
