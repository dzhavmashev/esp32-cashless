// Function : FUN_40170bfc
// Address  : 0x40170bfc
// Size     : 443 bytes


undefined4 FUN_40170bfc(int *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte bVar11;
  uint uVar12;
  byte *pbVar13;
  int local_40;
  undefined1 auStack_3c [4];
  uint auStack_38 [2];
  uint uStack_30;
  uint uStack_2c;
  
  (*(code *)&SUB_4008b530)(param_2,0,0x18);
  param_1[8] = 0;
  iVar3 = FUN_40171db0(param_1[6] + (-1 - (param_1[0xc] >> 0x1f)),param_1 + 9);
  if (iVar3 == 0) goto LAB_40170d9c;
  iVar6 = (iVar3 + 4) - *(int *)(iVar3 + 4);
  pbVar9 = (byte *)(iVar6 + 9);
  iVar4 = (*(code *)&SUB_4008c01c)(pbVar9);
  pbVar13 = pbVar9 + iVar4 + 1;
  if ((*(char *)(iVar6 + 9) == 'e') && (*(char *)(iVar6 + 10) == 'h')) {
    iVar4 = *(int *)pbVar13;
    pbVar13 = pbVar13 + 4;
    param_2[3] = iVar4;
    pbVar9 = (byte *)(iVar6 + 0xb);
  }
  uVar5 = FUN_40170998(pbVar13,auStack_38);
  pbVar13 = (byte *)FUN_401709c0(uVar5,auStack_3c);
  if (*(char *)(iVar6 + 8) == '\x01') {
    pbVar7 = pbVar13 + 1;
    uVar8 = (uint)*pbVar13;
  }
  else {
    pbVar7 = (byte *)FUN_40170998(pbVar13,auStack_38);
    uVar8 = auStack_38[0];
  }
  param_2[1] = uVar8;
  *(undefined1 *)((int)param_2 + 9) = 0xff;
  pbVar13 = (byte *)0x0;
  if (*pbVar9 == 0x7a) {
    pbVar7 = (byte *)FUN_40170998(pbVar7,auStack_38);
    pbVar13 = pbVar7 + auStack_38[0];
    *(undefined1 *)((int)param_2 + 10) = 1;
    pbVar9 = pbVar9 + 1;
  }
  uVar8 = 0x4c;
  while( true ) {
    pbVar10 = pbVar9 + 1;
    uVar12 = (uint)*pbVar9;
    if (uVar12 == 0) break;
    pbVar9 = pbVar10;
    if (uVar12 == uVar8) {
      *(byte *)((int)param_2 + 9) = *pbVar7;
LAB_40170cd3:
      pbVar7 = pbVar7 + 1;
    }
    else {
      if (uVar12 == 0x52) {
        *(byte *)(param_2 + 2) = *pbVar7;
        goto LAB_40170cd3;
      }
      if (uVar12 == 0x50) {
        uStack_30 = (uint)*pbVar7;
        uStack_2c = uVar8;
        uVar5 = FUN_40170ad0(uStack_30,param_1);
        pbVar7 = (byte *)FUN_401709fc(uStack_30,uVar5,pbVar7 + 1,&local_40);
        *param_2 = local_40;
        uVar8 = uStack_2c;
      }
      else {
        pbVar10 = pbVar13;
        if (uVar12 != 0x53) goto LAB_40170d2a;
        *(undefined1 *)((int)param_2 + 0xb) = 1;
      }
    }
  }
  pbVar10 = pbVar7;
  if (pbVar13 == (byte *)0x0) {
LAB_40170d2a:
    if (pbVar10 == (byte *)0x0) {
      return 3;
    }
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (bVar1 == 0xff) {
LAB_40170d56:
    iVar4 = 0;
  }
  else {
    bVar11 = bVar1 & 7;
    if (bVar11 == 2) {
      iVar4 = 2;
    }
    else if (bVar11 < 3) {
      iVar4 = 4;
      if ((bVar1 & 7) != 0) {
LAB_40170d50:
        (*(code *)&SUB_40094bc8)();
        goto LAB_40170d56;
      }
    }
    else if (bVar11 == 3) {
      iVar4 = 4;
    }
    else {
      iVar4 = 8;
      if (bVar11 != 4) goto LAB_40170d50;
    }
  }
  iVar3 = iVar3 + iVar4 * 2 + 8;
  if (*(char *)((int)param_2 + 10) != '\0') {
    iVar3 = FUN_40170998(iVar3,&local_40);
  }
  cVar2 = *(char *)((int)param_2 + 9);
  if (cVar2 != -1) {
    uVar5 = FUN_40170ad0(cVar2,param_1);
    FUN_401709fc(cVar2,uVar5,iVar3,&local_40);
    param_1[8] = local_40;
  }
LAB_40170d9c:
  if ((uint *)*param_1 == (uint *)0x0) {
    iVar3 = 8;
  }
  else {
    uVar8 = *(uint *)*param_1;
    if (uVar8 == 0) {
      return 5;
    }
    iVar3 = (uVar8 >> 0x1e) << 2;
  }
  param_2[1] = iVar3;
  return 0;
}

