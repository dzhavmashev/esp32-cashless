// Function : FUN_401339d4
// Address  : 0x401339d4
// Size     : 492 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401339d4(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte local_246 [16];
  undefined1 local_236 [32];
  undefined1 auStack_216 [34];
  undefined1 auStack_1f4 [32];
  undefined1 auStack_1d4 [16];
  byte abStack_1c4 [3];
  char cStack_1c1;
  undefined1 uStack_1b4;
  undefined1 uStack_1b3;
  undefined1 uStack_1b2;
  undefined1 uStack_1b1;
  undefined1 uStack_1ad;
  undefined1 auStack_1ac [392];
  int iStack_24;
  
  iVar2 = -0x38;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_3 < 0x181) {
    memw();
    (*(code *)&SUB_4008b530)(abStack_1c4,0,0x1a0);
    FUN_4013ce78(auStack_216);
    uStack_1b4 = 0;
    uStack_1b3 = 0;
    uStack_1b2 = (undefined1)(param_3 >> 8);
    uStack_1ad = 0x30;
    uStack_1b1 = (undefined1)param_3;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_1ac,param_2,param_3);
    auStack_1ac[param_3] = 0x80;
    memw();
    local_236[0] = 0;
    memw();
    memw();
    iVar2 = FUN_4013cea0(auStack_216,local_236,0x100);
    if (iVar2 == 0) {
      iVar1 = 0;
      do {
        memw();
        (*(code *)&SUB_4008b530)(local_246,0,0x10);
        pbVar3 = abStack_1c4;
        iVar4 = param_3 + 0x19;
        do {
          local_246[0] = *pbVar3 ^ local_246[0];
          memw();
          pbVar3 = pbVar3 + 0x10;
          iVar4 = iVar4 - ((uint)(iVar4 == 0) * iVar4 + (uint)(iVar4 != 0));
          memw();
          iVar2 = FUN_4013cf6c(auStack_216,1,local_246);
          if (iVar2 != 0) goto LAB_40133b50;
        } while (iVar4 != 0);
        (*(code *)&SUB_4008b3d0)(auStack_1f4 + iVar1,local_246,0x10);
        iVar1 = iVar1 + 0x10;
        cStack_1c1 = cStack_1c1 + '\x01';
        memw();
      } while (iVar1 != 0x30);
      memw();
      iVar2 = FUN_4013cea0(auStack_216,auStack_1f4,0x100);
      if (iVar2 == 0) {
        iVar1 = param_1;
        do {
          iVar2 = FUN_4013cf6c(auStack_216,1,auStack_1d4,auStack_1d4);
          if (iVar2 != 0) break;
          iVar4 = iVar1 + 0x10;
          (*(code *)&SUB_4008b3d0)(iVar1,auStack_1d4,0x10);
          iVar1 = iVar4;
        } while (param_1 + 0x30 != iVar4);
      }
    }
LAB_40133b50:
    FUN_4013ce8c(auStack_216);
    FUN_4013ae54(abStack_1c4,0x1a0);
    FUN_4013ae54(auStack_1f4,0x30);
    FUN_4013ae54(local_236,0x20);
    FUN_4013ae54(local_246,0x10);
    if (iVar2 != 0) {
      FUN_4013ae54(param_1,0x30);
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar2;
}

