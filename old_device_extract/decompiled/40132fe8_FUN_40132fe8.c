// Function : FUN_40132fe8
// Address  : 0x40132fe8
// Size     : 117 bytes


undefined4 FUN_40132fe8(int *param_1,uint param_2)

{
  undefined1 *puVar1;
  
  if (*param_1 == 0) {
    return 0xffff9f00;
  }
  if (*(int *)(*param_1 + 4) == 2) {
    if (param_2 == 2) {
      param_1[3] = (int)&LAB_40186268;
      puVar1 = &LAB_40132984;
      memw();
    }
    else if (param_2 < 3) {
      if (param_2 == 0) {
        param_1[3] = 0x40186210;
        puVar1 = &DAT_401329f8;
      }
      else {
        if (param_2 != 1) {
          return 0xffff9f80;
        }
        param_1[3] = 0x40186234;
        puVar1 = &LAB_40132a7c;
        memw();
      }
    }
    else {
      if (param_2 != 3) {
        if (param_2 != 4) {
          return 0xffff9f80;
        }
        param_1[4] = 0x40132960;
        param_1[3] = 0;
        memw();
        return 0;
      }
      param_1[3] = (int)&DAT_4018629c;
      puVar1 = &LAB_40132b10;
      memw();
    }
    param_1[4] = (int)puVar1;
    memw();
    return 0;
  }
  return 0xffff9f00;
}

