// Function : FUN_40121828
// Address  : 0x40121828
// Size     : 191 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40121828(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint in_SCOMPARE1;
  
  puVar8 = (uint *)(param_1 + 0x3ffbf6ccU & 0xfffffffc);
  uVar5 = param_1 + 0x3ffbf6ccU & 3;
  memw();
  memw();
  uVar3 = 0xff << 0x20 - (uVar5 * -8 + 0x20) ^ 0xffffffff;
  uVar6 = uVar3 & *puVar8;
  do {
    wsr((char)in_SCOMPARE1,uVar6);
    uVar2 = *puVar8;
    if (uVar2 == in_SCOMPARE1) {
      *puVar8 = 1 << 0x20 - (uVar5 * -8 + 0x20) | uVar6;
    }
  } while ((uVar2 != uVar6) && (uVar7 = uVar2 & uVar3, bVar1 = uVar6 != uVar7, uVar6 = uVar7, bVar1)
          );
  if ((uVar2 >> uVar5 * 8 & 0xff) == 0) {
    uVar4 = *(undefined4 *)(&DAT_3f4144b8 + param_1 * 0x24);
    *(undefined4 *)(param_1 * 4 + 0x3ffc6d88) = param_2;
    memw();
    FUN_400f552c(uVar4);
  }
  else {
    memw();
    if (_DAT_3ffbe0e8 != 0) {
      memw();
      uVar4 = (*(code *)&SUB_40094b80)();
      (*(code *)&SUB_40007d54)
                ("channel",uVar4,"CH_AUTO",param_1 + 1,*(undefined4 *)(param_1 * 4 + 0x3ffc6d88));
    }
  }
  return;
}

