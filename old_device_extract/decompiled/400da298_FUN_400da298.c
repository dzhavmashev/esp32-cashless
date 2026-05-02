// Function : FUN_400da298
// Address  : 0x400da298
// Size     : 36 bytes


undefined4 FUN_400da298(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[4] == 1) {
    uVar1 = FUN_400dbf24(*param_1);
  }
  else {
    uVar1 = 0;
    if (param_1[4] == 2) {
      uVar1 = (*(code *)&LAB_40183e9f_1)(param_1[1]);
    }
  }
  return uVar1;
}

