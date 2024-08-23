declare i32 @printf(i8*, ...)
declare i32 @scanf(i8*, ...)
declare void @exit(i32)
@.int_specifier = constant [4 x i8] c"%d\0A\00"
@.int_specifier_scan = constant [3 x i8] c"%d\00"
@.str_specifier = constant [4 x i8] c"%s\0A\00"
@.zero_div_string = constant [23 x i8] c"Error division by zero\00"
@.STRING_0_str = internal constant[19 x i8] c"Fibonachy numbers:\00"
@.STRING_1_str = internal constant[21 x i8] c"Shouldn't be printed\00"
@.STRING_2_str = internal constant[33 x i8] c"Fibonacci numbers (alternative):\00"
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
%t2= add i32 20,0
%t3 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 5
store i32 %t2, i32* %t3
%t4= add i32 1,0
%t5 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 6
store i32 %t4, i32* %t5
br label %label_2
label_2:
%t6 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 6
%t7 = load i32, i32* %t6
%t8 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 5
%t9 = load i32, i32* %t8
%t10 = icmp ult i32 %t7, %t9
br i1 %t10, label %label_8, label %label_9
label_8:
%t11= add i32 1,0
%t12 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 9
store i32 %t11, i32* %t12
%t13= add i32 0,0
%t14 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 10
store i32 %t13, i32* %t14
%t15= add i32 1,0
%t16 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 11
store i32 %t15, i32* %t16
%t17 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 12
store i32 0, i32* %t17
br label %label_10
label_10:
%t18 = add i1 1,0
br label %label_12
label_12:
%t19 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 9
%t20 = load i32, i32* %t19
%t21 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 6
%t22 = load i32, i32* %t21
%t23 = icmp eq i32 %t20, %t22
br i1 %t23, label %label_18, label %label_19
label_18:
%t24 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 11
%t25 = load i32, i32* %t24
call void @printi(i32 %t25)
br label %label_11
br label %label_19
label_19:
%t26 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 11
%t27 = load i32, i32* %t26
%t28 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 10
%t29 = load i32, i32* %t28
%t30 = add i32 %t27,%t29
%t31 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 12
store i32 %t30, i32* %t31
%t32 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 11
%t33 = load i32, i32* %t32
%t34 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 10
store i32 %t33, i32* %t34
%t35 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 12
%t36 = load i32, i32* %t35
%t37 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 11
store i32 %t36, i32* %t37
%t38 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 9
%t39 = load i32, i32* %t38
%t40= add i32 1,0
%t41 = add i32 %t39,%t40
%t42 = trunc i32 %t41 to i8
%t43 = zext i8 %t42 to i32
%t44 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 9
store i32 %t43, i32* %t44
br label %label_10
%t45 = getelementptr [21 x i8], [21 x i8]* @.STRING_1_str, i32 0, i32 0
call void @print(i8* %t45)
br label %label_10
label_13:
br label %label_11
label_11:
%t46 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 6
%t47 = load i32, i32* %t46
%t48= add i32 1,0
%t49 = add i32 %t47,%t48
%t50 = trunc i32 %t49 to i8
%t51 = zext i8 %t50 to i32
%t52 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 6
store i32 %t51, i32* %t52
br label %label_2
label_9:
br label %label_3
label_3:
br label %label_34
label_34:
%t53= add i32 1,0
%t54= add i32 2,0
%t55 = icmp slt i32 %t53, %t54
br i1 %t55, label %label_36, label %label_37
label_36:
%t56 = getelementptr [33 x i8], [33 x i8]* @.STRING_2_str, i32 0, i32 0
call void @print(i8* %t56)
%t57= add i32 20,0
%t58 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 12
store i32 %t57, i32* %t58
%t59= add i32 1,0
%t60 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
store i32 %t59, i32* %t60
%t61 = add i1 0,0
br label %label_39
label_38:
%t62 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t63 = zext i1 1 to i32
store i32 %t63, i32* %t62
br label %label_40
label_39:
%t65 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t64 = zext i1 0 to i32
store i32 %t64, i32* %t65
br label %label_40
label_40:
%t66 = add i1 0,0
br label %label_42
label_41:
%t67 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 15
%t68 = zext i1 1 to i32
store i32 %t68, i32* %t67
br label %label_43
label_42:
%t70 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 15
%t69 = zext i1 0 to i32
store i32 %t69, i32* %t70
br label %label_43
label_43:
br label %label_44
label_44:
%t71 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t72 = load i32, i32* %t71
%t73 = trunc i32 %t72 to i1
br i1 %t73, label %label_46, label %label_47
label_46:
%t74 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 15
%t75 = load i32, i32* %t74
%t76 = trunc i32 %t75 to i1
br i1 %t76, label %label_48, label %label_49
label_48:
br label %label_50
label_47:
br label %label_51
label_49:
br label %label_51
label_51:
br label %label_52
label_50:
br label %label_53
label_53:
%t77 = add i1 0,0
br label %label_55
label_54:
%t78 = add i1 0,0
br label %label_57
label_57:
br label %label_58
label_56:
br label %label_59
label_58:
br label %label_60
label_55:
br label %label_61
label_59:
br label %label_61
label_60:
%t79= add i32 3,0
%t80 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
%t81 = load i32, i32* %t80
%t82 = icmp slt i32 %t79, %t81
br i1 %t82, label %label_64, label %label_65
label_64:
br label %label_66
label_61:
br label %label_67
label_65:
br label %label_67
label_52:
br label %label_68
label_66:
br label %label_68
label_67:
br label %label_69
label_68:
%t83 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
%t84 = load i32, i32* %t83
%t85 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 12
%t86 = load i32, i32* %t85
%t87 = icmp eq i32 %t84, %t86
br i1 %t87, label %label_74, label %label_75
label_74:
%t88 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t89 = load i32, i32* %t88
%t90 = trunc i32 %t89 to i1
br i1 %t90, label %label_76, label %label_77
label_77:
br label %label_78
label_76:
br label %label_79
label_78:
br label %label_80
label_75:
br label %label_81
label_79:
br label %label_81
label_80:
%t91 = add i1 1,0
br label %label_82
label_82:
%t92 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t93 = zext i1 1 to i32
store i32 %t93, i32* %t92
br label %label_84
label_83:
%t95 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t94 = zext i1 0 to i32
store i32 %t94, i32* %t95
br label %label_84
label_84:
br label %label_44
br label %label_85
label_81:
%t96 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t97 = load i32, i32* %t96
%t98 = trunc i32 %t97 to i1
br i1 %t98, label %label_86, label %label_87
label_86:
%t99 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
%t100 = load i32, i32* %t99
%t101 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 12
%t102 = load i32, i32* %t101
%t103 = icmp eq i32 %t100, %t102
br i1 %t103, label %label_92, label %label_93
label_92:
%t104 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 15
%t105 = zext i1 1 to i32
store i32 %t105, i32* %t104
br label %label_94
label_93:
%t107 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 15
%t106 = zext i1 0 to i32
store i32 %t106, i32* %t107
br label %label_94
label_94:
br label %label_44
br label %label_87
label_87:
br label %label_85
label_85:
%t108= add i32 1,0
%t109 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 18
store i32 %t108, i32* %t109
%t110= add i32 0,0
%t111 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 19
store i32 %t110, i32* %t111
%t112= add i32 1,0
%t113 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 20
store i32 %t112, i32* %t113
%t114 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 21
store i32 0, i32* %t114
br label %label_95
label_95:
%t115 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 18
%t116 = load i32, i32* %t115
%t117 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
%t118 = load i32, i32* %t117
%t119 = icmp slt i32 %t116, %t118
br i1 %t119, label %label_101, label %label_102
label_101:
%t120 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 20
%t121 = load i32, i32* %t120
%t122 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 19
%t123 = load i32, i32* %t122
%t124 = add i32 %t121,%t123
%t125 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 21
store i32 %t124, i32* %t125
%t126 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 20
%t127 = load i32, i32* %t126
%t128 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 19
store i32 %t127, i32* %t128
%t129 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 21
%t130 = load i32, i32* %t129
%t131 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 20
store i32 %t130, i32* %t131
%t132 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 14
%t133 = load i32, i32* %t132
%t134 = trunc i32 %t133 to i1
br i1 %t134, label %label_111, label %label_112
label_111:
br label %label_96
br label %label_113
label_112:
%t135 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 26
store i32 0, i32* %t135
br label %label_113
label_113:
%t136 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 18
%t137 = load i32, i32* %t136
%t138= add i32 1,0
%t139 = add i32 %t137,%t138
%t140 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 18
store i32 %t139, i32* %t140
br label %label_95
label_102:
br label %label_96
label_96:
%t141 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 20
%t142 = load i32, i32* %t141
call void @printi(i32 %t142)
%t143 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
%t144 = load i32, i32* %t143
%t145= add i32 1,0
%t146 = add i32 %t144,%t145
%t147 = getelementptr [50 x i32], [50 x i32]* %stack_ptr, i32 0, i32 13
store i32 %t146, i32* %t147
br label %label_44
label_69:
br label %label_45
label_45:
ret i32 0
br label %label_34
label_37:
br label %label_35
label_35:
ret i32 0
}
