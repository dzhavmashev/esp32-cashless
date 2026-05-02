// Function : FUN_40116eac
// Address  : 0x40116eac
// Size     : 378 bytes


undefined4 FUN_40116eac(int param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  code *pcVar12;
  short sVar13;
  uint uVar14;
  uint uStack_38;
  
  uVar7 = *(ushort *)(param_2 + 0xe0) - 0x14;
  if ((int)uVar7 < 0) {
    uVar7 = *(ushort *)(param_2 + 0xe0) - 0xd;
  }
  pbVar11 = *(byte **)(param_1 + 4);
  if (((*pbVar11 & 0xf) == 5) && (0x13 < *(ushort *)(param_1 + 10))) {
    memw();
    uVar3 = FUN_40185290(*(undefined2 *)(pbVar11 + 6));
    uStack_38 = uVar3 & 0x1fff;
    uVar10 = (uVar7 >> 3 & 0x1fff) * 8;
    uVar8 = *(ushort *)(param_1 + 8) - 0x14;
    sVar13 = 0x14;
    while (uVar8 = uVar8 & 0xffff, uVar8 != 0) {
      iVar9 = (uVar10 < uVar8) * uVar10 + (uVar10 >= uVar8) * uVar8;
      memw();
      piVar4 = (int *)FUN_4010bbc4(0x36,iVar9,0x280);
      if (piVar4 == (int *)0x0) {
LAB_40116f78:
        uVar6 = 0xff;
        goto LAB_40116f13;
      }
      if ((*(short *)((int)piVar4 + 10) != (short)piVar4[2]) || (*piVar4 != 0)) {
        (*(code *)&SUB_40094c54)(" piece!",0x334,"_frag.c",&DAT_3f411f0c);
      }
      sVar1 = FUN_4010bfb8(param_1,piVar4[1],iVar9,sVar13);
      sVar13 = sVar13 + sVar1;
      memw();
      iVar5 = FUN_4010ba7c(piVar4,0x14);
      if (iVar5 != 0) {
        FUN_4010bb10(piVar4);
        goto LAB_40116f78;
      }
      (*(code *)&SUB_4008b3d0)(piVar4[1],pbVar11,0x14);
      uVar14 = uStack_38 & 0x1fff;
      iVar5 = piVar4[1];
      if (((int)(*(ushort *)(param_2 + 0xe0) - 0x13) <= (int)uVar8) || ((uVar3 >> 0xd & 1) != 0)) {
        uVar14 = uStack_38 & 0x1fff | 0x2000;
      }
      uVar2 = FUN_40185290(uVar14);
      *(char *)(iVar5 + 6) = (char)uVar2;
      *(char *)(iVar5 + 7) = (char)((ushort)uVar2 >> 8);
      memw();
      memw();
      uVar2 = FUN_40185290(iVar9 + 0x14U & 0xffff);
      *(char *)(iVar5 + 2) = (char)uVar2;
      *(undefined1 *)(iVar5 + 10) = 0;
      *(undefined1 *)(iVar5 + 0xb) = 0;
      *(char *)(iVar5 + 3) = (char)((ushort)uVar2 >> 8);
      memw();
      memw();
      uVar2 = FUN_4011dc60(iVar5,0x14);
      *(char *)(iVar5 + 10) = (char)uVar2;
      memw();
      pcVar12 = *(code **)(param_2 + 0xb8);
      *(char *)(iVar5 + 0xb) = (char)((ushort)uVar2 >> 8);
      memw();
      memw();
      (*pcVar12)(param_2,piVar4,param_3);
      FUN_4010bb10(piVar4);
      uVar8 = uVar8 - iVar9;
      uStack_38 = uStack_38 + (uVar7 >> 3 & 0xffff) & 0xffff;
      memw();
    }
    uVar6 = 0;
  }
  else {
    uVar6 = 0xfa;
  }
LAB_40116f13:
  memw();
  return uVar6;
}

