// Function : FUN_400e5650
// Address  : 0x400e5650
// Size     : 642 bytes


undefined4 FUN_400e5650(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  byte bVar9;
  char *pcVar10;
  undefined1 uStack_31;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  char *pcStack_24;
  
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "rotocol version";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  iVar8 = param_1 + 0x5c;
  iVar5 = param_1 + 0x7c;
  FUN_400f0d70(iVar8,uVar2);
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "irmware_url";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(iVar5,uVar2);
  uVar6 = *param_2;
  puVar3 = (uint *)FUN_400d48f8(uVar6,"ock) >= size");
  uVar2 = 0;
  if (puVar3 == (uint *)0x0) goto LAB_400e56c0;
  bVar9 = (byte)puVar3[2] & 0x7f;
  if (bVar9 == 8) {
    if ((puVar3[1] == 0) && (-1 < (int)*puVar3)) {
LAB_400e58a2:
      iVar4 = FUN_400d48f8(uVar6,"ock) >= size");
      uVar2 = 0;
      if (iVar4 != 0) {
        uVar2 = FUN_400d4348();
      }
      goto LAB_400e56c0;
    }
  }
  else if ((bVar9 == 10) && ((uint)(*puVar3 + 0x80000000 < *puVar3) + puVar3[1] == 0))
  goto LAB_400e58a2;
  uVar2 = 0;
LAB_400e56c0:
  *(undefined4 *)(param_1 + 0x9c) = uVar2;
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "culated hash";
  pcVar7 = (char *)(param_1 + 0x8c);
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(pcVar7,uVar2);
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "present";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(param_1 + 0xd4,uVar2);
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "ing: CA certificate";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(param_1 + 0xe4,uVar2);
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "gnature";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(param_1 + 0xa0,uVar2);
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "version";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(param_1 + 0xb0,uVar2);
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "version";
  uStack_31 = 0;
  uVar1 = FUN_400d49c0(auStack_30,&uStack_31);
  *(undefined1 *)(param_1 + 0xc0) = uVar1;
  uStack_28 = param_2[1];
  uStack_2c = *param_2;
  pcStack_24 = "ndatory";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(param_1 + 0xc4,uVar2);
  uStack_2c = *param_2;
  uStack_28 = param_2[1];
  pcStack_24 = "angelog";
  uVar2 = FUN_400e0768(auStack_30,&DAT_3f42161d);
  FUN_400f0d70(param_1 + 0x6c,uVar2);
  FUN_400f06a4(0x3ffc5490,"se_date");
  iVar4 = iVar8;
  if ((*(byte *)(param_1 + 0x6b) & 0x80) == 0) {
    iVar4 = *(int *)(param_1 + 0x5c);
  }
  FUN_400f06a4(0x3ffc5490,"mmand:\n",iVar4);
  iVar4 = iVar5;
  if ((*(byte *)(param_1 + 0x8b) & 0x80) == 0) {
    iVar4 = *(int *)(param_1 + 0x7c);
  }
  FUN_400f06a4(0x3ffc5490,"on: %s\n",iVar4);
  FUN_400f06a4(0x3ffc5490,"RL: %s\n",*(undefined4 *)(param_1 + 0x9c));
  iVar4 = FUN_400da468(pcVar7);
  if (iVar4 == 0) {
    if ((*(byte *)(param_1 + 0x9b) & 0x80) == 0) {
      pcVar7 = *(char **)(param_1 + 0x8c);
    }
  }
  else {
    pcVar7 = "d - %s\n";
  }
  FUN_400f06a4(0x3ffc5490," bytes\n",pcVar7);
  iVar4 = FUN_400da468(param_1 + 0xd4);
  pcVar7 = "d - %s\n";
  if (iVar4 == 0) {
    pcVar7 = "\n";
  }
  FUN_400f06a4(0x3ffc5490,"sh: %s\n",pcVar7);
  iVar4 = FUN_400da468(param_1 + 0xe4);
  pcVar7 = "d - %s\n";
  if (iVar4 == 0) {
    pcVar7 = "\n";
  }
  FUN_400f06a4(0x3ffc5490,"re: %s\n",pcVar7);
  iVar4 = FUN_400da468(iVar8);
  if (((iVar4 != 0) || (iVar4 = FUN_400da468(iVar5), iVar4 != 0)) ||
     (uVar2 = 1, *(int *)(param_1 + 0x9c) == 0)) {
    FUN_400f0780(0x3ffc5490,"te: %s\n");
    iVar8 = FUN_400da468(iVar8);
    pcVar7 = "s";
    if (iVar8 == 0) {
      pcVar7 = " %s";
    }
    iVar5 = FUN_400da468(iVar5);
    pcVar10 = "s";
    if (iVar5 == 0) {
      pcVar10 = " %s";
    }
    FUN_400f06a4(0x3ffc5490," fields",pcVar7,pcVar10,*(undefined4 *)(param_1 + 0x9c));
    uVar2 = 0;
  }
  return uVar2;
}

