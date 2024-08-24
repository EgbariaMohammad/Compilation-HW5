declare i32 @printf(i8*, ...)
declare i32 @scanf(i8*, ...)
declare void @exit(i32)
@.int_specifier = constant [4 x i8] c"%d\0A\00"
@.int_specifier_scan = constant [3 x i8] c"%d\00"
@.str_specifier = constant [4 x i8] c"%s\0A\00"
@.zero_div_string = constant [23 x i8] c"Error division by zero\00"
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
%stack_ptr = alloca [100 x i32]
%t1= add i32 3,0
%t2 = getelementptr [100 x i32], [100 x i32]* %stack_ptr, i32 0, i32 7
store i32 %t1, i32* %t2
%t3= add i32 0,0
%t4 = getelementptr [100 x i32], [100 x i32]* %stack_ptr, i32 0, i32 9
store i32 %t3, i32* %t4
%t5 = getelementptr [100 x i32], [100 x i32]* %stack_ptr, i32 0, i32 7
%t6 = load i32, i32* %t5
%t7 = getelementptr [100 x i32], [100 x i32]* %stack_ptr, i32 0, i32 9
%t8 = load i32, i32* %t7
%t9 = icmp eq i32 0, %t8
br i1 %t9, label %DIV_BY_ZERO, label %label_11
DIV_BY_ZERO:
DIV_BY_ZERO:
call void (i8*) @print(i8* getelementptr ([22 x i8], [22 x i8]* @.zero_div_string, i32 0, i32 0))
call void (i32) @exit(i32 0)
label_11:
%t10 = sdiv i32 %t6,%t8
%t11 = getelementptr [100 x i32], [100 x i32]* %stack_ptr, i32 0, i32 11
store i32 %t10, i32* %t11
ret i32 0
}
