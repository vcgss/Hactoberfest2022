#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char stack[100], output[100];
int topstack = -1, topoutput = -1;

void pushstack(char ele){
stack[++topstack] = ele;
}

char popstack(){
return stack[topstack--];
}

char peepstack(){
return stack[topstack];
}
void pushoutput(char ele) {
output[++topoutput] = ele;
}

int getpriority(char ele) {
switch(ele) {
case '^': return 3;
case '*':
case '/': return 2;
case '+':
case '-': return 1;
}
return -1;
}

int poststack[20];
int top = -1;

void push(int ele) {
poststack[++top] = ele;
}

int pop() {
return poststack[top--];
}

int main() {
char infix[30], ele, popele;
printf("Enter the infix expression to convert into postfix : ");
scanf("%s", infix);
int i = 0;
while (infix[i] != '\0') {
ele = infix[i];
if (ele == '(') {
pushstack(ele);
}
else if (ele == ')') {
while (peepstack() != '(') {
popele = popstack();
pushoutput(popele);
}
popstack();
}
else if (ele == '^' || ele == '*' || ele == '/' || ele == '+' || ele == '-') {
if (topstack >= 0) {
while (getpriority(peepstack()) >= getpriority(ele) && topstack!= -1) {
popele = popstack();
pushoutput(popele);
}
}
pushstack(ele);
}
else pushoutput(ele);
i++;
}
if (topstack != -1) {
while (topstack != -1) {
popele = popstack();
pushoutput(popele);
}
}
printf("The Postfix expression of %s is: %s",infix,output);
printf("\n");
char var;
i = 0;
while(i <= strlen(output)-1){
var = output[i];
if (isalpha(var)){
printf("Enter %c: ", var);
scanf("%c", &output[i]);
scanf("%c", &output[i]);
}
i++;
}
i = 0;
int num1, num2, result;
while (i <= strlen(output)-1) {
ele = output[i];

if (isdigit(ele)) {
push(ele - '0');
}

else {
num1 = pop();
num2 = pop();
switch(ele) {
case '^': result = pow(num2, num1); break;
case '+': result = num2 + num1; break;
case '-': result = num2 - num1; break;
case '/': result = num2 / num1; break;
case '*': result = num2 * num1; break;
}
push(result);
}

i++;
}

printf("The Result of the expression,%s is %d\n", output,pop());

return 0;
}
