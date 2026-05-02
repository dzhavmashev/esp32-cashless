// Function : FUN_401181c4
// Address  : 0x401181c4
// Size     : 390 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401181c4(int param_1,int param_2,undefined4 param_3)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  uint uStack_38;
  
  memw();
  iVar3 = FUN_4011a800(param_3,param_2);
  uVar10 = iVar3 - 0x30U & 0xfff8;
  _DAT_3ffc648c = _DAT_3ffc648c + 1;
  iVar3 = *(int *)(param_1 + 4);
  uVar6 = (uint)*(ushort *)(param_1 + 8);
  if (0x27 < uVar6) goto LAB_4011820c;
  puVar12 = &DAT_3f4120a8;
  uVar11 = 0x30c;
LAB_40118200:
  memw();
  (*(code *)&SUB_40094c54)("P6_HLEN",uVar11,"_frag.c",puVar12);
LAB_4011820c:
  uVar6 = uVar6 - 0x28;
  sVar9 = 0x28;
  uStack_38 = 0;
  do {
    uVar6 = uVar6 & 0xffff;
    if (uVar6 == 0) {
      uVar11 = 0;
      goto LAB_4011821e;
    }
    iVar7 = (uVar6 < uVar10) * uVar6 + (uVar6 >= uVar10) * uVar10;
    uVar8 = iVar7 + 8U & 0xffff;
    memw();
    piVar4 = (int *)FUN_4010bbc4(0x36,uVar8,0x280);
    if (piVar4 == (int *)0x0) {
LAB_40118288:
      uVar11 = 0xff;
LAB_4011821e:
      memw();
      return uVar11;
    }
    if ((*(short *)((int)piVar4 + 10) != (short)piVar4[2]) || (*piVar4 != 0)) break;
    sVar1 = FUN_4010bfb8(param_1,piVar4[1] + 8,iVar7,sVar9);
    sVar9 = sVar9 + sVar1;
    memw();
    iVar5 = FUN_4010ba7c(piVar4,0x28);
    if (iVar5 != 0) {
      FUN_4010bb10(piVar4);
      goto LAB_40118288;
    }
    memw();
    (*(code *)&SUB_4008b3d0)(piVar4[1],iVar3,0x28);
    iVar5 = piVar4[1];
    *(undefined1 *)(iVar5 + 0x28) = *(undefined1 *)(iVar3 + 6);
    memw();
    *(undefined1 *)(iVar5 + 0x29) = 0;
    memw();
    memw();
    uVar2 = FUN_40185290((uint)(uVar10 < uVar6) | uStack_38 & 0xfffffff8);
    *(char *)(iVar5 + 0x2a) = (char)uVar2;
    uVar6 = uVar6 - iVar7;
    *(char *)(iVar5 + 0x2b) = (char)((ushort)uVar2 >> 8);
    memw();
    memw();
    uVar11 = FUN_40109eec(_DAT_3ffc648c);
    *(char *)(iVar5 + 0x2c) = (char)uVar11;
    *(char *)(iVar5 + 0x2d) = (char)((uint)uVar11 >> 8);
    *(char *)(iVar5 + 0x2f) = (char)((uint)uVar11 >> 0x18);
    *(undefined1 *)(iVar5 + 6) = 0x2c;
    memw();
    *(char *)(iVar5 + 0x2e) = (char)((uint)uVar11 >> 0x10);
    memw();
    memw();
    uVar2 = FUN_40185290(uVar8);
    *(char *)(iVar5 + 4) = (char)uVar2;
    *(char *)(iVar5 + 5) = (char)((ushort)uVar2 >> 8);
    memw();
    memw();
    (**(code **)(param_2 + 0xc0))(param_2,piVar4,param_3);
    FUN_4010bb10(piVar4);
    uStack_38 = iVar7 + uStack_38 & 0xffff;
    memw();
  } while( true );
  puVar12 = &DAT_3f411f0c;
  uVar11 = 0x31c;
  goto LAB_40118200;
}

