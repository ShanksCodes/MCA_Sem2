import React from 'react';
import ReactDOM from 'react-dom/client';
//import App from './App';
import './login.css';
import {Login, FunCompEx} from './indexFunctions.js';




 

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <FunCompEx nm="Abhishek" at="Delhi"/>
   <Login/>
  </React.StrictMode>
);