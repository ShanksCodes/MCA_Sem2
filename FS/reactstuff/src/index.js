import React from 'react';
import ReactDOM from 'react-dom/client';
//import App from './App';
import './login.css';
import './formA.css';
import {Login, FunCompEx, FormA} from './indexFunctions.js';




 

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
   {/*<FunCompEx nm="Abhi" at="delhi"/>*/} 
   {/*<Login/>*/}
   {<FormA/>}
  </React.StrictMode>
);