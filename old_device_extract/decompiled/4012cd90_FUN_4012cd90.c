// Function : FUN_4012cd90
// Address  : 0x4012cd90
// Size     : 109 bytes


undefined4 FUN_4012cd90(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff8f00;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (*(char *)(*param_1 + 4) == '\x01') {
      if (param_1[1] == 0x10) {
        param_1[2] = 3;
        if (param_1[0x36] == 0) {
          param_1[0x35] = 4;
          param_1[0x34] = 0x16;
          *(undefined1 *)param_1[0x33] = 0;
          memw();
          memw();
          uVar1 = FUN_4012a534(param_1);
        }
        else {
          memw();
          uVar1 = FUN_40129bc8(param_1);
        }
      }
    }
    else if (param_1[2] == 1) {
      uVar1 = FUN_4012c9dc(param_1);
    }
    else {
      uVar1 = 0xffff8f00;
      if (param_1[1] == 0x10) {
        uVar1 = FUN_4012cd4c(param_1);
      }
    }
  }
  return uVar1;
}

