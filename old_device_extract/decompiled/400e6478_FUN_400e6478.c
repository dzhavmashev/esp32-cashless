// Function : FUN_400e6478
// Address  : 0x400e6478
// Size     : 255 bytes


void FUN_400e6478(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (-1 < *param_1) {
    FUN_400e62c0(param_1,0,param_1 + 5,param_1 + 2,param_1 + 3);
  }
  if (-1 < param_1[1]) {
    FUN_400e62c0(param_1,1,param_1 + 9,param_1 + 6,param_1 + 7);
  }
  iVar1 = FUN_400f1a90();
  uVar2 = param_1[2];
  if ((uint)param_1[4] < uVar2) {
    if (*(char *)((int)param_1 + 0x26) == '\0') {
      *(undefined1 *)((int)param_1 + 0x26) = 1;
      if (param_1[0x15] != 0) {
        FUN_400e6444(param_1 + 0x13);
      }
      FUN_400f0780(0x3ffc5490,"ialized");
    }
    if ((uint)param_1[10] < (uint)(iVar1 - param_1[3]) / 1000) {
      iVar3 = uVar2 - param_1[4];
      if (iVar3 != 0) {
        if (param_1[0xd] != 0) {
          FUN_400e645c(param_1 + 0xb,iVar3);
        }
        FUN_400f06a4(0x3ffc5490,"STARTED",iVar3);
      }
      param_1[4] = uVar2;
      *(undefined1 *)((int)param_1 + 0x26) = 0;
    }
  }
  uVar2 = param_1[6];
  if ((uint)param_1[8] < uVar2) {
    if (*(char *)((int)param_1 + 0x27) == '\0') {
      *(undefined1 *)((int)param_1 + 0x27) = 1;
      if (param_1[0x19] != 0) {
        FUN_400e6444(param_1 + 0x17);
      }
      FUN_400f0780(0x3ffc5490,"ulses)\n");
    }
    if ((uint)param_1[10] < (uint)(iVar1 - param_1[7]) / 1000) {
      iVar1 = uVar2 - param_1[8];
      if (iVar1 != 0) {
        if (param_1[0x11] != 0) {
          FUN_400e645c(param_1 + 0xf,iVar1);
        }
        FUN_400f06a4(0x3ffc5490,"STARTED",iVar1);
      }
      param_1[8] = uVar2;
      *(undefined1 *)((int)param_1 + 0x27) = 0;
    }
  }
  return;
}

