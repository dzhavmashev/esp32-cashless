// Function : FUN_40147cc4
// Address  : 0x40147cc4
// Size     : 321 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40147cc4(undefined1 param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined1 auStack_40 [16];
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int iStack_28;
  undefined1 *puStack_24;
  
  uVar4 = (uint)*(ushort *)(param_2 + 0x16);
  if (uVar4 < 0x14) {
    return 0x104;
  }
  puVar5 = *(undefined1 **)(*(int *)(param_2 + 4) + 4);
  puVar1 = puVar5 + 0x18;
  puStack_30 = puVar1;
  if (((puVar1[uVar4 - 0x12] != 'L') || (puVar1[uVar4 - 0x11] != '\x10')) ||
     (1 < (ushort)(*(short *)(puVar1 + (uVar4 - 0x10)) - 4U))) {
    pcVar6 = "etected";
    memw();
LAB_40147d3f:
    FUN_40147fe4(1,0x20,1,pcVar6);
    return -1;
  }
  memw();
  puStack_24 = puVar5;
  iVar2 = FUN_4015aa8c(param_1);
  iStack_28 = iVar2 + 2;
  memw();
  puStack_2c = puVar1 + (uVar4 - 0xe);
  iVar3 = (*(code *)&SUB_4008b33c)(puVar1 + (uVar4 - 0xe),iStack_28,6);
  if (iVar3 < 1) {
    pcVar6 = "res=%d)";
    goto LAB_40147d3f;
  }
  iVar3 = *(ushort *)(param_2 + 0x16) + 0x14;
  memw();
  puVar5 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(iVar3);
  if (puVar5 == (undefined1 *)0x0) {
    return 0x101;
  }
  *puVar5 = *puStack_24;
  memw();
  puVar5[1] = puStack_24[1] & 199;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(puVar5 + 2,puStack_24 + 4,0x12);
  (*(code *)&SUB_4008b3d0)(puVar5 + 0x14,puStack_30,*(ushort *)(param_2 + 0x16) - 8);
  iVar2 = (*_DAT_3ffc8ac8)(iVar2 + 8,puVar5,iVar3,auStack_40);
  pcVar6 = "res=%d)";
  if (iVar2 == 0) {
    iVar2 = (*(code *)&SUB_4008b33c)(auStack_40,puVar1 + (uVar4 - 8),8,"res=%d)",0);
    if (iVar2 == 0) {
      (*(code *)&SUB_4008b3d0)(iStack_28,puStack_2c,6);
      goto LAB_40147df4;
    }
    pcVar6 = "id MMIE";
  }
  FUN_40147fe4(1,0x20,1,pcVar6,iVar2);
LAB_40147df4:
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar5);
  return iVar2;
}

