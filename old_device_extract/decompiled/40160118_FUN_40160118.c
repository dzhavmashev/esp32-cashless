// Function : FUN_40160118
// Address  : 0x40160118
// Size     : 310 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40160118(int *param_1,char param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint *puVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_2 != '\0') {
    memw();
    breakpoint(0x1000,0x4016024e,1,0xf);
    do {
      ill();
    } while( true );
  }
  iVar5 = *param_1;
  iVar4 = *(int *)(*(int *)(iVar5 + 4) + 4);
  if ((**(uint **)(iVar5 + 0x2c) & 0x40000) != 0) {
    iVar4 = iVar4 + 4;
  }
  uVar2 = *(undefined2 *)((int)*(uint **)(iVar5 + 0x2c) + 10);
  iVar3 = FUN_40165d28();
  if (iVar3 != 0) {
    cVar1 = *(char *)(*(int *)(iVar5 + 0x2c) + 0xc);
    if (cVar1 == '\t') {
      uVar8 = 0xe;
    }
    else {
      if (cVar1 != '\n') goto LAB_40160158;
      uVar8 = 0xf;
    }
    *(undefined1 *)(*(int *)(iVar5 + 0x2c) + 0xc) = uVar8;
    memw();
  }
LAB_40160158:
  if ((**(uint **)(iVar5 + 0x2c) & 0x400000) == 0) {
    if (((*(char *)((int)param_1 + 0xd) == '\0') && (*(char *)((int)param_1 + 0xf) == '\0')) &&
       ((byte)((char)(*(uint **)(iVar5 + 0x2c))[3] - 0x10U) < 0x10)) goto LAB_4016017e;
  }
  else {
    memw();
LAB_4016017e:
    *(undefined2 *)(iVar4 + 2) = uVar2;
    memw();
  }
  if (DAT_3ffc000e != '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 0x2c) + 0xc);
    if (DAT_3ffc000d == '\0') {
      if (2 < (byte)(cVar1 - 1U)) goto LAB_401601b5;
      bVar6 = cVar1 + 4;
    }
    else {
      bVar6 = cVar1 - 4;
      if (3 < bVar6) goto LAB_401601b5;
      memw();
    }
    *(byte *)(*(int *)(iVar5 + 0x2c) + 0xc) = bVar6;
    memw();
  }
LAB_401601b5:
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar4 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  puVar7 = *(uint **)(iVar5 + 0x2c);
  if (DAT_3ffc1a44 == '\0') {
    uVar9 = _DAT_3ffbffe8;
    if ((*puVar7 & 0x400000) != 0) {
      uVar9 = _DAT_3ffbffe0;
    }
    uVar11 = 10;
    uVar10 = (puVar7[6] - iVar4) + uVar9 * 0x400;
    if (uVar10 < uVar9 * 0x400) {
      uVar11 = uVar10 >> 10;
    }
  }
  else {
    uVar9 = _DAT_3ffbffe8 - (iVar4 - puVar7[6] >> 10);
    uVar11 = (_DAT_3ffbffe8 < uVar9) * _DAT_3ffbffe8 + (_DAT_3ffbffe8 >= uVar9) * uVar9;
  }
  FUN_401666e8(param_1,uVar11);
  FUN_401666c0(param_1,_DAT_3ffc0034);
  return;
}

