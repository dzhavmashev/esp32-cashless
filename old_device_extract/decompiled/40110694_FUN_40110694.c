// Function : FUN_40110694
// Address  : 0x40110694
// Size     : 464 bytes


undefined4 FUN_40110694(int param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  byte bVar12;
  undefined4 uVar13;
  char *pcVar14;
  
  param_2 = param_2 & 0xffff;
  if (param_1 != 0) goto LAB_401106ae;
  pcVar14 = " length";
  uVar13 = 0x34b;
  while( true ) {
    while( true ) {
      while( true ) {
        (*(code *)&SUB_40094c54)("lid pcb",uVar13,"end_fin",pcVar14);
LAB_401106ae:
        piVar8 = *(int **)(param_1 + 0x98);
        if (piVar8 == (int *)0x0) {
          return 0xff;
        }
        if (param_2 != 0) break;
        pcVar14 = "lid pcb";
        uVar13 = 0x353;
      }
      uVar9 = (uint)*(ushort *)(piVar8 + 2);
      if (uVar9 <= param_2) {
        return 0;
      }
      if (param_2 <= *(ushort *)(param_1 + 0x5e)) break;
      pcVar14 = "ength 0";
      uVar13 = 0x35b;
    }
    if (uVar9 != 0) break;
    pcVar14 = " <= mss";
    uVar13 = 0x35c;
  }
  bVar1 = *(byte *)((int)piVar8 + 10);
  uVar10 = uVar9 - param_2 & 0xffff;
  iVar11 = (bVar1 & 1) * 4;
  memw();
  iVar5 = FUN_4010bbc4(0x4a,uVar10 + iVar11 & 0xffff,0x280);
  if (iVar5 != 0) {
    uVar6 = FUN_4010bfb8(piVar8[1],*(int *)(iVar5 + 4) + iVar11,uVar10,
                         param_2 + ((uint)*(ushort *)(piVar8[1] + 8) - (uint)*(ushort *)(piVar8 + 2)
                                   ) & 0xffff);
    if (uVar6 == uVar10) {
      bVar3 = FUN_40185288(*(undefined2 *)(piVar8[3] + 0xc));
      if ((bVar3 & 8) == 0) {
        bVar12 = 0x3f;
        uVar10 = 0;
      }
      else {
        bVar12 = 0x37;
        uVar10 = 8;
      }
      bVar3 = bVar3 & bVar12;
      if ((bVar3 & 1) != 0) {
        bVar3 = bVar3 & 0xfe;
        uVar10 = uVar10 | 1;
      }
      memw();
      iVar11 = FUN_40109eec(*(undefined4 *)(piVar8[3] + 4));
      piVar7 = (int *)FUN_4010ffc8(param_1,iVar5,uVar10,param_2 + iVar11,(uint)bVar1);
      if (piVar7 != (int *)0x0) {
        sVar4 = FUN_40185360(piVar8[1]);
        *(short *)(param_1 + 0x92) = *(short *)(param_1 + 0x92) - sVar4;
        memw();
        memw();
        FUN_4010bd2c(piVar8[1],
                     (param_2 - uVar9 & 0xffff) + (uint)*(ushort *)(piVar8[1] + 8) & 0xffff);
        *(short *)(piVar8 + 2) = (short)(param_2 - uVar9) + (short)piVar8[2];
        memw();
        uVar2 = *(ushort *)(piVar8[3] + 0xc);
        memw();
        uVar9 = FUN_40185288(bVar3);
        iVar5 = piVar8[3];
        uVar9 = (uint)uVar2 | uVar9 & 0xffff;
        *(char *)(iVar5 + 0xc) = (char)uVar9;
        *(char *)(iVar5 + 0xd) = (char)(uVar9 >> 8);
        memw();
        memw();
        sVar4 = FUN_40185360(piVar8[1]);
        *(short *)(param_1 + 0x92) = sVar4 + *(short *)(param_1 + 0x92);
        memw();
        memw();
        sVar4 = FUN_40185360(piVar7[1]);
        iVar5 = *piVar8;
        *(short *)(param_1 + 0x92) = sVar4 + *(short *)(param_1 + 0x92);
        memw();
        *piVar7 = iVar5;
        *piVar8 = (int)piVar7;
        if (*piVar7 == 0) {
          *(undefined2 *)(param_1 + 0x94) = 0;
          memw();
          memw();
        }
        return 0;
      }
    }
    FUN_4010bb10(iVar5);
  }
  return 0xff;
}

