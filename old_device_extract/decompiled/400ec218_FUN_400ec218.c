// Function : FUN_400ec218
// Address  : 0x400ec218
// Size     : 37 bytes


undefined4 FUN_400ec218(int *param_1)

{
  undefined4 uVar1;
  
  if (*(byte *)(*param_1 + param_1[2]) < 2) {
    *(byte *)(param_1 + 0x27) = *(byte *)(*param_1 + param_1[2]);
    param_1[4] = 0x400ec238;
    uVar1 = 0;
  }
  else {
    param_1[4] = (int)&LAB_400ec520;
    uVar1 = 2;
  }
  return uVar1;
}

