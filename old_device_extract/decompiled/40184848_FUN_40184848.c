// Function : FUN_40184848
// Address  : 0x40184848
// Size     : 22 bytes


void FUN_40184848(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  for (; param_2 = param_2 + -1, param_1 < param_2; param_1 = param_1 + 1) {
    uVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = uVar1;
  }
  return;
}

