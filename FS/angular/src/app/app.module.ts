import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';
import { RouterModule, Routes } from '@angular/router';

import { AppComponent } from './app.component';
import { SchoolComponent } from './school/school.component';
import { StudentsComponent } from './students/students.component';
import { SalaryCalculatorComponent } from './salary-calculator/salary-calculator.component';
import { LoginComponent } from './login/login.component';

const routes: Routes = [
  { path: 'login', component: LoginComponent },
  { path: 'school', component: SchoolComponent },
 
];

@NgModule({
  declarations: [
    AppComponent,
    SchoolComponent,
    StudentsComponent,
    SalaryCalculatorComponent,
    LoginComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    RouterModule.forRoot(routes)
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
