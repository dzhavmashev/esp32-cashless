// Function : FUN_4012a788
// Address  : 0x4012a788
// Size     : 90 bytes


uint FUN_4012a788(int *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = FUN_4012c96c(param_1);
  if (-1 < (int)uVar1) {
    if ((uVar1 < param_3) && (param_3 = uVar1, *(char *)(*param_1 + 5) == '\x01')) {
      uVar1 = 0xffff8f00;
    }
    else {
      if (param_1[0x36] == 0) {
        param_1[0x35] = param_3;
        param_1[0x34] = 0x17;
        if (param_3 != 0) {
          memw();
          (*(code *)&SUB_4008b3d0)(param_1[0x33],param_2,param_3);
        }
        uVar1 = FUN_40129e24(param_1,1);
      }
      else {
        uVar1 = FUN_40129bc8(param_1);
      }
      if (uVar1 == 0) {
        uVar1 = param_3;
      }
    }
  }
  return uVar1;
}

