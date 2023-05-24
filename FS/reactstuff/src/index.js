import React from 'react';
import ReactDOM from 'react-dom/client';
//import App from './App';
//import './login.css';
import './formA.css';
import {Login, FunCompEx, FormA} from './indexFunctions.js';
import { Employee, Department, Car, Propsexample } from './classComponents';







const element=<Employee Name="Pragim" DeptName="Dev"/>
const carElement = <Car brand="BMW"/>
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
   
   {/*<FunCompEx nm="Abhi" at="delhi"/>*/} 
   {/*<Login/>*/}
   {/*<FormA/>*/}
   {/*element*/}
   {/*carElement*/} 
   {<Propsexample/>}


   
  </React.StrictMode>
);