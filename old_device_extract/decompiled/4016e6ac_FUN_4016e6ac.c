// Function : FUN_4016e6ac
// Address  : 0x4016e6ac
// Size     : 299 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e6ac(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint local_50;
  uint uStack_4c;
  uint uStack_48;
  byte local_44;
  byte bStack_43;
  byte bStack_42;
  ushort auStack_41 [8];
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  uStack_30 = 0xe;
  if (DAT_3ffc7e91 == '\0') {
    uStack_30 = 0x55;
  }
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x62,1,0,7);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x62,1,2,7,7,0);
  iVar1 = (**(code **)(_DAT_3ffc7e64 + 0x98))(0x68,3,0);
  iVar2 = (**(code **)(_DAT_3ffc7e64 + 0x98))(0x66,4,5);
  uVar5 = 0xc;
  uVar6 = 0;
  uStack_2c = iVar1 << 0x18 | iVar2 << 0x10;
  iVar1 = 0x96c;
  uVar4 = 0x6e;
  do {
    if (DAT_3ffc7e91 == '\0') {
      iVar2 = uVar6 + 0x960;
      uStack_28 = uVar6;
    }
    else {
      iVar2 = 0x9b4;
      uStack_28 = 0x54;
      if (uVar6 < 0xd) {
        iVar2 = iVar1;
        uStack_28 = uVar5;
      }
    }
    uVar6 = uVar6 + 1;
    iVar1 = iVar1 + 5;
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x62,1,1,uVar4);
    FUN_4016e3b4(iVar2,0,&local_44,auStack_41);
    uVar4 = (undefined1)auStack_41[0];
    uVar3 = FUN_4016e670(4);
    iVar2 = FUN_4016e670(7);
    uStack_48 = uVar3 | uStack_2c | iVar2 << 8;
    local_50 = (uint)auStack_41[0];
    uStack_4c = (uint)local_44 << 0x10 | (uint)bStack_43 << 8 | (uint)bStack_42;
    FUN_4016e568(uStack_28,&local_50);
    uVar5 = uVar5 + 5 & 0xff;
  } while ((uVar6 & 0xff) < uStack_30);
  _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x10;
  return;
}

