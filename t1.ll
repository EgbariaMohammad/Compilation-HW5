declare i32 @printf(i8*, ...)
declare i32 @scanf(i8*, ...)
declare void @exit(i32)
@.int_specifier = constant [4 x i8] c"%d\0A\00"
@.int_specifier_scan = constant [3 x i8] c"%d\00"
@.str_specifier = constant [4 x i8] c"%s\0A\00"
@.zero_div_string = constant [23 x i8] c"Error division by zero\00"
@.STRING_0_str = internal constant[19 x i8] c"Fibonachy numbers:\00"
@.STRING_1_str = internal constant[21 x i8] c"Shouldn't be printed\00"
define void @print(i8*) {
%spec_ptr = getelementptr [4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0
call i32 (i8*, ...) @printf(i8* %spec_ptr, i8* %0)
ret void
}
define void @printi(i32) {
%spec_ptr = getelementptr [4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0
call i32 (i8*, ...) @printf(i8* %spec_ptr, i32 %0)
ret void
}
define i32 @readi(i32) {
%ret_val = alloca i32
%spec_ptr = getelementptr [3 x i8], [3 x i8]* @.int_specifier_scan, i32 0, i32 0
call i32 (i8*, ...) @scanf(i8* %spec_ptr, i32* %ret_val)
%val = load i32, i32* %ret_val
ret i32 %val
}
define i32 @main(){
%size = add i32 50, 0
%stack_ptr = alloca [50 x i32]
%t1 = getelementptr [19 x i8], [19 x i8]* @.STRING_0_str, i32 0, i32 0
call void @print(i8* %t1)
%t2= add i32 20,0 // max to print
%t3 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 3
store i32 %t2, i32* %t3
%t4= add i32 1,0 // whichFibNumber
%t5 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 4
store i32 %t4, i32* %t5 // t5 is whichFibNumber address
br label %label_2
label_2:
%t6 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 4
%t7 = load i32, i32* %t6 // t7 is max to print address
%t8 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 3
%t9 = load i32, i32* %t8 // t9 is whichFibNumber address
%t10 = icmp ult i32 %t7, %t9
br i1 %t10, label %label_8, label %label_9 // while loop condition
label_8:
%t11= add i32 1,0
%t12 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 0
store i32 %t11, i32* %t12
%t13= add i32 0,0
%t14 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 1
store i32 %t13, i32* %t14
%t15= add i32 1,0
%t16 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 2
store i32 %t15, i32* %t16
%t17 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 3
store i32 0, i32* %t17
br label %label_10
label_10:
%t18 = add i1 1,0
br label %label_12
label_12:
%t19 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 0
%t20 = load i32, i32* %t19
%t21 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 4
%t22 = load i32, i32* %t21
%t23 = icmp eq i32 %t20, %t22
br i1 %t23, label %label_18, label %label_19
label_18:
%t24 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 2
%t25 = load i32, i32* %t24
call void @printi(i32 %t25)
br label %label_11
br label %label_19
label_19:
%t26 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 2
%t27 = load i32, i32* %t26
%t28 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 1
%t29 = load i32, i32* %t28
%t30 = add i32 %t27,%t29
%t31 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 3
store i32 %t30, i32* %t31
%t32 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 2
%t33 = load i32, i32* %t32
%t34 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 1
store i32 %t33, i32* %t34
%t35 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 3
%t36 = load i32, i32* %t35
%t37 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 2
store i32 %t36, i32* %t37
%t38 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 0
%t39 = load i32, i32* %t38
%t40= add i32 1,0
%t41 = add i32 %t39,%t40
%t42 = trunc i32 %t41 to i8
%t43 = zext i8 %t42 to i32
%t44 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 0
store i32 %t43, i32* %t44
br label %label_10
%t45 = getelementptr [21 x i8], [21 x i8]* @.STRING_1_str, i32 0, i32 0
call void @print(i8* %t45)
br label %label_10
label_13:
br label %label_11
label_11:
%t46 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 4
%t47 = load i32, i32* %t46
%t48= add i32 1,0
%t49 = add i32 %t47,%t48
%t50 = trunc i32 %t49 to i8
%t51 = zext i8 %t50 to i32
%t52 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 4
store i32 %t51, i32* %t52
br label %label_2
label_9:
br label %label_3
label_3:
ret i32 0
}
