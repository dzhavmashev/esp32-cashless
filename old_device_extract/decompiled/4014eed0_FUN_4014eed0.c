// Function : FUN_4014eed0
// Address  : 0x4014eed0
// Size     : 339 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014eed0(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined4 uVar6;
  byte local_30 [48];
  
  bVar1 = *(byte *)(param_1 + 8);
  memw();
  if (3 < bVar1) {
    return 0;
  }
  bVar2 = *_DAT_3ffbfc54;
  local_30[0] = bVar1;
  if (bVar1 == bVar2) {
    iVar3 = FUN_40151060(0,local_30);
    if (iVar3 == 0) goto LAB_4014f004;
    *_DAT_3ffbfc54 = local_30[0];
    memw();
    memw();
  }
  else {
    if (1 < DAT_3ffc89d9) {
      if (((bVar2 & 0xfd) == 1) && ((bVar1 & 0xfd) == 0)) {
        memw();
        FUN_4014dd68(1);
      }
      if (((byte)(bVar2 - 2) < 2) && (bVar1 < 2)) {
        FUN_4014dd68(2);
      }
      FUN_40147a54(bVar1);
      bVar5 = bVar1;
      if (bVar1 == 1) {
        if (bVar2 == 2) {
          uVar6 = 0;
LAB_4014efa9:
          FUN_4014ebe0(uVar6);
        }
        else if (bVar2 != 3) {
          uVar4 = 0;
          if (bVar2 != 0) goto LAB_4014efc3;
LAB_4014ef80:
          FUN_4014ebe0(uVar4);
          bVar5 = 3;
        }
LAB_4014efae:
        FUN_4014ed5c(bVar5);
      }
      else {
        if (bVar1 == 0) {
          FUN_4014ebe0(3);
          if (bVar2 != 2) {
            if (bVar2 != 3) {
              if (bVar2 != 1) goto LAB_4014efc3;
              goto LAB_4014efae;
            }
            FUN_4014ed5c(0);
          }
          bVar5 = 1;
          goto LAB_4014efae;
        }
        if (bVar1 == 2) {
          if (bVar2 == 1) {
            FUN_4014ebe0(1);
          }
          else {
            if (bVar2 == 0) {
              uVar4 = 1;
              goto LAB_4014ef80;
            }
            if (bVar2 != 3) goto LAB_4014efc3;
          }
          bVar5 = 0;
          goto LAB_4014efae;
        }
        if (bVar1 == 3) {
          if (bVar2 == 1) {
            uVar4 = 1;
          }
          else {
            if (bVar2 == 0) {
              FUN_4014ebe0(0);
              uVar6 = 1;
              goto LAB_4014efa9;
            }
            if (bVar2 != 2) goto LAB_4014efc3;
            uVar4 = 0;
          }
          FUN_4014ebe0(uVar4);
        }
      }
LAB_4014efc3:
      if (((bVar1 & 0xfd) == 1) && ((bVar2 & 0xfd) == 0)) {
        FUN_4014dda8();
      }
      if (((byte)(bVar1 - 2) < 2) && (bVar2 < 2)) {
        FUN_4014dda8(2);
      }
    }
    *_DAT_3ffbfc54 = local_30[0];
    memw();
  }
  memw();
  iVar3 = FUN_40150e8c(0,local_30[0],DAT_3ffc8a05 == '\0');
  if (iVar3 != 0) {
    return 0;
  }
LAB_4014f004:
  FUN_40150e38();
  return 0;
}

