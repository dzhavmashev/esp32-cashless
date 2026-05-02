// Function : FUN_4018e470
// Address  : 0x4018e470
// Size     : 236 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4018e470(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = _DAT_3ffc65b8;
  piVar2 = (int *)&DAT_3ffc65c0;
  for (iVar6 = 0; iVar6 != iVar1; iVar6 = iVar6 + 1) {
    if ((iVar6 != 0) &&
       (*(uint *)(&DAT_3ffc65c4 + iVar6 * 8) >> 3 <=
        *(uint *)(&DAT_3ffc65c4 + (iVar6 - 1U >> 1) * 8) >> 3)) {
      iVar6 = (*(code *)&SUB_40094c54)("nts/log/log.c",0xdc,"g/log.c","f_alloc");
    }
    if (param_1 == *piVar2) {
      iVar6 = iVar6 * 8;
      uVar4 = *(uint *)(&DAT_3ffc65c4 + iVar6) & 7;
      if (iVar1 == 0x1f) {
        uVar5 = _DAT_3ffc65bc << 3;
        _DAT_3ffc65bc = _DAT_3ffc65bc + 1;
        *(uint *)(&DAT_3ffc65c4 + iVar6) = *(uint *)(&DAT_3ffc65c4 + iVar6) & 7 | uVar5;
        memw();
        FUN_4018e41c();
      }
      goto LAB_4018e500;
    }
    piVar2 = piVar2 + 2;
  }
  puVar3 = (undefined4 *)&DAT_3ffc66b8;
  do {
    puVar3 = (undefined4 *)*puVar3;
    uVar4 = _DAT_3ffbe0e8;
    if (puVar3 == (undefined4 *)0x0) goto LAB_4018e51a;
    iVar6 = (*(code *)&SUB_4008bdec)(param_1,(undefined1 *)((int)puVar3 + 5));
  } while (iVar6 != 0);
  uVar4 = (uint)*(byte *)(puVar3 + 1);
LAB_4018e51a:
  uVar5 = _DAT_3ffc65bc << 3;
  if (iVar1 == 0x1f) {
    _DAT_3ffc65c4 = uVar4 & 7 | uVar5;
    memw();
    _DAT_3ffc65bc = _DAT_3ffc65bc + 1;
    _DAT_3ffc65c0 = param_1;
    FUN_4018e41c(0);
  }
  else {
    _DAT_3ffc65b8 = iVar1 + 1;
    _DAT_3ffc65bc = _DAT_3ffc65bc + 1;
    *(int *)(&DAT_3ffc65c0 + iVar1 * 8) = param_1;
    *(uint *)(&DAT_3ffc65c4 + iVar1 * 8) = uVar4 & 7 | uVar5;
  }
  _DAT_3ffc65b4 = _DAT_3ffc65b4 + 1;
  memw();
LAB_4018e500:
  (*(code *)&SUB_40094b64)();
  return uVar4;
}

