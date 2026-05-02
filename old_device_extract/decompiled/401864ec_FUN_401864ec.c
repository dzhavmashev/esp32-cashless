// Function : FUN_401864ec
// Address  : 0x401864ec
// Size     : 26 bytes


undefined4 FUN_401864ec(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) && (uVar1 = 0, *param_1 != 0)) {
    uVar1 = (**(code **)(*param_1 + 0xc))(param_2);
  }
  return uVar1;
}

