// Function : FUN_4016f3ec
// Address  : 0x4016f3ec
// Size     : 212 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016f3ec(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  uint local_30 [3];
  byte abStack_24 [2];
  byte bStack_22;
  
  puVar6 = local_30;
  uVar1 = (param_1 & 0xff) * 3 & 0xff;
  uVar5 = uVar1 + 3;
  do {
    uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    _DAT_3ff4e0c4 = uVar2 & 0xffffff00 | uVar1;
    memw();
    uVar3 = (*(code *)&SUB_40084594)(0x3ff4e0c0);
    uVar1 = uVar1 + 1 & 0xff;
    *puVar6 = uVar3;
    puVar6 = puVar6 + 1;
  } while (uVar1 != (uVar5 & 0xff));
  FUN_4016e1b8(local_30[0] & 0xff,abStack_24);
  uVar1 = (uint)DAT_3ffca674;
  if (0xf < uVar1) {
    DAT_3ffca660 = (undefined1)(local_30[0] >> ((uVar1 & 3) << 3));
    if (0x13 < uVar1) {
      DAT_3ffca660 = (undefined1)(local_30[2] >> (uVar1 << 3 & 0x1f));
      if (uVar1 < 0x18) {
        DAT_3ffca660 = (undefined1)(local_30[1] >> (uVar1 << 3 & 0x1f));
      }
    }
    memw();
  }
  bVar4 = DAT_3ffca669 & 0xf0;
  DAT_3ffca669 = bVar4 | abStack_24[0];
  DAT_3ffca66a = bVar4 | abStack_24[0] & 0xf0 | bStack_22;
  memw();
  FUN_4016edc4(&DAT_3ffca660,0xd,0x3ffca661);
  return;
}

