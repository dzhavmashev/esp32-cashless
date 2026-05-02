// Function : FUN_4010a2c4
// Address  : 0x4010a2c4
// Size     : 439 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010a2c4(uint param_1)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  if (param_1 < 4) goto LAB_4010a2dc;
  pcVar9 = "f array";
  uVar8 = 0x463;
  while( true ) {
    (*(code *)&SUB_40094c54)("esponse",uVar8,"l_found",pcVar9);
LAB_4010a2dc:
    iVar6 = param_1 * 0x128;
    cVar3 = (&DAT_3ffc5d6e)[iVar6];
    if (cVar3 == '\x01') goto LAB_4010a311;
    if (cVar3 == '\0') {
      return;
    }
    if (cVar3 == '\x02') {
      cVar3 = *(char *)(iVar6 + 0x3ffc5d70) + -1;
      *(char *)(iVar6 + 0x3ffc5d70) = cVar3;
      memw();
      if (cVar3 != '\0') {
        return;
      }
      cVar3 = *(char *)(iVar6 + 0x3ffc5d71) + '\x01';
      *(char *)(iVar6 + 0x3ffc5d71) = cVar3;
      memw();
      if (cVar3 == '\x04') {
        goto LAB_4010a3d4;
      }
      *(char *)(iVar6 + 0x3ffc5d70) = cVar3;
      memw();
      memw();
      goto LAB_4010a389;
    }
    if (cVar3 == '\x03') break;
    pcVar9 = " bounds";
    uVar8 = 0x4ac;
  }
  iVar4 = *(int *)(iVar6 + 0x3ffc5d50);
  if ((iVar4 != 0) && (iVar4 = iVar4 + -1, *(int *)(iVar6 + 0x3ffc5d50) = iVar4, iVar4 != 0)) {
    memw();
    return;
  }
LAB_4010a44a:
  (&DAT_3ffc5d6e)[param_1 * 0x128] = 0;
  memw();
  memw();
  return;
LAB_4010a3d4:
  bVar1 = *(byte *)(iVar6 + 0x3ffc5d6f);
  if (1 < bVar1) goto LAB_4010a3fc;
  iVar4 = bVar1 + 1;
  iVar7 = iVar4 * 0x18;
  iVar5 = *(int *)(&DAT_3ffc5cd8 + iVar7);
  if ((&DAT_3ffc5cec)[iVar7] == '\x06') {
    if (((iVar5 != 0) || (*(int *)(&DAT_3ffc5cdc + iVar7) != 0)) ||
       (*(int *)(&DAT_3ffc5ce0 + iVar7) != 0)) goto LAB_4010a3fc;
    iVar5 = *(int *)(&DAT_3ffc5ce4 + iVar7);
  }
  if (iVar5 != 0) goto LAB_4010a3fc;
  *(byte *)(iVar6 + 0x3ffc5d6f) = (byte)iVar4;
  memw();
  memw();
  goto LAB_4010a3d4;
LAB_4010a3fc:
  iVar4 = param_1 * 0x128;
  memw();
  iVar6 = FUN_40109f14(iVar4 + 0x3ffc5d50);
  if ((iVar6 != 0) && (*(char *)(iVar4 + 0x3ffc5e75) == '\0')) {
    *(byte *)(iVar4 + 0x3ffc5d6f) = bVar1 + 1;
    *(undefined2 *)(iVar4 + 0x3ffc5d70) = 1;
    memw();
    memw();
    goto LAB_4010a389;
  }
  FUN_40109f58(param_1,0);
  goto LAB_4010a44a;
  while (_DAT_3ffc5d6c == sVar2) {
LAB_4010a311:
    sVar2 = (*(code *)&SUB_400842fc)();
    if (DAT_3ffc5d6e != '\x02') break;
  }
  iVar6 = param_1 * 0x128;
  *(short *)(&DAT_3ffc5d6c + iVar6) = sVar2;
  *(undefined2 *)(&DAT_3ffc5d6e + iVar6) = 2;
  memw();
  *(undefined2 *)(iVar6 + 0x3ffc5d70) = 1;
  memw();
  while( true ) {
    bVar1 = *(byte *)(iVar6 + 0x3ffc5d6f);
    if (1 < bVar1) break;
    iVar5 = (uint)bVar1 * 0x18;
    iVar4 = *(int *)(&DAT_3ffc5cd8 + iVar5);
    if ((&DAT_3ffc5cec)[iVar5] == '\x06') {
      if (((iVar4 != 0) || (*(int *)(&DAT_3ffc5cdc + iVar5) != 0)) ||
         (*(int *)(&DAT_3ffc5ce0 + iVar5) != 0)) break;
      iVar4 = *(int *)(&DAT_3ffc5ce4 + iVar5);
    }
    if (iVar4 != 0) break;
    *(byte *)(iVar6 + 0x3ffc5d6f) = bVar1 + 1;
    memw();
    memw();
  }
LAB_4010a389:
  memw();
  FUN_4010a0b8(param_1);
  return;
}

