// Function : FUN_401845f8
// Address  : 0x401845f8
// Size     : 32 bytes


undefined4 FUN_401845f8(undefined4 param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_3 != 0) && ((param_3 & 3) == 0)) {
    param_3 = param_3 >> 2;
    do {
      if (*param_2 != -1) {
        return 1;
      }
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    uVar1 = 0;
  }
  return uVar1;
}

