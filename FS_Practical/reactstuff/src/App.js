import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './Home';
import { Login } from './loginC';
import Converter from './Converter';



const App = () => {
  return (
    <Router>
      <div className="container">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/converter" element={<Converter />} /> {/* Add the route for converter */}
          <Route path="/login" element={<Login />} /> {/* Add the route for Login */}
        </Routes>
      </div>
    </Router>
  );
};

export default App;


