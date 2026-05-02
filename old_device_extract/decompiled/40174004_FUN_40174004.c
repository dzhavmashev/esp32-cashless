// Function : FUN_40174004
// Address  : 0x40174004
// Size     : 56 bytes


undefined4 FUN_40174004(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    (*(code *)&SUB_4008a890)(param_1);
  }
  uVar1 = FUN_40178024(param_1,*(undefined4 *)(param_1 + 8),param_2);
  return uVar1;
}

