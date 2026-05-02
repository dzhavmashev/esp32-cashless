// Function : FUN_40118b78
// Address  : 0x40118b78
// Size     : 240 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_40118b78(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar7 = "_if_src";
  if ((*(byte *)(param_1 + 0x94) & 0x10) != 0) {
    pcVar7 = (char *)(param_1 + 0x4c);
  }
  iVar6 = 0;
  _DAT_3ffc64b4 = 0x2ff;
  _DAT_3ffc64c0 = 0x2000000;
  DAT_3ffc64c4 = *(char *)(param_1 + 0xee) + '\x01';
  memw();
  _DAT_3ffc64b8 = 0;
  _DAT_3ffc64bc = 0;
  if (pcVar7 != "_if_src") {
    uVar4 = *(byte *)(param_1 + 0xea) + 2;
    iVar6 = (uint)((uVar4 & 7) != 0) + ((int)uVar4 >> 3);
  }
  memw();
  iVar3 = FUN_4010bbc4(0x36,iVar6 * 8 + 8,0x280);
  uVar1 = 0xfe;
  if (iVar3 != 0) {
    puVar5 = *(undefined1 **)(iVar3 + 4);
    *puVar5 = 0x85;
    puVar5[1] = 0;
    memw();
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    memw();
    if (pcVar7 != "_if_src") {
      puVar5[8] = 1;
      puVar5[9] = (char)iVar6;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(puVar5 + 10,param_1 + 0xe4,*(undefined1 *)(param_1 + 0xea));
    }
    uVar2 = FUN_4011dbec(iVar3,0x3a,*(undefined2 *)(iVar3 + 10),pcVar7,&DAT_3ffc64b4);
    puVar5[2] = (char)uVar2;
    puVar5[3] = (char)((ushort)uVar2 >> 8);
    memw();
    if (pcVar7 == "_if_src") {
      pcVar7 = (char *)0x0;
    }
    memw();
    uVar1 = FUN_40117f9c(iVar3,pcVar7,&DAT_3ffc64b4,0xff,0,0x3a,param_1);
    FUN_4010bb10(iVar3);
  }
  return uVar1;
}

