import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { SchoolComponent } from './school/school.component';
import { LoginComponent } from './login/login.component';
import { StudentsComponent } from './students/students.component';

const routes: Routes = [
  { path: '', component: StudentsComponent }, // Home screen route
  { path: 'school', component: SchoolComponent },
  { path: 'login', component: LoginComponent },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
