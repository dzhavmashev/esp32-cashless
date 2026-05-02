// Function : FUN_40186508
// Address  : 0x40186508
// Size     : 24 bytes


undefined4 FUN_40186508(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) && (uVar1 = 0, *param_1 != 0)) {
    uVar1 = (**(code **)(*param_1 + 8))(param_1[1]);
  }
  return uVar1;
}

