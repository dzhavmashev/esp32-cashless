// Function : FUN_4012a73c
// Address  : 0x4012a73c
// Size     : 76 bytes


undefined4 FUN_4012a73c(int *param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff8f00;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[0x36] == 0) {
      param_1[0x34] = 0x15;
      param_1[0x35] = 2;
      *(undefined1 *)param_1[0x33] = param_2;
      memw();
      *(undefined1 *)(param_1[0x33] + 1) = param_3;
      memw();
      memw();
      uVar1 = FUN_40129e24(param_1,1);
    }
    else {
      uVar1 = FUN_40129bc8(param_1);
    }
  }
  return uVar1;
}

