import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { SchoolComponent } from './school/school.component';
import { StudentsComponent } from './students/students.component';

const routes: Routes = [

  {
    path: "school",component: SchoolComponent
  },
  {
    path: "students", component: StudentsComponent
  }

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
