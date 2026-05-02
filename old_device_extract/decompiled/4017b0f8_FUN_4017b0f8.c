// Function : FUN_4017b0f8
// Address  : 0x4017b0f8
// Size     : 46 bytes


undefined4
FUN_4017b0f8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    (*(code *)&SUB_4008a890)(param_1);
  }
  uVar1 = FUN_40178024(param_1,*(undefined4 *)(param_1 + 8),param_2,param_3,param_4,param_5);
  return uVar1;
}

