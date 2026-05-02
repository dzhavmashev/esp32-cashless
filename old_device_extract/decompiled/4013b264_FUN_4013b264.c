// Function : FUN_4013b264
// Address  : 0x4013b264
// Size     : 448 bytes


int FUN_4013b264(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  int iVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  
  iVar1 = param_1 + 8;
  memw();
  iVar2 = FUN_40131ad8(iVar1,0);
  iVar12 = param_1 + 0x2c;
  iVar13 = param_1 + 0x38;
  memw();
  iVar3 = FUN_40131ad8(iVar12,0);
  iVar4 = param_1 + 0x20;
  memw();
  iVar5 = FUN_40131ad8(iVar13,0);
  memw();
  iVar6 = FUN_40131ad8(iVar4,0);
  iVar15 = param_1 + 0x14;
  memw();
  iVar7 = FUN_40131ad8(iVar15,0);
  bVar16 = iVar7 != 0;
  memw();
  iVar7 = FUN_40131ad8(param_1 + 0x44,0);
  memw();
  iVar8 = FUN_40131ad8(param_1 + 0x50,0);
  memw();
  iVar9 = FUN_40131ad8(param_1 + 0x5c,0);
  if (iVar3 == 0 || iVar5 == 0) {
    if ((iVar3 == 0) && (iVar2 != 0)) {
      bVar17 = false;
      bVar18 = false;
      bVar14 = iVar5 == 0 && (iVar6 != 0 && bVar16);
      bVar16 = bVar16 && (iVar5 == 0 && iVar6 == 0);
    }
    else {
      bVar17 = false;
      bVar18 = false;
      bVar14 = bVar17;
      bVar16 = bVar17;
    }
  }
  else {
    bVar17 = iVar6 != 0 && bVar16;
    bVar18 = bVar16 && iVar6 == 0;
    bVar14 = false;
    bVar16 = false;
  }
  bVar11 = bVar14 | bVar18 | bVar17;
  if (bVar11 == 0 && bVar16 == false) {
    return -0x4080;
  }
  if ((iVar2 == 0) && (iVar3 != 0 && iVar5 != 0)) {
    memw();
    iVar2 = FUN_4013d5d8(iVar1,iVar12,iVar13);
    if (iVar2 != 0) goto LAB_4013b368;
    memw();
    uVar10 = FUN_401317d8(iVar1);
    *(undefined4 *)(param_1 + 4) = uVar10;
  }
  if (bVar14 == false) {
    if (bVar18 != false) {
      iVar2 = FUN_4013c708(iVar12,iVar13,iVar15,iVar4);
      goto LAB_4013b3c5;
    }
    if (bVar11 == 0) goto LAB_4013b414;
  }
  else {
    memw();
    iVar2 = FUN_4013c51c(iVar1,iVar15,iVar4,iVar12,iVar13);
LAB_4013b3c5:
    if (iVar2 != 0) goto LAB_4013b368;
  }
  if (((iVar7 != 0 && iVar8 != 0) && (iVar9 != 0 && (iVar7 != 0 && iVar8 != 0))) ||
     (iVar2 = FUN_4013cab0(iVar12,iVar13,iVar4,param_1 + 0x44,param_1 + 0x50,param_1 + 0x5c),
     iVar2 == 0)) {
LAB_4013b414:
    iVar1 = FUN_4013b074(param_1,bVar11);
    return iVar1;
  }
LAB_4013b368:
  return iVar2 + -0x4080;
}

