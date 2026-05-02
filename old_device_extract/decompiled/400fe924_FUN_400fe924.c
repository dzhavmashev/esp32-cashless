// Function : FUN_400fe924
// Address  : 0x400fe924
// Size     : 61 bytes


undefined4
FUN_400fe924(char *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_2 != 0xffffffff) {
    if ((param_2 == 1) || (0xf < param_2)) {
      return 0x102;
    }
    if (1 < param_2) {
      if (*param_1 != '/') {
        return 0x102;
      }
      if (param_1[param_2 - 1] == '/') {
        return 0x102;
      }
    }
  }
  uVar1 = FUN_400fe884(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}

