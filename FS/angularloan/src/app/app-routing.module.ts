import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { CarLoanComponent } from './car-loan/car-loan.component';
import { HomeLoanComponent } from './home-loan/home-loan.component';

const routes: Routes = [
  { path: '', redirectTo: '/car-loan', pathMatch: 'full' },
  { path: 'car-loan', component: CarLoanComponent },
  { path: 'home-loan', component: HomeLoanComponent },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
