Customer.java
public abstract class Customer {
   private String firstName;
   private String lastName;
   private int age;
   private int customerNumber;
   public static int lastCustomerNumber = 9999;
   public Customer(){
       firstName = "";
       lastName = "";
       age = 0;
       customerNumber = lastCustomerNumber;
       lastCustomerNumber ++;
   }
   public Customer(String fname, String lname, int a){
       firstName = fname;
       lastName = lname;
       age = a;
       customerNumber = lastCustomerNumber;
       lastCustomerNumber ++;
   }
   public String getFirstName(){
       return firstName;
   }
   public String getLastName(){
       return lastName;
   }
   public int getAge(){
       return age;
   }
   public int getCustomerNumber(){
       return customerNumber;
   }
   public void setFirstName(String name){
       firstName = name;
   }
   public void setLastName(String name){
       lastName = name;
   }
   public void setAge(int a){
       age = a;
   }
   public boolean equals(Customer c){
       if(c.getCustomerNumber()==customerNumber){
           return true;
       }
       return false;
   }
   public String toString(){
       String str = "First Name : "+ firstName + " Last Name : "+ lastName + " Age : "+ age + " Customer Number : " + customerNumber;
       return str;
       }
   public abstract double getSavingsIntrest();
   public abstract double getCheckIntrest();
   public abstract double getCheckCharge();

   public double getOverDraftCharges(double amt) {
       return 0;
   }

}

Adult.java


public class Adult extends Customer {
   public Adult(){
       super();
   }
   public Adult(String fname, String lname, int a){
       super(fname,lname,a);
   }
  

   public double getSavingsIntrest() {
       return 0.03;
   }

   public double getCheckIntrest() {
       return 0.01;
   }

   public double getCheckCharge() {
       return 0.03;
   }

public double getOverDraftCharge(double amt){
       if(amt<500){
           return 25.0;
       }
       else {
           throw new IllegalArgumentException("OverDraft must be in limit $500");
       }
   }

}

Senior.java


public class Senior extends Customer {
  
   private boolean vip;
  
   public Senior(){
       super();
   }
   public Senior(String fname, String lname, int a){
       super(fname,lname,a);
   }
   public Senior(String fname, String lname, int a, boolean vip){
       super(fname,lname,a);
       this.vip = vip;
   }

   public double getSavingsIntrest() {
       if(vip){
           return 0.1;
       }
       return 0.08;
   }

   public double getCheckIntrest() {
       return 0.04;
   }

   public double getCheckCharge() {
       if(vip){
           return 0.00;
       }
       return 0.01;
   }

public double getOverDraftCharge(double amt){
       if(amt<500){
           if(vip){
               if(amt<=100){
                   return 0.0;
               }
               else{
                   return 5.0;
               }
           }
           else{
               return 10.0;
           }
       }
       else {
           throw new IllegalArgumentException("OverDraft must be in limit $500");
       }
   }

}

Student.java


public class Student extends Customer {
   public Student(){
       super();
   }
   public Student(String fname, String lname, int a){
       super(fname,lname,a);
   }
  

   public double getSavingsIntrest() {
       return 0.07;
   }

   public double getCheckIntrest() {
       return 0.03;
   }

   public double getCheckCharge() {
       return 0.02;
   }

public double getOverDraftCharge(double amt){
           throw new IllegalArgumentException("Student can not do OverDraft.");
   }

}

Transaction.java

import java.util.Date;


public class Transaction {

   private byte type;
   private double amount;
   private Date date;
   private double fees;
   private String discription;
   public String processTransaction(){
       String t = "";
       if(type==0){
           t = "deposited";
       }
       if(type == 1){
           t = "withdraw";
       }
       if(type == 2){
           t = "addedInterest";
       }
       return "Amount " + amount + " is " + t + "on Date :" + date + "with fees : " + fees + discription;
      
   }
   public Transaction(byte t,double amt,Date d,double f,String dis){
       type = t;
       amount = amt;
       date = d;
       fees = f;
       discription = dis;
   }
}

Account.java

import java.util.Date;


public abstract class Account {
  
   protected Customer customer;
   protected double balance;
   private int accountNumber;
   public static int AccountNumber = 0;
   private Transaction[] transactions;
   private int INITSIZE = 25;
   private int count = 0;
  
   public Account(Customer c,double balance){
       customer = c;
       this.balance = balance;
       accountNumber = AccountNumber + 1;
       AccountNumber++;
       transactions = new Transaction[INITSIZE];
   }
   public void reallocate(){
       int size = transactions.length;
       Transaction[] temp = new Transaction[size*2];
       transactions = temp;
   }
   public Customer getCustomer(){
       return customer;
   }
   public double getBalance(){
       return balance;
   }
   public int getAccountNumber(){
       return accountNumber;
   }
   public String toString(){
       return customer.toString()+" Account Number : " + accountNumber + " Balance : " + balance;  
   }
   public void setCustomer(Customer c){
       customer = c;
   }
   public void addTransaction(byte t,double amt,Date d,double f,String dis){
       if(count==transactions.length){
           reallocate();
           addTransaction(t, amt, d, f, dis);
       }
       else{
           transactions[count] = new Transaction(t, amt, d, f, dis);
       }
   }

public abstract void deposit(double amt, String dis);

public abstract void withdraw(double amt, String dis);

}

SavingsAccount.java

import java.util.Date;


public class SavingsAccount extends Account{

   public SavingsAccount(Customer c, double balance) {
       super(c, balance);
   }
  
   public void deposit(double amt,String dis){
       if(amt>0){
           this.balance = balance + amt;
           Date d = new Date();
           this.addTransaction((byte) 0, amt, d,0.0,dis);
       }
   }
   public void withdraw(double amt,String dis){
       if(amt<balance){
           this.balance = balance - amt;
           Date d = new Date();
           this.addTransaction((byte) 1, amt, d,0.0,dis);
       }
   }
   public void overDraft(double amt,String dis){
       if(amt<balance){
           this.balance = balance - amt;
           Date d = new Date();
           double charges = customer.getOverDraftCharges(amt);
           this.addTransaction((byte) 1, amt, d,charges,dis);
       }
   }
   public void addInterest(){
       Date d = new Date();
       double amt = customer.getSavingsIntrest()*balance;
       this.addTransaction((byte) 2, amt, d,0.0,"Interest have been added to the account.");  
   }

}

CheckingAccount.java

import java.util.Date;


public class CheckingAccount extends Account{

   public CheckingAccount(Customer c, double balance) {
       super(c, balance);
   }
  
   public void deposit(double amt,String dis){
       if(amt>0){
           this.balance = balance + amt;
           Date d = new Date();
           this.addTransaction((byte) 0, amt, d,0.0,dis);
       }
   }
   public void withdraw(double amt,String dis){
       if(amt<balance){
           this.balance = balance - amt;
           Date d = new Date();
           double charge = customer.getCheckCharge();
           this.addTransaction((byte) 1, amt, d,charge,dis);
       }
   }
   public void overDraft(double amt,String dis){
       if(amt<balance){
           this.balance = balance - amt;
           Date d = new Date();
           double charges = customer.getOverDraftCharges(amt);
           this.addTransaction((byte) 1, amt, d,charges,dis);
       }
   }
   public void addInterest(){
       Date d = new Date();
       double amt = customer.getCheckIntrest()*balance;
       this.addTransaction((byte) 2, amt, d,0.0,"Interest have been added to the account.");  
   }

}

Bank.java


public class Bank {
   private Account[] accounts;
   private int count;
   public Bank(){
       accounts = new Account[100];
       count = 0;
   }
   public void addAccount(Account ac){
       if(count == accounts.length){
           reallocate();
           addAccount(ac);
       }
       else{
           accounts[count] = ac;
           count++;
       }
   }
   private void reallocate() {
       Account[] temp = new Account[accounts.length*2];
       for(int i=0;i<accounts.length;i++){
           temp[i]=accounts[i];
       }
       accounts = temp;
   }
   public Account getAccount(int i){
       return accounts[i];
   }
   public void makeDeposit(double amt,String dis){
       accounts[count].deposit(amt,dis);
   }
   public void makeWithdraw(double amt,String dis){
       accounts[count].withdraw(amt,dis);
   }
}