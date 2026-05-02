// Function : FUN_4016e5d8
// Address  : 0x4016e5d8
// Size     : 145 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e5d8(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_40 [4];
  uint uStack_30;
  uint uStack_2c;
  
  if ((_DAT_3ffca4c8 & 0x18) == 0x10) {
    uVar3 = 0xc;
    uVar2 = 0;
    uStack_2c = 0x55;
    if (DAT_3ffc7e91 != '\0') {
      uStack_2c = 0xe;
    }
    do {
      if (DAT_3ffc7e91 == '\0') {
        iVar6 = uVar2 * 0xc;
        uStack_30 = uVar2;
      }
      else {
        iVar6 = 0x3f0;
        uStack_30 = 0x54;
        if (uVar2 < 0xd) {
          iVar6 = uVar3 * 0xc;
          uStack_30 = uVar3;
        }
      }
      iVar4 = param_1 + iVar6;
      puVar5 = local_40;
      do {
        uVar1 = FUN_40186d70(iVar4);
        *puVar5 = uVar1;
        iVar4 = iVar4 + 4;
        puVar5 = puVar5 + 1;
      } while (param_1 + iVar6 + 0xc != iVar4);
      uVar2 = uVar2 + 1;
      FUN_4016e568(uStack_30,local_40);
      uVar3 = uVar3 + 5 & 0xff;
    } while ((uVar2 & 0xff) < uStack_2c);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 8;
  }
  return;
}

