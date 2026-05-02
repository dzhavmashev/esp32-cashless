// Function : FUN_4011f054
// Address  : 0x4011f054
// Size     : 135 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4011f054(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = FUN_4011f034();
  uVar3 = 0;
  while (uVar3 < uVar1 >> 2) {
    memw();
    *(uint *)(uVar3 * 4 + 0x3f800000) = uVar3 ^ 0xaaaaaaaa;
    uVar3 = uVar3 + 8;
    memw();
  }
  iVar6 = -1;
  iVar4 = 0;
  for (uVar3 = 0; uVar3 < uVar1 >> 2; uVar3 = uVar3 + 8) {
    memw();
    iVar5 = iVar4;
    if ((*(uint *)(uVar3 * 4 + 0x3f800000) != (uVar3 ^ 0xaaaaaaaa)) &&
       (iVar5 = iVar4 + 1, iVar4 == 0)) {
      iVar6 = uVar3 * 4;
    }
    iVar4 = iVar5;
  }
  uVar2 = 1;
  if ((iVar4 != 0) && (uVar2 = 0, _DAT_3ffbe0e8 != 0)) {
    uVar2 = (*(code *)&SUB_40094b80)();
    (*(code *)&SUB_40007d54)("alized\n",uVar2,"nternal",iVar4,uVar1 >> 5,iVar6 + 0x3f800000);
    uVar2 = 0;
  }
  return uVar2;
}

