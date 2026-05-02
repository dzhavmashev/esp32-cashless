// Function : FUN_4012b260
// Address  : 0x4012b260
// Size     : 136 bytes


undefined1 * FUN_4012b260(int *param_1)

{
  undefined1 *puVar1;
  short sVar2;
  
  puVar1 = (undefined1 *)FUN_4012a960(param_1,1);
  if (puVar1 == (undefined1 *)0x0) {
    if (param_1[0x20] == 0x14) {
      param_1[0x12] = param_1[0x15];
      param_1[0xd] = param_1[0x10];
      if (*(char *)(*param_1 + 5) == '\x01') {
        param_1[0x26] = 0;
        param_1[0x28] = 0;
        sVar2 = (short)param_1[0x23] + 1;
        *(short *)(param_1 + 0x23) = sVar2;
        memw();
        param_1[0x27] = 0;
        param_1[0x29] = 0;
        if (sVar2 == 0) {
          memw();
          return (undefined1 *)0xffff9480;
        }
      }
      else {
        (*(code *)&SUB_4008b530)(param_1[0x1a],0,8);
      }
      FUN_40185894(param_1);
      param_1[1] = param_1[1] + 1;
      memw();
    }
    else {
      FUN_4012a73c(param_1,2,10);
      puVar1 = &DAT_ffff8900;
    }
  }
  return puVar1;
}

