// Function : FUN_40117028
// Address  : 0x40117028
// Size     : 242 bytes


void FUN_40117028(int *param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 in_t0;
  
  uVar7 = (uint)*(ushort *)((int)param_1 + 8);
  uVar7 = (uVar7 < 0x4d0) * uVar7 + (uint)(uVar7 >= 0x4d0) * 0x4d0;
  memw();
  iVar3 = FUN_4010bbc4(0x36,uVar7 + 8 & 0xffff,0x280);
  if (iVar3 != 0) {
    iVar4 = iVar3;
    if (*(ushort *)(iVar3 + 10) < 8) {
      param_2 = 0x67;
      param_3 = in_t0;
      iVar4 = (*(code *)&SUB_40094c54)(" header",0x192,"esponse");
    }
    puVar5 = *(undefined1 **)(iVar4 + 4);
    *puVar5 = param_4;
    puVar5[1] = param_2;
    memw();
    memw();
    uVar6 = FUN_40109eec(param_3);
    uVar9 = 8;
    puVar5[4] = (char)uVar6;
    puVar5[5] = (char)((uint)uVar6 >> 8);
    puVar5[6] = (char)((uint)uVar6 >> 0x10);
    puVar5[7] = (char)((uint)uVar6 >> 0x18);
    memw();
    for (; (param_1 != (int *)0x0 && (uVar7 != 0)); uVar7 = uVar7 - iVar4 & 0xffff) {
      uVar8 = (uint)*(ushort *)((int)param_1 + 10);
      iVar4 = (uVar8 < uVar7) * uVar8 + (uVar8 >= uVar7) * uVar7;
      memw();
      cVar1 = FUN_4010c094(iVar3,param_1[1],iVar4,uVar9);
      if (cVar1 != '\0') break;
      uVar9 = uVar9 + iVar4 & 0xffff;
      param_1 = (int *)*param_1;
    }
    uVar2 = *(undefined2 *)(iVar3 + 8);
    puVar5[2] = 0;
    puVar5[3] = 0;
    memw();
    memw();
    uVar2 = FUN_4011dbec(iVar3,0x3a,uVar2,param_5,param_6);
    puVar5[2] = (char)uVar2;
    puVar5[3] = (char)((ushort)uVar2 >> 8);
    memw();
    memw();
    FUN_40117f9c(iVar3,param_5,param_6,0xff,0,0x3a,param_7);
    FUN_4010bb10(iVar3);
  }
  return;
}

