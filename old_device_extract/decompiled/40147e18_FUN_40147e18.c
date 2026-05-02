// Function : FUN_40147e18
// Address  : 0x40147e18
// Size     : 435 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40147e18(undefined1 param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [6];
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 *puStack_40;
  int iStack_3c;
  undefined1 *puStack_38;
  int iStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  
  uVar4 = (uint)*(ushort *)(param_2 + 0x16);
  if (uVar4 < 0x1c) {
    return 0x104;
  }
  puVar6 = *(undefined1 **)(*(int *)(param_2 + 4) + 4);
  puVar1 = puVar6 + 0x18;
  puStack_40 = puVar1;
  if (((puVar1[uVar4 - 0x1a] != 'L') || (puVar1[uVar4 - 0x19] != '\x18')) ||
     (1 < (ushort)(*(short *)(puVar1 + (uVar4 - 0x18)) - 4U))) {
    pcVar7 = "etected";
    memw();
LAB_40147e91:
    FUN_40147fe4(1,0x20,1,pcVar7);
    return -1;
  }
  iStack_3c = FUN_4015aa8c(param_1);
  iStack_34 = iStack_3c + 2;
  memw();
  puStack_38 = puVar1 + (uVar4 - 0x16);
  iVar2 = (*(code *)&SUB_4008b33c)(puVar1 + (uVar4 - 0x16),iStack_34,6);
  if (iVar2 < 1) {
    pcVar7 = "res=%d)";
    goto LAB_40147e91;
  }
  puStack_30 = (undefined1 *)(*(ushort *)(param_2 + 0x16) + 0x14);
  memw();
  puVar3 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(puStack_30);
  if (puVar3 == (undefined1 *)0x0) {
    return 0x101;
  }
  *puVar3 = *puVar6;
  memw();
  puVar3[1] = puVar6[1] & 199;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(puVar3 + 2,puVar6 + 4,0x12);
  (*(code *)&SUB_4008b3d0)(puVar3 + 0x14,puStack_40,*(ushort *)(param_2 + 0x16) - 0x10);
  (*(code *)&SUB_4008b3d0)(auStack_50,puVar6 + 10,6);
  puVar6 = puStack_30;
  uStack_4a = puVar1[uVar4 - 0x11];
  uVar5 = 0x10;
  puStack_30 = auStack_60;
  memw();
  uStack_49 = puVar1[uVar4 - 0x12];
  memw();
  uStack_48 = puVar1[uVar4 - 0x13];
  memw();
  uStack_47 = puVar1[uVar4 - 0x14];
  memw();
  uStack_46 = puVar1[uVar4 - 0x15];
  memw();
  uStack_45 = puVar1[uVar4 - 0x16];
  if (DAT_3ffc89f6 == '\x0e') {
    uVar5 = 0x20;
  }
  memw();
  uStack_2c = 0x10;
  memw();
  iVar2 = (*_DAT_3ffc8ad4)(iStack_3c + 8,uVar5,auStack_50,0xc,puVar3,puVar6,puStack_30);
  pcVar7 = "res=%d)";
  if (iVar2 == 0) {
    iVar2 = (*(code *)&SUB_4008b33c)(puStack_30,puVar1 + (uVar4 - 0x10),uStack_2c,"res=%d)",0);
    if (iVar2 == 0) {
      (*(code *)&SUB_4008b3d0)(iStack_34,puStack_38,6);
      goto LAB_40147fc0;
    }
    pcVar7 = "s fail\n";
  }
  FUN_40147fe4(1,0x20,1,pcVar7,iVar2);
LAB_40147fc0:
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar3);
  return iVar2;
}

