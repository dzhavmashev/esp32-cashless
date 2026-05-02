// Function : FUN_40151b00
// Address  : 0x40151b00
// Size     : 227 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40151b00(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined1 auStack_30 [6];
  undefined1 auStack_2a [42];
  
  iVar8 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(iVar8 + 4);
  uVar3 = *(ushort *)(param_1 + 0x16);
  (*(code *)&SUB_4008b3d0)(auStack_30,iVar5,0xe);
  uVar6 = uVar3 - 6;
  uVar7 = uVar6 & 0xffff;
  uVar1 = *(undefined1 *)(iVar5 + 0xd);
  uVar2 = *(undefined1 *)(iVar5 + 0xc);
  *(int *)(iVar8 + 4) = iVar5 + 6;
  *(short *)(param_1 + 0x16) = (short)uVar6;
  *(undefined1 *)(iVar5 + 7) = 0xaa;
  *(undefined1 *)(iVar5 + 6) = 0xaa;
  *(undefined1 *)(iVar5 + 8) = 3;
  memw();
  if ((_DAT_3ffc8864 == 0) || ((*(uint *)(param_1 + 0x1c) & 0x10000) == 0)) {
    *(undefined1 *)(iVar5 + 9) = 0;
    *(undefined1 *)(iVar5 + 10) = 0;
    *(undefined1 *)(iVar5 + 0xb) = 0;
  }
  else {
    *(undefined1 *)(iVar5 + 9) = 0x18;
    *(undefined1 *)(iVar5 + 10) = 0xfe;
    *(undefined1 *)(iVar5 + 0xb) = 0x34;
    memw();
    memw();
  }
  *(undefined1 *)(iVar5 + 0xc) = uVar2;
  *(undefined1 *)(iVar5 + 0xd) = uVar1;
  memw();
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  *(int *)(*(int *)(param_1 + 4) + 4) = iVar5 + -0xe;
  *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 0xe;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(iVar5 + -0xe,auStack_30,6);
  (*(code *)&SUB_4008b3d0)(iVar5 + -8,auStack_2a);
  *(char *)(iVar5 + -2) = (char)(uVar7 >> 8);
  memw();
  uVar4 = *(undefined2 *)(param_1 + 0x16);
  *(char *)(iVar5 + -1) = (char)uVar7;
  memw();
  memw();
  uVar4 = (*(code *)&SUB_4000ab7c)(uVar4,4);
  *(undefined2 *)(param_1 + 0x16) = uVar4;
  memw();
  memw();
  return;
}

